#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <thread>
#include <mutex>

// Mutex to synchronize file access between threads
std::mutex fileMutex;

// Thread-safe function to append data to a file
void appendToFileThreadSafe(const std::string& filename, const std::string& data) {
    // Lock the mutex to ensure only one thread accesses the file at a time
    std::lock_guard<std::mutex> lock(fileMutex);

    // Open the file in append mode
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        // Write data to the file followed by a newline
        file << data << "\n";
        file.close();  // Close the file
        std::cout << "Data appended to " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}

// Thread-safe function to reverse file content and save it to a new file
void reverseFileContentThreadSafe(const std::string& inputFilename, const std::string& outputFilename) {
    // Lock the mutex to ensure exclusive access to the file
    std::lock_guard<std::mutex> lock(fileMutex);

    // Open the input file for reading
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file " << inputFilename << std::endl;
        return;
    }

    // Read the entire content of the input file
    std::string content((std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>());
    inputFile.close();  // Close the input file

    // Reverse the content
    std::reverse(content.begin(), content.end());

    // Open the output file for writing the reversed content
    std::ofstream outputFile(outputFilename);
    if (outputFile.is_open()) {
        // Write the reversed content to the output file
        outputFile << content;
        outputFile.close();  // Close the output file
        std::cout << "Reversed content stored in " << outputFilename << std::endl;
    }
    else {
        std::cerr << "Unable to open file " << outputFilename << std::endl;
    }
}

int main() {
    // Prompt the user for input to append to the file
    std::string userInput;
    std::cout << "Enter text to append to CSC450_CT5_mod5.txt: ";
    std::getline(std::cin, userInput);

    // Define filenames as relative paths
    std::string originalFilename = "CSC450_CT5_mod5.txt";
    std::string reversedFilename = "CSC450-mod5-reverse.txt";

    // Start thread for appending data
    std::thread appendThread(appendToFileThreadSafe, originalFilename, userInput);

    // Ensure append thread completes before starting the reversal
    appendThread.join();

    // Start thread for reversing file content after appending is done
    std::thread reverseThread(reverseFileContentThreadSafe, originalFilename, reversedFilename);

    // Wait for the reverse thread to complete
    reverseThread.join();

    return 0;
}

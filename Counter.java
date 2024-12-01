import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Counter {
    // ReentrantLock to ensure thread-safe access to shared resources
    private static final Lock lock = new ReentrantLock();
    // Condition to signal between threads
    private static final Condition countUpDone = lock.newCondition();
    // Flag to indicate whether the count-up thread has finished
    private static boolean isCountUpDone = false;

    public static void main(String[] args) {
        // Create threads for counting up and counting down
        Thread countUpThread = new Thread(new CountUp());
        Thread countDownThread = new Thread(new CountDown());

        // Start both threads
        countUpThread.start();
        countDownThread.start();

        try {
            // Wait for both threads to complete before exiting
            countUpThread.join();
            countDownThread.join();
        } catch (InterruptedException e) {
            // Handle thread interruption
            Thread.currentThread().interrupt();
            System.out.println("Main thread interrupted: " + e.getMessage());
        }
    }

    // Runnable class for counting up from 1 to 20
    static class CountUp implements Runnable {
        @Override
        public void run() {
            // Use StringBuilder for efficient string accumulation
            StringBuilder output = new StringBuilder();
            for (int i = 1; i <= 20; i++) {
                output.append("Thread 1 (Count Up): ").append(i).append("\n");
            }

            // Lock the critical section to ensure thread-safe output
            lock.lock();
            try {
                // Print the accumulated output all at once
                System.out.print(output);
                // Update the flag to indicate that counting up is complete
                isCountUpDone = true;
                // Signal the condition variable to wake up the count-down thread
                countUpDone.signal();
            } finally {
                // Ensure the lock is released
                lock.unlock();
            }
        }
    }

    // Runnable class for counting down from 20 to 0
    static class CountDown implements Runnable {
        @Override
        public void run() {
            // Lock the critical section to wait for the signal
            lock.lock();
            try {
                // Wait until the count-up thread signals completion
                while (!isCountUpDone) {
                    countUpDone.await();
                }

                // Use StringBuilder for efficient string accumulation
                StringBuilder output = new StringBuilder();
                for (int i = 20; i >= 0; i--) {
                    output.append("Thread 2 (Count Down): ").append(i).append("\n");
                }

                // Print the accumulated output all at once
                System.out.print(output);
            } catch (InterruptedException e) {
                // Handle thread interruption
                Thread.currentThread().interrupt();
                System.out.println("CountDown thread interrupted: " + e.getMessage());
            } finally {
                // Ensure the lock is released
                lock.unlock();
            }
        }
    }
}

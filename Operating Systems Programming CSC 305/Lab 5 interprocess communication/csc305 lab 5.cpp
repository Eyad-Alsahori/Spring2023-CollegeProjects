#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int parentToChild[2], childToParent[2], additionalPipe[2];
    int n;
    int childResult = 0;

    // Create the pipes
    if (pipe(parentToChild) == -1 || pipe(childToParent) == -1 || pipe(additionalPipe) == -1) {
        perror("pipe failed");
        return 1;
    }

    // Fork the process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process

        // Close unused ends of the pipes
        close(parentToChild[1]);  // Close write end of the parent-to-child pipe
        close(childToParent[0]);  // Close read end of the child-to-parent pipe
        close(additionalPipe[0]); // Close read end of the additional pipe

        // Read the message from the parent
        char message[100];
        read(parentToChild[0], message, sizeof(message));
        std::cout << "Child: Received message from parent: " << message << std::endl;

        // Send a message to the parent
        std::string childMessage = "Message from child";
        write(childToParent[1], childMessage.c_str(), childMessage.length() + 1);

        // Read the value of N from the parent
        read(parentToChild[0], &n, sizeof(n));

        // Compute the partial sum
        for (int i = n / 2; i <= n; ++i) {
            childResult += i;
        }

        // Send the partial sum to the parent
        write(additionalPipe[1], &childResult, sizeof(childResult));

        // Close the pipe ends
        close(parentToChild[0]);
        close(childToParent[1]);
        close(additionalPipe[1]);

        return 0;
    }
    else {
        // Parent process

        // Close unused ends of the pipes
        close(parentToChild[0]);  // Close read end of the parent-to-child pipe
        close(childToParent[1]);  // Close write end of the child-to-parent pipe
        close(additionalPipe[1]); // Close write end of the additional pipe

        // Get the value of N from the user
        std::cout << "Enter a number (N): ";
        std::cin >> n;

        // Send a message to the child
        std::string parentMessage = "Message from parent";
        write(parentToChild[1], parentMessage.c_str(), parentMessage.length() + 1);

        // Read the message from the child
        char childMessage[100];
        read(childToParent[0], childMessage, sizeof(childMessage));
        std::cout << "Parent: Received message from child: " << childMessage << std::endl;

        // Send the value of N to the child
        write(parentToChild[1], &n, sizeof(n));

        // Compute the partial sum in the parent
        int parentPartialSum = 0;
        for (int i = 1; i < n / 2; ++i) {
            parentPartialSum += i;
        }

        // Read the partial sum from the child
        int childPartialSum;
        read(additionalPipe[0], &childPartialSum, sizeof(childPartialSum));

        // Compute the total sum
        int totalSum = parentPartialSum + childPartialSum;

        // Print the total sum
        std::cout << "Parent: Total Sum: " << totalSum << std::endl;

        // Close the pipe ends
        close(parentToChild[1]);
        close(childToParent[0]);
        close(additionalPipe[0]);

        return 0;
    }
}
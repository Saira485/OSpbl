#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    int pid = fork();   // Create child process

    if (pid < 0) {
        cout << "Fork failed!" << endl;
    }
    else if (pid == 0) {
        // Child process
        cout << "Child Process ID: " << getpid() << endl;
    }
    else {
        // Parent process
        cout << "Parent Process ID: " << getpid() << endl;
        cout << "Child Process ID (from parent): " << pid << endl;
    }

    return 0;
}

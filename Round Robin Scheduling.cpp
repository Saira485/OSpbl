#include <iostream>
using namespace std;

int main() {
    int n, tq, bt[10], rem_bt[10], wt[10] = {0}, tat[10];

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time = 0;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false;
                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    cout << "WT\tTAT\n";
    for (int i = 0; i < n; i++)
        cout << wt[i] << "\t" << tat[i] << endl;

    return 0;
}

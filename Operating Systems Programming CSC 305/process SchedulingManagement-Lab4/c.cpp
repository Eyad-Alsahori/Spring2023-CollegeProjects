#include<iostream>
#include<algorithm>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int turnaroundTime;
};

void swap(Process& p1, Process& p2) {
    Process temp = p1;
    p1 = p2;
    p2 = temp;
}

void arrivalTime(int num, Process* procs) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (procs[j].arrivalTime > procs[j + 1].arrivalTime) {
                swap(procs[j], procs[j + 1]);
            }
        }
    }
}

void completionTime(int num, Process* procs) {
    procs[0].completionTime = procs[0].arrivalTime + procs[0].burstTime;
    procs[0].turnaroundTime = procs[0].completionTime - procs[0].arrivalTime;
    procs[0].startTime = procs[0].arrivalTime;

    for (int i = 1; i < num; i++) {
        int temp = procs[i - 1].completionTime;
        int lowestBurst = procs[i].burstTime;
        int lowestIndex = i;

        for (int j = i; j < num; j++) {
            if (procs[j].arrivalTime <= temp && procs[j].burstTime < lowestBurst) {
                lowestBurst = procs[j].burstTime;
                lowestIndex = j;
            }
        }

        procs[lowestIndex].completionTime = temp + procs[lowestIndex].burstTime;
        procs[lowestIndex].turnaroundTime = procs[lowestIndex].completionTime - procs[lowestIndex].arrivalTime;
        procs[lowestIndex].startTime = temp;

        swap(procs[lowestIndex], procs[i]);
    }
}

int main() {
    int num;
    double total_tat = 0;

    cout << "Please enter the number of Processes: ";
    cin >> num;

    Process procs[num];
    for (int i = 0; i < num; i++) {
        cout << "Enter Process Id for " << i + 1 << ": ";
        cin >> procs[i].id;
        cout << "Enter Arrival Time for " << i + 1 << ": ";
        cin >> procs[i].arrivalTime;
        cout << "Enter Burst Time for " << i + 1 << ": ";
        cin >> procs[i].burstTime;
    }

    arrivalTime(num, procs);
    completionTime(num, procs);

    cout << "Process ID" << "\tStart Time" << "\tCompletion Time" << "\tTurnaround Time" << endl;
    for (int i = 0; i < num; i++) {
        cout << "\t" << procs[i].id << "\t\t" << procs[i].startTime << "\t\t" << procs[i].completionTime << "\t\t" << procs[i].turnaroundTime << "\n";
        total_tat += procs[i].turnaroundTime;
    }

    double avg_tat = total_tat / num;
    cout << "\nAverage Turnaround Time: " << avg_tat << endl;

    return 0;
}


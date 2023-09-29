#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Process {
    string name;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;

    Process(string n, int at, int bt, int p) {
        name = n;
        arrival_time = at;
        burst_time = bt;
        priority = p;
    }
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

bool comparePriority(Process p1, Process p2) {
    return p1.priority > p2.priority;
}

bool compareBurstTime(Process p1, Process p2) {
    return p1.burst_time < p2.burst_time;
}

vector<Process> getProcesses() {
    vector<Process> processes;
    int num_processes;
    cout << "Enter the number of processes: ";
    cin >> num_processes;
    for (int i = 0; i < num_processes; i++) {
        string name;
        int arrival_time, burst_time, priority;
        cout << "Enter the name of process " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> arrival_time;
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> burst_time;
        cout << "Enter the priority of process " << i + 1 << ": ";
        cin >> priority;
        processes.push_back(Process(name, arrival_time, burst_time, priority));
    }
    return processes;
}

void FCFS(vector<Process> processes) {
    int current_time = 0;
    cout << left << setw(10) << "PID";
    cout << left << setw(25) << "Start";
    cout << left << setw(25) << "Completion time";
    cout << left << setw(25) << "Turn Around time";
    cout << endl;
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].start_time = current_time;
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        cout << left << setw(10) << processes[i].name;
        cout << left << setw(25) << processes[i].start_time;
        cout << left << setw(25) << processes[i].completion_time;
        cout << left << setw(25) << processes[i].turnaround_time;
        cout << endl;
    }
    double avg_turnaround_time = 0;
    for (Process p : processes) {
        avg_turnaround_time += p.turnaround_time;
    }
    avg_turnaround_time /= processes.size();
    cout << "Average Turnaround Time: " << avg_turnaround_time << "\n";
}

int main() {
    vector<Process> processes = getProcesses();
    sort(processes.begin(), processes.end(), compareArrivalTime);
    FCFS(processes);
    cout << "\n";
    return 0;
}



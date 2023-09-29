#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turn_around_time;
    int remaining_time;
};

bool compare_arrival_time(const process& p1, const process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

bool compare_priority(const process& p1, const process& p2) {
    if (p1.priority != p2.priority) {
        return p1.priority > p2.priority;
    }
    else {
        return p1.arrival_time > p2.arrival_time;
    }
}

int main() {
    int n;
    cout << "Please enter the number of Processes: ";
    cin >> n;

    vector<process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Process ID:" << i + 1 << endl;
        cout << "Enter the Arrival time for " << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter the Burst Time for " << i + 1 << ": ";
        cin >> processes[i].burst_time;
        cout << "Enter the Priority for " << i + 1 << ": ";
        cin >> processes[i].priority;
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), compare_arrival_time);

    int current_time = 0;
    vector<process> completed_processes;

    priority_queue<process, vector<process>, decltype(&compare_priority)> pq(&compare_priority);

    int i = 0;
    while (completed_processes.size() < n) {
        while (i < n && processes[i].arrival_time <= current_time) {
            pq.push(processes[i]);
            i++;
        }

        if (pq.empty()) {
            current_time = processes[i].arrival_time;
            continue;
        }

        process current_process = pq.top();
        pq.pop();

        if (current_process.remaining_time == current_process.burst_time) {
            current_process.start_time = current_time;
        }

        current_process.remaining_time--;
        current_time++;

        if (current_process.remaining_time == 0) {
            current_process.completion_time = current_time;
            current_process.turn_around_time = current_process.completion_time - current_process.arrival_time;
            completed_processes.push_back(current_process);
        }
        else {
            pq.push(current_process);
        }
    }

    double total_turn_around_time = 0;
    cout << "\nPID\tStart time\tCompletion time\tTurn Around time\n";
    for (auto& p : completed_processes) {
        total_turn_around_time += p.turn_around_time;
        printf("%d\t%d\t\t%d\t\t%d\n", p.pid, p.start_time, p.completion_time, p.turn_around_time);
    }
    printf("\tAvgerage TaT:\t%.2lf\n", total_turn_around_time / n);

    return 0;
}

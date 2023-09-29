#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    int size;
    Process(int id, int size) : id(id), size(size) {}
};

class Partition {
public:
    int id;
    int size;
    int allocated_process_id;
    Partition(int id, int size) : id(id), size(size), allocated_process_id(-1) {}
};

class NextFit {
public:
    vector<Process> processes;
    vector<Partition> partitions;
    vector<int> allocation;
    vector<int> waste;
    int total_waste;

    NextFit() : total_waste(0) {}

    void run() {
        int current_partition = 0;
        for (int i = 0; i < processes.size(); i++) {
            int count = 0;
            while (count < partitions.size()) {
                count++;
                if (processes[i].size <= partitions[current_partition].size &&
                    partitions[current_partition].allocated_process_id == -1) {
                    allocation[i] = partitions[current_partition].id;
                    partitions[current_partition].size -= processes[i].size;
                    waste[i] = partitions[current_partition].size;
                    partitions[current_partition].allocated_process_id = processes[i].id;
                    current_partition = (current_partition + 1) % partitions.size();
                    break;
                }
                current_partition = (current_partition + 1) % partitions.size();
            }
        }

        cout << "Job\tPartition ID\tStatus\tWaste amount\n";
        for (int i = 0; i < processes.size(); i++) {
            cout << i + 1 << "\t\t";
            if (allocation[i] != -1)
                cout << allocation[i] << "\t\tRun\t";
            else
                cout << "-\t\tWait\t";
            if (waste[i] != -1) {
                total_waste += waste[i];
                cout << waste[i];
            }
            else
                cout << "-";
            cout << endl;
        }
        cout << "Total Waste: " << total_waste << endl;
    }
};

int main() {
    int num_processes, num_partitions;
    cout << " number of chosen processes: ";
    cin >> num_processes;

    NextFit nf;
    nf.allocation.resize(num_processes, -1);
    nf.waste.resize(num_processes, -1);

    for (int i = 0; i < num_processes; i++) {
        int process_size;
        cout << "size of process " << i + 1 << ": ";
        cin >> process_size;
        nf.processes.push_back(Process(i + 1, process_size));
    }

    cout << "number of partitions: ";
    cin >> num_partitions;

    for (int i = 0; i < num_partitions; i++) {
        int partition_size;
        cout << "size of partition " << i + 1 << ": ";
        cin >> partition_size;
        nf.partitions.push_back(Partition(i + 1, partition_size));
    }

    nf.run();

    return 0;
}

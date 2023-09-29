#include <iostream>
#include <cstring>
using namespace std;

class Partition {
public:
    int size;
    int index;

    Partition() {
        size = 0;
        index = -1;
    }

    Partition(int s, int i) {
        size = s;
        index = i;
    }
};

class Process {
public:
    int size;
    int partition_index;
    int waste;

    Process() {
        size = 0;
        partition_index = -1;
        waste = -1;
    }

    Process(int s) {
        size = s;
        partition_index = -1;
        waste = -1;
    }
};

class MemoryManager {
private:
    int num_processes;
    int num_partitions;
    Partition* partitions;
    Process* processes;

public:
    MemoryManager(int np, int nb) {
        num_processes = np;
        num_partitions = nb;
        partitions = new Partition[nb];
        processes = new Process[np];
    }

    void getPartitionSizes() {
        for (int i = 0; i < num_partitions; i++) {
            cout << "Size of partition " << i + 1 << ": ";
            cin >> partitions[i].size;
            partitions[i].index = i;
        }
    }

    void getProcessSizes() {
        for (int i = 0; i < num_processes; i++) {
            cout << "Size of process " << i + 1 << ": ";
            cin >> processes[i].size;
        }
    }

    void allocateMemory() {
        for (int i = 0; i < num_processes; i++) {
            for (int j = 0; j < num_partitions; j++) {
                if (processes[i].size <= partitions[j].size) {
                    processes[i].partition_index = j;
                    processes[i].waste = partitions[j].size - processes[i].size;
                    partitions[j].size -= processes[i].size;
                    break;
                }
            }
        }
    }

    void printAllocationStatus() {
        cout << "\nJobs\tPartitions\tStatus\tWaste num\n";
        int total_waste = 0;
        for (int i = 0; i < num_processes; i++) {
            cout << i + 1 << "\t\t";
            if (processes[i].partition_index >= 0) {
                cout << processes[i].partition_index + 1 << "\t\tRun\t";
            }
            else {
                cout << "-\t\tWait\t";
            }
            if (processes[i].waste >= 0) {
                total_waste += processes[i].waste;
                cout << processes[i].waste;
            }
            else {
                cout << "-";
            }
            cout << endl;
        }
        cout << "\nTotal Waste: " << total_waste << endl;
    }
};

int main() {
    int np, nb;
    cout << "Number of chosen processes: ";
    cin >> np;
    cout << "Number of chosen partitions: ";
    cin >> nb;

    MemoryManager mm(np, nb);
    mm.getPartitionSizes();
    mm.getProcessSizes();
    mm.allocateMemory();
    mm.printAllocationStatus();

    return 0;
}
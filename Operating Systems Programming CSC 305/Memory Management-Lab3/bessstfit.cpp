#include<iostream>
#include<cstring>
using namespace std;

class Process {
public:
    int size;
    int allocation = -1;
    int waste = -1;
};

class Partition {
public:
    int size;
    bool allocated = false;
};

int main() {
    int np, nb, total_waste = 0;

    cout << "number of processes: ";
    cin >> np;
    Process p[np];

    for (int i = 0; i < np; i++) {
        cout << "size of process " << i + 1 << ": ";
        cin >> p[i].size;
    }

    cout << "\nnumber of partitions: ";
    cin >> nb;
    Partition b[nb];

    for (int i = 0; i < nb; i++) {
        cout << "size of partition " << i + 1 << ": ";
        cin >> b[i].size;
    }

    for (int i = 0; i < np; i++) {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++) {
            if (b[j].allocated == false && p[i].size <= b[j].size) {
                if (bestIdx == -1 || b[bestIdx].size > b[j].size) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            p[i].allocation = bestIdx;
            b[bestIdx].allocated = true;
            b[bestIdx].size -= p[i].size;
            p[i].waste = b[bestIdx].size;
            total_waste += p[i].waste;
        }
    }

    cout << "\nJob\tPartition ID\tStatus\tWaste amount\n";
    for (int i = 0; i < np; i++) {
        cout << i + 1 << "\t\t";
        if (p[i].allocation != -1) {
            cout << p[i].allocation + 1 << "\t\tRun\t";
            cout << p[i].waste;
        }
        else {
            cout << "-\t\tWait\t-";
        }
        cout << endl;
    }

    cout << "\nTotal Waste: " << total_waste << endl;

    return 0;
}


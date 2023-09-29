#include <iostream>
using namespace std;

struct Process {
    int size;
};

struct Partition {
    int size;
};
//delcaring vairbles
int main() {
    Process* p; 
    int np; 
    Partition* b; 
    int nb; 
    int ch; 
    int* w; 
    int total = 0;

    cout << "number of processes: ";
    cin >> np;

    p = new Process[np]; 

    for (int i = 0; i < np; i++) {
        cout << "size of process " << i + 1 << ": ";
        cin >> p[i].size;
    }

    cout << "\nnumber of partitions: ";
    cin >> nb;

    b = new Partition[nb]; 

    for (int i = 0; i < nb; i++) {
        cout << "size of partition " << i + 1 << ": ";
        cin >> b[i].size;
    }

    int* alloc = new int[np];
    w = new int[np]; 

    memset(alloc, -1, sizeof(alloc));

    cout << "\nWorst Fit Algorithm\n";
    cout << "\nJobs\tPartition ID\tStatus\tWaste amount\n";

    for (int i = 0; i < np; i++) {
        int worstIndex = -1;

        for (int j = 0; j < nb; j++) {
            if (p[i].size <= b[j].size) {
                if (worstIndex == -1 || b[worstIndex].size < b[j].size)
                    worstIndex = j;
            }
        }

        if (worstIndex != -1) {
            alloc[i] = worstIndex;
            b[worstIndex].size -= p[i].size;
            w[i] = b[worstIndex].size;
        }

        cout << i + 1 << "\t\t";
        if (alloc[i] >= -1)
            cout << alloc[i] + 1 << "\t\tRun\t";
        else
            cout << "-\t\tWait\t";

        if (w[i] >= -1) {
            total += w[i];
            cout << w[i];
        }
        else {
            cout << "-";
        }

        cout << endl;
    }

    cout << "\nTotal Waste: " << total << endl;

    delete[] p; 
    delete[] b; 
    delete[] alloc;
    delete[] w; 

    return 0;
}


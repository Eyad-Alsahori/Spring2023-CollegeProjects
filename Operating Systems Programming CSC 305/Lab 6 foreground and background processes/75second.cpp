#include<iostream>
using namespace std;

int main() {
    int sum = 0;
    int n = 80000000;
    for (int i = 1; i <= 75; i++) {
        for (int j = 1; j <= n; j++) {
            sum += j * 0.75;
        }
    }
    return 0;
}
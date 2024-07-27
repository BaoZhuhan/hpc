#include <bits/stdc++.h>
using namespace std;

int main() {
    string a1[2] = { "OpenMP-task-nest" , "OpenMP-task-normal" };
    string a2[3] = { "sgemm-normal","sgemm-neon-simd","sgemm-V(4*4)" };
    string a3 = 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << '[' << a1[i] << ']' << "-with-" << '[' << a2[j] << ']' << endl;
        }
    }

    return 0;
}
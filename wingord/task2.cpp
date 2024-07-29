#include <bits/stdc++.h>
using namespace std;

int main() {
    string a1[3] = { "-openmp-task" , "-openmp-untask" , "-openmp-task-minside" };
    string a2[2] = { "-U", "-V" };
    string a3[2] = { "-sgemm","-sgemm-neon" };
    string a4[2] = { "-sgemm-neon","-sgemm-44" };
    string a5[2] = { "" , "-check" };

    int cot = 7;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << cot++ << a1[i] <<  a2[0] << a3[j] << a2[1] << a4[k] << ".sh" << endl;
                cot++;
            }
        }
    }

    return 0;
}
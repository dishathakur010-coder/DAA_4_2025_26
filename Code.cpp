/*Recurrence Relation - T(n) = 3T(n/2)+O(nlogn)
  Time Complexity - T(n) = Θ(n1.585)
  Master Theorem Case 1 - a>b^k*/
#include <bits/stdc++.h>
using namespace std;
long long opCount = 0;
int depthMax = 0;
void complexRec(int n, int depth) {
    if (depth > depthMax)
        depthMax = depth;
    if (n <= 2)
        return;
    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            opCount++;
        }
        p = p >> 1;
    }
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        opCount++;
    }
    reverse(small.begin(), small.end());
    opCount += n;
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}
int main() {
    int nValues[] = {8, 16, 32, 64};
    for (int i = 0; i < 4; i++) {
        int n = nValues[i];
        opCount = 0;
        depthMax = 0;
        auto start = chrono::high_resolution_clock::now();
        complexRec(n, 1);
        auto end = chrono::high_resolution_clock::now();
        auto timeTaken =
            chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "n = " << n << endl;
        cout << "Operations = " << opCount << endl;
        cout << "Recursion Depth = " << depthMax << endl;
        cout << "Time = " << timeTaken.count() << " ms" << endl;
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int avg = accumulate(A.begin(), A.end(), 0) / N;
    int dist;
    for (int i = 0; i < N; i++) {
        dist = abs(A.at(i) - avg);
        cout << dist << endl;
    }
}

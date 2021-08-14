#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N + 1, vector<int>(3, 0));
    for (int i = 1; i < N + 1; i++) {
        cin >> A.at(i).at(0) >> A.at(i).at(1) >> A.at(i).at(2);
    }

    for (int i = 0; i < N; i++) {
        int dist = abs(A.at(i).at(1) - A.at(i + 1).at(1)) + abs(A.at(i).at(2) - A.at(i + 1).at(2));
        int time = A.at(i + 1).at(0) - A.at(i).at(0);
        if (dist > time || abs(dist - time) % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}

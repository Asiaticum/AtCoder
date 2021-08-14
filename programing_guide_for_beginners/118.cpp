#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    vector<vector<char>> result(N, vector<char>(N, '-'));

    for (int i = 0; i < M; i++) {
        result.at(A.at(i) - 1).at(B.at(i) - 1) = 'o';
        result.at(B.at(i) - 1).at(A.at(i) - 1) = 'x';
    }


    int i;
    int size;
    for (vector<char> x : result) {
        i = 0;
        size = x.size();
        for (char y : x) {
            i++;
            cout << y;
            if (i == size) {
                cout << endl;
            } else {
                cout << ' ';
            }
        }
    }
}

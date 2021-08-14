#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    int b;
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end(), greater<int>());
    int A_point = 0, B_point = 0;
    for (int i = 0; i < N; i += 2) {
        A_point += a.at(i);
    }
    for (int i = 1; i < N; i += 2) {
        B_point += a.at(i);
    }

    cout << A_point - B_point << endl;

    return 0;
}

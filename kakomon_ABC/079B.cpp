#include <bits/stdc++.h>
using namespace std;

int64_t lucas_number(int N) {
    if (N == 0) {
        return 2;
    }

    if (N == 1) {
        return 1;
    }

    return lucas_number(N - 1) + lucas_number(N - 2);
}

int main() {
    int N;
    cin >> N;

    vector<int64_t> l = {2, 1};
    if (N == 0 || N == 1) {
        cout << l.at(N) << endl;
        return 0;
    } else {
        for (int i = 2; i < N + 1; i++) {
            l.push_back(l.at(i - 1) + l.at(i - 2));
        }
    }
    cout << l.at(N) << endl;

    return 0;
}

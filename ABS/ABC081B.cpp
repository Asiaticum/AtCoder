#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }

    int counter = 0;
    bool flag = true;
    while (flag) {
        for (int i = 0; i < N; i++) {
            if (A.at(i) % 2 == 0) {
                A.at(i) /= 2;
            } else {
                flag = false;
                break;
            }
        }

        if (flag) {
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}

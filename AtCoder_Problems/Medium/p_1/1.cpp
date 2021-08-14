#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    vector<int> pushed_button;
    int button_now = 1;
    int counter = 0;

    while (true) {
        pushed_button.push_back(button_now);
        button_now = A.at(button_now - 1);
        counter++;

        if (button_now == 2) {
            break;
        }

        if (find(pushed_button.begin(), pushed_button.end(), button_now) != pushed_button.end()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << counter << endl;

    return 0;
}

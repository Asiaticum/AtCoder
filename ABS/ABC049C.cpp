#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    vector<string> T = {"dream", "dreamer", "erase", "eraser"};

    for (int i = 0; i < T.size(); i++) {
        reverse(T.at(i).begin(), T.at(i).end());
    }

    bool flag = false;
    while (true) {
        if (S.length() == 0) {
            cout << "YES" << endl;
            break;
        }


        for (string t : T) {
            flag = false;
            if (S.substr(0, t.size()) == t) {
                S = S.substr(t.size());
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << "NO" << endl;
            break;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    int itr = S.size();
    for (int i = 2; i < itr + 1; i += 2) {
        string tmp = S.substr(0, S.size() - i);
        if (tmp.substr(0, tmp.size() / 2) == tmp.substr(tmp.size() / 2)) {
            cout << tmp.size() << endl;
            return 0;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string S;
    cin >> S;

    int ans = 0;
    for (int i = 1; i < S.size(); i++) {
        int count = 0;
        string S1 = S.substr(0, i);
        string S2 = S.substr(i);
        string tmp = "";

        for (char s : S1) {
            if (S2.find(s) != string::npos && tmp.find(s) == string::npos) {
                count++;
                tmp += s;
            }
        }
        ans = max(ans, count);
    }

    cout << ans << endl;
    return 0;
}

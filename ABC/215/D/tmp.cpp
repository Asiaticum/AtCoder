/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2021.08.21 23:01:55
 **/

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int maxA = 100000;
    int n, m;
    cin >> n >> m;
    vector<bool> k(maxA + 1, true);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 1) k[a] = false;
    }
    vector<bool> isprime(maxA + 1, true);
    vector<int> prime;
    for (int i = 2; i <= maxA; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j <= maxA; j += i) {
            isprime[j] = false;
            k[i] = k[i] & k[j];
        }
        if (!k[i]) prime.push_back(i);
    }
    for (int p : prime)
        for (int j = p + p; j <= m; j += p) k[j] = k[j] & k[p];
    vector<int> ans;
    for (int i = 1; i <= m; i++)
        if (k[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e8;
const ll MOD = 1e9 + 7;
const ll LINF = 1e17;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

bool compare(string a, string b, string X) {
    bool name_order = false;

    for (int j = 0; j < a.size(); j++) {
        if (b.size() <= j || X.find(a.at(j)) > X.find(b.at(j))) {
            name_order = true;
            break;
        } else if (X.find(a.at(j)) < X.find(b.at(j)) || j == a.size() - 1) {
            name_order = false;
            break;
        }
    }

    return name_order;
}

void merge(vector<string> &S, int l, int m, int r, string X) {
    int i, j, k;

    int n1 = m - l + 1;  // number of elements in first subarray
    int n2 = r - m;      // number of elements in second subarray

    // create temporary subarrays
    vector<string> L(n1);  // array[l..m]
    vector<string> R(n2);  // array[m+1..r]

    // copy data to subarrays L and R
    for (i = 0; i < n1; i++) L[i] = S[l + i];
    for (j = 0; j < n2; j++) R[j] = S[m + 1 + j];

    // merge the two arrays
    i = 0;  // index of L
    j = 0;  // index of R
    k = l;  // index of merged array

    while (i < n1 && j < n2) {
        // cout << L[i] << R[j] << endl;
        // cout << compare(L[i], R[j], X) << endl;
        if (!compare(L[i], R[j], X)) {
            S[k] = L[i];
            i++;
        } else {
            S[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        S[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        S[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string> &S, int l, int r, string X) {
    if (l < r) {
        // avoids overflow for large l and h
        int m = l + (r - l) / 2;

        mergeSort(S, l, m, X);
        mergeSort(S, m + 1, r, X);
        merge(S, l, m, r, X);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X;
    cin >> X;
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S.at(i);
    }

    mergeSort(S, 0, N - 1, X);

    for (string s : S) {
        cout << s << endl;
    }


    return 0;
}

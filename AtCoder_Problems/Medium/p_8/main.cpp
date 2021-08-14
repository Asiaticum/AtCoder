#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void put_color(vector<string> &c, string color) {
    if (find(c.begin(), c.end(), color) == c.end()) {
        c.push_back(color);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    vector<string> colors = {"grey", "blown",  "green",  "lightblue",
                             "blue", "yellow", "orange", "red"};
    vector<string> c;
    int min_color = 1, max_color = 0;
    int bonus = 0;
    for (int a : A) {
        string color;
        if (a <= 399) {
            color = "grey";
            put_color(c, color);
        } else if (a <= 799) {
            color = "blown";
            put_color(c, color);
        } else if (a <= 1199) {
            color = "green";
            put_color(c, color);
        } else if (a <= 1599) {
            color = "lightblue";
            put_color(c, color);
        } else if (a <= 1999) {
            color = "blue";
            put_color(c, color);
        } else if (a <= 2399) {
            color = "yellow";
            put_color(c, color);
        } else if (a <= 2799) {
            color = "organge";
            put_color(c, color);
        } else if (a <= 3199) {
            color = "red";
            put_color(c, color);
        } else {
            bonus++;
        }
    }
    int num = c.size();
    min_color = max(min_color, num);
    max_color = c.size();
    max_color = max_color + bonus;

    cout << min_color << " " << max_color << endl;
    return 0;
}

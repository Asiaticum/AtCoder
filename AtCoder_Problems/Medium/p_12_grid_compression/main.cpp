#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    for (int i = 0; i < H; i++)
    {
        cin >> A.at(i);
    }

    auto itr = A.begin();
    while (itr != A.end())
    {
        string s = *itr;
        if (s.find("#") == string::npos)
        {
            itr = A.erase(itr);
            H--;
        }
        else
        {
            itr++;
        }
    }

    bool is_sharp_in = false;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (A.at(j).at(i) == '#')
            {
                is_sharp_in = true;
            }
        }
        if (!is_sharp_in)
        {
            for (int j = 0; j < H; j++)
            {
                A.at(j).erase(i, 1);
            }
            i--;
            W--;
        }
        is_sharp_in = false;
    }

    for (string s : A)
    {
        cout << s << endl;
    }

    return 0;
}

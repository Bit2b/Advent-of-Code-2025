#include <bits/stdc++.h>
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
using namespace std;
class solution
{
    vector<string> splitters;

public:
    solution()
    {
        readInput();
        solve();
    }
    void readInput();
    void solve();
};
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    clock_t z = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    solution sol;
    cerr << "Run time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}
void solution::readInput()
{
    int i = 0;
    string s;
    getline(cin, s);
    while (getline(cin, s))
    {
        if (i)
            splitters.push_back(s);
        i = 1 - i;
    }
}

void solution::solve()
{
    int n = splitters[0].size();
    vector<int> lastSplitter(n, -1);
    lastSplitter[n / 2] = 0;
    int res = 1;
    for (int i = 1; i < splitters.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (splitters[i][j] == '^' &&
                (lastSplitter[j] < lastSplitter[j - 1] or
                 lastSplitter[j] < lastSplitter[j + 1]))
            {
                res++;
                lastSplitter[j] = i;
            }
        }
    }
    cout << res << endl;
    return;
}
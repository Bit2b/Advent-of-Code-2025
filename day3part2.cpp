#include <bits/stdc++.h>
#include "../algo/debug.h"
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
using namespace std;
class solution
{
    vector<string> banks;

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
    string s;
    while (getline(cin, s))
    {
        banks.push_back(s);
    }
}
string findMax(string &s, int n, int start, int end)
{
    string res;
    int pos = start;

    while (n > 0)
    {
        int best = pos;
        int limit = end - n;
        for (int i = pos; i <= limit; ++i)
        {
            if (s[i] > s[best])
                best = i;
        }
        res.push_back(s[best]);
        pos = best + 1; 
        n--;
    }

    return res;
}

void solution::solve()
{
    int ans = 0;
    for (auto bank : banks)
    {
        int res = stoll(findMax(bank, 12, 0, bank.size()));
        ans += res;
    }
    cout << ans << endl;
    return;
}
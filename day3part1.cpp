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
void solution::solve()
{
    int ans = 0;
    for (auto bank : banks)
    {
        int mx_pos = max_element(bank.begin(), bank.end()) - bank.begin();
        int res = bank[mx_pos] - '0';
        if (mx_pos == bank.length() - 1)
        {
            bank.pop_back();
            res = (*max_element(bank.begin(), bank.end()) - '0') * 10 + res;
        }
        else
        {
            bank = bank.substr(mx_pos + 1);
            res = (*max_element(bank.begin(), bank.end()) - '0') + res * 10;
        }
        ans += res;
    }
    cout << ans << endl;
    return;
}
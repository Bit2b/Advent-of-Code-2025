#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../algo/debug.h"
#else
#define debug(...) (void)0
#endif
#define all(v) v.begin(), v.end()
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
#define endl '\n'
const int MOD = (int)1000000000 + 7;
using namespace std;
class solution
{
    vector<pair<int, int>> range;
public:
    solution();
    void readInput();
    void solve();
};
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    clock_t z = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    solution sol;
    cerr << "Run time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}
solution::solution()
{
    readInput();
    solve();
}
void solution::readInput()
{
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    char noise;
    while (ss)
    {
        int start, end;
        ss >> start;
        ss >> noise;
        ss >> end;
        if (ss)
            ss >> noise;
        range.emplace_back(make_pair(start, end));
    }
}
void solution::solve()
{
    set<int> s;
    for (int i = 1; i < 1e6; i++)
    {
        int len = 1 + (int)log10(i);
        int n = i;
        for (int j = 1; j < (12 / len); j++)
        {
            n = n * pow(10, len) + i;
            s.insert(n);
        }
    }
    vector<int> st(s.begin(), s.end());
    vector<int> psum(s.size() + 1, 0);
    for (int i = 1; i < psum.size(); i++)
    {
        psum[i] = psum[i - 1] + st[i - 1];
    }
    int res = 0;
    for (auto p : range)
    {
        int invalidSum = 0;
        int f = lower_bound(st.begin(), st.end(), p.first) - st.begin();
        int l = upper_bound(st.begin(), st.end(), p.second) - st.begin();
        invalidSum = psum[l] - psum[f];
        res += invalidSum;
    }
    cout << res << endl;
    return;
}
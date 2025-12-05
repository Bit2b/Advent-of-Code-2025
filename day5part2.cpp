#include <bits/stdc++.h>
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
using namespace std;
class solution
{
    vector<pair<int, int>> ranges;
    vector<int> ingredients;

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
    char c;
    while (getline(cin, s))
    {
        if (s == "")
            break;
        stringstream ss;
        ss << s;
        int start, end;
        ss >> start;
        ss >> c;
        ss >> end;
        ranges.emplace_back(make_pair(start, end));
    }
    while (getline(cin, s))
    {
        ingredients.push_back(stoll(s));
    }
}
void solution::solve()
{
    int res = 0, n = ranges.size();
    sort(ranges.begin(), ranges.end());
    for (int i = 0; i < n; i++)
    {
        auto [start, end] = ranges[i];
        while ((i + 1) < n and ranges[i + 1].first <= end)
        {
            end = max(end, ranges[i + 1].second);
            i++;
        }
        res += end - start + 1;
    }
    cout << res << endl;
    return;
}
#include <bits/stdc++.h>
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
using namespace std;
class solution
{
    vector<string> v;
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
        v.push_back(s);
    }
}
void solution::solve()
{
    int n = v.size(), m = v[0].size();
    vector<vector<int>> neighbours(n, vector<int>(m));
    vector<vector<bool>> inQueue(n, vector<bool>(m));
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
    queue<pair<int, int>> q;
    auto isBound = [n, m](int x, int y)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    };
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '@')
            {
                for (int k = 0; k < 8; k++)
                {

                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (isBound(xx, yy) && v[xx][yy] == '@')
                    {
                        neighbours[i][j]++;
                    }
                }
                if (neighbours[i][j] < 4)
                {
                    q.push({i, j});
                    inQueue[i][j] = 1;
                }
            }
        }
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        v[x][y] = '.';
        res++;
        for (int k = 0; k < 8; k++)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (isBound(xx, yy) && v[xx][yy] == '@')
            {
                neighbours[xx][yy]--;
                if (!inQueue[xx][yy] && neighbours[xx][yy] < 4)
                {
                    q.push({xx, yy});
                    inQueue[xx][yy] = 1;
                    continue;
                }
            }
        }
    }
    cout << res << endl;
    return;
}
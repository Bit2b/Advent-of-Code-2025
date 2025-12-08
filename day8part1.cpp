#include <bits/stdc++.h>
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
using namespace std;
class solution
{
    vector<vector<int>> points;

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
        stringstream ss(s);
        int x, y, z;
        char c;
        ss >> x;
        ss >> c;
        ss >> y;
        ss >> c;
        ss >> z;
        points.emplace_back(vector<int>({x, y, z}));
    }
}

class dsu
{
    vector<int> parent;

public:
    dsu(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            parent[b] = a;
        }
    }
};

void solution::solve()
{
    int connections = 1000;
    vector<pair<int, int>> twoPoints;
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            twoPoints.emplace_back(make_pair(i, j));
        }
    }
    sort(twoPoints.begin(), twoPoints.end(), [&](auto &a, auto &b)
         {
        auto &p1 = points[a.first];
        auto &p2 = points[a.second];
        auto &q1 = points[b.first];
        auto &q2 = points[b.second];
        
        long long da = (p1[0]-p2[0])*(p1[0]-p2[0]) +
        (p1[1]-p2[1])*(p1[1]-p2[1]) +
        (p1[2]-p2[2])*(p1[2]-p2[2]);
        
        long long db = (q1[0]-q2[0])*(q1[0]-q2[0]) +
        (q1[1]-q2[1])*(q1[1]-q2[1]) +
        (q1[2]-q2[2])*(q1[2]-q2[2]);
        
        return da < db; });

    dsu d(points.size());
    for (int i = 0; i < connections; i++)
    {
        d.union_set(twoPoints[i].first, twoPoints[i].second);
    }

    map<int, int> mp;
    for (int i = 0; i < points.size(); i++)
    {
        d.find_set(i);
    }
    for (int i = 0; i < points.size(); i++)
    {
        mp[d.find_set(i)]++;
    }

    vector<int>v;
    for (auto &[_, val] : mp)
    {
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout << v[0]*v[1]*v[2] << endl;
    return;
}
#include <bits/stdc++.h>
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
using namespace std;
class solution
{
    vector<vector<int>> values;
    vector<char> op;

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
    vector<string> inp;
    while (getline(cin, s))
    {
        inp.push_back(s);
    }
    {
        stringstream ss;
        ss << inp.back();
        inp.pop_back();
        char val;
        while (ss >> val)
        {
            if (val != 32)
                op.push_back(val);
        }
    }
    int i = 0;
    values.resize(op.size());
    vector<int>valueOffset;
    for(int i=0;i<s.size();i++){
        if(s[i]!=32){
            valueOffset.push_back(i);
        }
    }
    
    for(int i=0;i<valueOffset.size();i++){
        int k=0;
        while(true){
            int val=0;
            int j=valueOffset[i]+k;
            for(auto& line:inp){
                if(isdigit(line[j])){
                    val*=10;
                    val+=line[j]-'0';
                }
            }
            if(val==0)break;
            values[i].push_back(val);
            k++;
        }
    }

}

void solution::solve()
{
    int res = 0;
    for (int i = 0; i < values.size(); i++)
    {
        if (op[i] == '*')
        {
            int ans = 1;
            for (int &val:values[i])
            {
                ans *= val;
            }
            res += ans;
        }
        else
        {
            int ans = 0;
            for (int  &val: values[i])
            {
                ans += val;
            }
            res += ans;
        }
    }
    cout << res << endl;
    return;
}
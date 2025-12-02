#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../algo/debug.h"
#else
#define debug(...) (void)0
#endif
#define all(v) v.begin(),v.end()
#define int long long int
#define IMAX INT64_MAX
#define IMIN INT64_MIN
#define endl '\n'
const int MOD =(int)1000000000+7;
using namespace std;
void cases();
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  clock_t z = clock();
#ifndef ONLINE_JUDGE
  freopen("input.txt" , "r", stdin );
  freopen("output.txt", "w", stdout);
  freopen("error.txt" , "w", stderr);
#endif
  cases();
  cerr << "Run time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}
void cases()
{
  int position=50;
  int answer=0;
  string line;
  while(getline(cin,line)){
    stringstream ss;
    ss<<line;
    char direction;
    ss>>direction;
    int rotation;
    ss>>rotation;
    answer+=rotation/100;
    rotation%=100;
    if(direction=='L'){
      if(position==0){
        position=100;
      }
      position-=rotation;
      if(position<=0){
        answer++;
      }
      if(position<0){
        position+=100;
      }
    }else{
      position+=rotation;
      if(position>99){
        answer++;
        position-=100;
      }
    }
  }
  cout<<answer<<endl;
  return;
}
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =1e6+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
vector<vector<ll>>v,malik(101),dp(101,vector<ll>(1<<10+1,-1));
ll n,m;
ll magic(ll shirt,ll lft)
{
    if(!lft){return 1;}
    if(shirt>100){return 0;}
    if(dp[shirt][lft]!=-1){return dp[shirt][lft];}
    ll ans=0;
    for(auto it:malik[shirt])
    {
        if((lft&(1<<it)))
        {
            ans+=magic(shirt+1,(lft-(1<<it)));
            ans%=M;
        }
    }
    ans+=magic(shirt+1,lft);
    ans%=M;
    return dp[shirt][lft]=ans;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cin>>n;cin.ignore();
        v.resize(n);
        k=1;
        for(i=0;i<n;i++)
        {
            k*=2;
            string s;
            getline(cin, s);
            istringstream ss(s);
            ll tmp;
            while(ss >> tmp){v[i].push_back(tmp);}
        }
        i=0;
        for(auto it:v)
        {
            for(auto tt:it)
            {
                malik[tt].pb(i);
            }i++;
        }
        cout<<magic(1,k-1)<<endl;
        v.clear();
        for(i=0;i<101;i++){for(j=0;j<(1<<10)+1;j++){dp[i][j]=-1;}}
        for(i=0;i<101;i++){malik[i].clear();}
    }
}
/***
https://www.codechef.com/AUG14/problems-old/TSHIRTS

কন্সট্রেইন্ট এর মদ্ধ্যেই কিন্ত হিন্টস লুকানো থাকে।


#At first, I thought I have to run dp over the number of shirt(100)
#But couldn't figure out how would I implement the problem.
#Then the tutorial said- run dp over Elephants.
#Thanks to Kartik Aurora's tutorial.
***/

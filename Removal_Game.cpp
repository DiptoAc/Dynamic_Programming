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
const ll N =5e3+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<ll>>dp(N,vector<ll>(N,LLONG_MIN));
vector<ll>v;
ll magic(ll x, ll y)
{
    if(y<x){return 0;}
    if(dp[x][y]!=LLONG_MIN){return dp[x][y];}
    ll a,b;
    a=v[x]-magic(x+1,y);
    b=v[y]-magic(x,y-1);
    return dp[x][y]=max(a,b);
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;
        ll sum=0;
        v.resize(n);
        for(auto &it:v){cin>>it;sum+=it;}
        k=magic(0,n-1);
        sum-=k;
        sum/=2;
        sum+=k;
        cout<<sum<<endl;
    }
}

/***
CSES
Removal Game
https://cses.fi/problemset/task/1097

এই প্রবলেমটা প্রথম পাই একটা TFC ফার্ষ্ট ইয়ারে। সেসময় ডিপি নাগালের অনেক বাইরে,
ভেবেছিলাম ডিপি শেখা মাত্র এই প্রবলেমটা সলভ করবো। আড়াই বছর পর হঠাত এই প্রবলেমটা
চোখে পড়লো। It's nostalogic man.

যাহোক, সুন্দর একটা প্রবলেম। অবজারভেশনটা পাওয়া খুব একটা সহজ নয়। ডিপির বেসিকট
কমপ্লিট হয়ে গেলে এই প্রবলেমটা ট্রাই করা যেতে পারে
***/

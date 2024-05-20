#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =3e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<ll>>dp(1001,vector<ll>(1025,-1));
void generate_mask(ll mask,ll cur_mask,ll pos,vector<ll>&nxt_mask)
{

    if(pos==n){nxt_mask.pb(cur_mask);return;}
    if(((mask>>pos)&1)==0)
    {
        generate_mask(mask,cur_mask+(1<<pos),pos+1,nxt_mask);
    }
    if(pos<n-1)
    {
        if((((mask>>pos)&1)==0) && (((mask>>(pos+1))&1)==0))
        {generate_mask(mask,cur_mask,pos+2,nxt_mask);}
    }
    if(((mask>>pos)&1)==1){generate_mask(mask,cur_mask,pos+1,nxt_mask);}
}
ll magic(ll col,ll mask)
{
    if(col==m){return (mask==0?1:0);}
    if(dp[col][mask]!=-1){return dp[col][mask];}
    ll ans=0;
    vector<ll>nxt_mask;
    generate_mask(mask,0,0,nxt_mask);
    set<ll>st;
    for(auto it:nxt_mask){st.insert(it);}
    for(auto it:st)
    {
        ans+=magic(col+1,it);
        ans%=M;
    }
    return dp[col][mask]=ans;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        cout<<magic(0,0)<<endl;
        vector<ll>v;
    }
}
/***
https://cses.fi/problemset/task/2181
Counting Tilings.

Of course I got to practice or solve these problem multiple times./
Intution didn't help. Had to watch the tutorial video by Kartik Aurora.
***/

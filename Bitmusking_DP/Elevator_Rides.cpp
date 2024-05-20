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
const ll N =3e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        vector<ll>v(n);
        for(auto &it:v){cin>>it;}
        vector<pair<ll,ll>>dp((1<<n),{LONG_MAX,LLONG_MAX});
        dp[0]={1,0};
        for(i=1;i<(1<<n);i++)
        {
            for(j=0;j<n;j++)
            {
                if(!(1&(i>>j))){continue;}
                ll space_taken=dp[i^(1<<j)].second;
                if(space_taken+v[j]<=k)
                {
                    dp[i]=min(dp[i],{dp[(i^(1<<j))].first,space_taken+v[j]});
                }
                else
                {
                    dp[i]=min(dp[i],{dp[(i^(1<<j))].first+1,v[j]});
                }
            }
        }
        cout<<dp[(1<<n)-1].first<<endl;
        //for(i=0;i<(1<<n);i++){cout<<i<<" "<<dp[i].first<<" "<<dp[i].second<<endl;}

    }
}
/***
https://cses.fi/problemset/task/1653
Elevator Rides(CSES)

Youtube Solution: https://www.youtube.com/watch?v=UEkvzjsodDk

20! is not computable. But this dp made operations
with 20! possible.
***/


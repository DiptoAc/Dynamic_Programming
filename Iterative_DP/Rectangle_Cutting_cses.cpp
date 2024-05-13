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
const ll N =5e2+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<ll>>dp(N,vector<ll>(N,INT_MAX));
ll magic(ll x,ll y)
{
    ll i,j,k;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            if(i==j)
            {
                dp[i][j]=1;
            }
            else
            {
                for(k=1;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]);
                }
                for(k=1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }return dp[x][y];
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        cout<<magic(n,m)-1<<endl;
    }
}



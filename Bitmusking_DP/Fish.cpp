#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll int
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =1e6+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<double>>v(19,vector<double>(19));
vector<double>dp((1<<19),-1.0);
double magic(ll lft)
{
    if(dp[lft]>-0.9){return dp[lft];}
    ll i,j,alive=__builtin_popcount(lft);
    double ans=0.0,temp=alive*alive+alive;
    temp/=2;
    temp=1.0/temp;
    if(alive==n){return dp[lft]=1.0;}
    for(i=0;i<n;i++)
    {
        if(!((lft>>i)&1)){continue;}
        for(j=0;j<n;j++)
        {
            if(((lft>>j)&1)){continue;}
            ans+=temp*v[i][j]*magic(lft+(1<<j));
        }
    }
    return dp[lft]=ans;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(i=0;i<n;i++){for(j=0;j<n;j++){cin>>v[i][j];}}
        k=1;
        for(i=0;i<n;i++)
        {
            cout<<setprecision(8)<<fixed<<magic(k)<<" ";
            k*=2;
        }cout<<endl;

    }
}
/**
Bitmusking DP
https://codeforces.com/contest/16/problem/E


এই প্রবলেমটার আইডিয়া নিজ থেকে পাইনি। আমি ৩ টা ভিন্ন ভিন্ন স্টেট রাখার কথা চিন্তা করছিলাম। পরবর্তিতে Kartik Aurora র টিউটোরিয়াল ভিডিওতে দেখলাম
একটা মাত্র স্টেট রাখাই যথেষ্ট। রিকারসিভ ডিপিও যে বটম থেকে কল করে করা যায়,তা আগে জানতাম না।


#Takings:
1) Top থেকে ডিপি কল করে যদি এন্সার না পাওয়া যায়, Bottom থেকে ডিপি কল করা যায় কিনা, চিন্তা কর।
2) Test case বিহীন প্রবলেমে একবার ডিপি কল করেই যে সমস্ত এন্সার বের করে ফেলতে হবে, সেই বাধ্যবাধকতা নেই।
**/

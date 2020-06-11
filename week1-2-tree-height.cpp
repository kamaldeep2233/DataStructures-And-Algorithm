#include<bits/stdc++.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,j,n) for(i=j;i<=n;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<int> > graph;
const ll maxn = (ll) 1e5+9;
const ll mod = (ll) 1e9+7;

//ll a[maxn];
//ll dp[1024][1024];
graph A(maxn);

int height(int r){
    if(A[r].size()==0) return 1;
    else{
        int maxh=0;
        rep(i, A[r].size()){
            int j=A[r][i];
            maxh=MAX(maxh, height(j));
        }
        return 1+maxh;
    }
}

int main()
{
	std::ios::sync_with_stdio(0);
	ll i,j,k,t,q,m,l,n;
    cin>>n;
    int p[n];
    int r;
    rep(i, n){
        cin>>p[i];
        if(p[i]==-1) r=i;
        else A[p[i]].pb(i);
    }
    cout<<height(r)<<endl;
}

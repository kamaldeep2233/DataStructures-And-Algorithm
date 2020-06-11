#include<bits/stdc++.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
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

int main()
{
	std::ios::sync_with_stdio(0);
	int I,J,K,T,m,l,r,n;
    int S;
    cin>>S>>n;
    queue<pair<int, pair<int, int> > > q;
    vector<pair<int, pair<int, int> > > v(n);
    rep(I, n){
        cin>>J>>K;
        v[I]=mp(I, mp(J,K));
    }
    vector<int> res(n);
    J=0;
    while(J<n && J<S){
        q.push(v[J]);
        J++;
    }
    T=0;
    while(!q.empty()){
        int st=MAX(T, q.front().second.first);
        T = st+q.front().second.second;
        res[q.front().first]=st;
        q.pop();
        while(q.size()<S && J<n){
            if(v[J].second.first<T){
                res[J++]=-1;
            }else{
                q.push(v[J++]);
            }
        }
    }
    rep(I, n){
        cout<<res[I]<<endl;
    }
    
    return 0;

}

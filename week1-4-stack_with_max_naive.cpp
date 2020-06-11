#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a,b) make_pair(a,b)

class stacks
{
	vector<pair<ll,ll> > element;
	ll top;

public:
	stacks()
	{
		top=-1;
	}
	bool empty()
	{
		return top==-1;
	}
	void push(ll a)
	{
		if(empty())
		{
			element.push_back(mp(a,a));
			top=0;
		}
		else
		{
			ll mx=max(a,element[top].second);
			element.push_back(mp(a,mx));
			top++;
		}
	}
	void pop()
	{
		element.pop_back();
		top--;
	}
	ll maxa()
	{
		return element[top].second;
	}
};

int main()
{	//cin.tie(true);
	ll n;
	cin>>n;
	stacks s;
	string input;
	ll a,i;
	for(i=0;i<n;++i)
	{
		cin>>input;
		if(input=="push")
		{
			cin>>a;
			s.push(a);
		}
		else if(input=="pop")
			s.pop();
		else
			cout<<s.maxa()<<"\n";
	}
	return 0;
}

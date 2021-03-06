/*************************************************************************
    > File Name: 112-2-C.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 17时57分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<bitset>
#include<sstream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int n;
	string str;
	ll ans=0;
	cin>>n>>str;
	vector<int> pos;
	for(int i=0;i<str.length();i++)
		if(str[i]=='1') pos.push_back(i);
	if(n==0)
	{
		if(n==0)
		{
			ll cont=0;
			for(int i=0;i<str.length();i++)
			{
				if(str[i]=='0') cont++;
				else {
					ans+=cont*(cont+1)/2;
					cont=0;
				}
			}
			if(cont>0)
			{
				ans+=(cont+1)*cont/2;
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	for(int i=0;i<pos.size();i++)
	{
		ll contl=0,contr=0;
		int id=i+n-1;
		if(id>=pos.size()) break;
		int l=pos[i]-1;
		int r=pos[id]+1;
		while(l>=0&&str[l]=='0')
		{
			contl++;
			l--;
		}
		while(r<str.length()&&str[r]=='0')
		{
			contr++;
			r++;
		}
		ans+=(contl+contr+1+contl*contr);
	}
	cout<<ans<<endl;
	return 0;
}


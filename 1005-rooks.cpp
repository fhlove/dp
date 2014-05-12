/*************************************************************************
    > File Name: 1005-rooks.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月14日 星期五 21时13分58秒
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
ll c[35][35];
void init()
{
	for(int i=0;i<=30;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
	}
	for(int i=2;i<=30;i++)
	{
		for(int j=1;j<i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
}
int main()
{
	//freopen("/home/mengshangqi/input.txt","r",stdin);
	int t;
	int n,m;
	init();
	cin>>t;
	for(int cs=1;cs<=t;cs++)
	{
		cin>>n>>m;
		cout<<"Case "<<cs<<": ";
		if(m>n) 
		{
			cout<<0<<endl;
			continue;
		}
		ll ans=c[n][m];
		ans*=ans;
		while(m>1)
		{
			ans*=m;
			m--;
		}
		cout<<ans<<endl;
	}
	return 0;
}

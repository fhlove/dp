/*************************************************************************
    > File Name: bomb.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年02月27日 星期四 19时42分53秒
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
ll dp[100][3];
int num[100];
int init(ll n)
{
	int cont=0;
	while(n)
	{
		num[cont++]=n%10;
		n/=10;
	}
	return cont;
}
ll dfs(int cont,int flag,bool limit)
{
	if(cont==-1)
		return flag==2? 1:0;
	if(!limit&&dp[cont][flag]!=-1) return dp[cont][flag];
	int end=limit? num[cont]:9;
	ll res=0;
	for(int i=0;i<=end;i++)
	{
		int temp=flag;
		if(flag==0&&i==4)
			temp=1;
		if(flag==1&&i==9) 
			temp=2;
		if(flag==1&&i!=9&&i!=4)
			temp=0;
		res+=dfs(cont-1,temp,limit&&i==end);
	}
	if(!limit) dp[cont][flag]=res;
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	ll n;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n;
		int cont=init(n);	
		ll ans=dfs(cont-1,0,1);
		cout<<ans<<endl;
	}
	return 0;
}

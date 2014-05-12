/*************************************************************************
    > File Name: windynumber.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年02月27日 星期四 20时21分44秒
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
int ln[100],rn[100];
ll dp[100][20];
int init(ll n,int *num)
{
	int cont=0;
	while(n)
	{
		num[++cont]=n%10;
		n/=10;
	}
	return cont;
}
int calc(int a,int b)
{
	return abs(a-b);
}
ll dfs(int cont,bool limit,int last,bool flag,int *num)
{
	if(cont==0)
	{
		if(flag) return last==0? 0:1;
		return 1;
	}
	if(!limit&&!flag&&dp[cont][last]!=-1) return dp[cont][last];
	int end=limit? num[cont]:9;
	ll res=0;
	for(int i=0;i<=end;i++)
	{
		if(calc(last,i)>=2||flag)
			res+=dfs(cont-1,limit&&i==end,i,flag&&i==0,num);
	}
	if(!limit&&!flag) dp[cont][last]=res;
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	int l,r;
	while(cin>>l>>r)
	{
		memset(dp,-1,sizeof(dp));
		memset(ln,0,sizeof(ln));
		memset(rn,0,sizeof(rn));
		int c1=init(l-1,ln);
		ll res1=dfs(c1,1,0,1,ln);

		memset(dp,-1,sizeof(dp));
		int c2=init(r,rn);		
		ll res=dfs(c2,1,0,1,rn);
		//cout<<res<<"  "<<res1<<endl;
		cout<<res-res1<<endl;
	}
	return 0;
}

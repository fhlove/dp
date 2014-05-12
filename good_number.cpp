/*************************************************************************
    > File Name: good_number.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com
    > Created Time: 2014年02月27日 星期四 21时50分43秒
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
ll dp[100][20];
int L[100],R[100];
int init(ll x,int *num)
{
	int cont=0;
	while(x)
	{
		num[++cont]=x%10;
		x/=10;
	}
	return cont;
}
ll dfs(int cont,int mod,bool limit,int *num)
{
	//cout<<"--------"<<endl;
	if(cont==0)
	{
		return mod==0? 1:0;
	}
	if(!limit&&dp[cont][mod]!=-1) return dp[cont][mod];
	int end=limit? num[cont]:9;
	ll res=0;
	for(int i=0;i<=end;i++)
	{
		res+=dfs(cont-1,(mod+i)%10,limit&&i==end,num);
	}
	if(!limit) dp[cont][mod]=res;
	return res;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int t;
	ll l,r;
	int c=1;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>l>>r;

		int cl=init(l-1,L);
		ll res1=dfs(cl,0,1,L);

		int cr=init(r,R);
		memset(dp,-1,sizeof(dp));
		ll res=dfs(cr,0,1,R);

		printf("Case #%d: ",c++);
		cout<<res-res1<<endl;
	}
	return 0;
}

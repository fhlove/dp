/*************************************************************************
    > File Name: 2-2-B.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月27日 星期四 20时09分18秒
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
const int N=1005;
int dp[N][N][2];
int m[N][N];
int path[2][N][N];
bool flag=0;
vector<char> s;
//0:up 1:left
int contx(int y,int x)
{
	int cont=0;
	while(y%x==0&&y)
	{
		y/=x;
		cont++;
	}
	return cont;
}
void print(int i,int x,int y)
{
	if(x==0||y==0) return;
	if(path[i][x][y]==0)
	{
		if(m[x][y]==0) flag=1;
		print(i,x-1,y);
		s.push_back('D');
	}else {
		if(m[x][y]==0) flag=1;
		print(i,x,y-1);
		s.push_back('R');
	}
}
void solve(int n)
{
	memset(dp,0x1f,sizeof(dp));
	dp[0][0][0]=dp[0][0][1]=dp[0][1][0]=dp[0][1][1]=dp[1][0][0]=dp[1][0][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int cont2=contx(m[i][j],2);
			int cont5=contx(m[i][j],5);	
			if(dp[i-1][j][0]<dp[i][j-1][0])
			{
				dp[i][j][0]=dp[i-1][j][0]+cont2;
				path[0][i][j]=0;
			}else {
				dp[i][j][0]=dp[i][j-1][0]+cont2;
				path[0][i][j]=1;
			}
			if(dp[i-1][j][1]<dp[i][j-1][1])
			{
				dp[i][j][1]=dp[i-1][j][1]+cont5;
				path[1][i][j]=0;
			}else {
				dp[i][j][1]=dp[i][j-1][1]+cont5;
				path[1][i][j]=1;
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int n;
	int x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&m[i][j]);
			if(m[i][j]==0)
			{
				flag=1;
				x=i;
				y=j;
			}
		}
	solve(n);
	int ans=0;
	if(dp[n][n][0]<dp[n][n][1])
	{
		ans=dp[n][n][0];
		print(0,n,n);
	}else {
		ans=dp[n][n][1];
		print(1,n,n);
	}
	if(flag==1)
	{
		if(ans>1)
		{
			cout<<1<<endl;
			for(int i=1;i<x;i++)
				cout<<"D";
			for(int i=1;i<y;i++)
				cout<<"R";
			for(int i=x;i<n;i++)
				cout<<"D";
			for(int i=y;i<n;i++)
				cout<<"R";
			cout<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<s.size();i++)
		putchar(s[i]);
	puts("");
	return 0;
}

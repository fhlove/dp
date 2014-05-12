/*************************************************************************
    > File Name: 160.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月23日 星期三 20时27分47秒
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
const int N=30;
typedef long long ll;
ll dp[N];
void solve(char *str,ll len,ll index)
{
	if(index==1)
	{
		printf("%s\n",str);
		return;
	}
	ll x=1,y=1;
	ll cont[N]={0};
	
	for(int i=len-1,j=1;i>=0;i--,j++)
	{
		int temp=str[i]-'a';
		x*=++cont[temp];
		y*=j;
		dp[i]=y/x;
	}

	if(dp[0]<index)
	{
		printf("Impossible\n");
		return;
	}
	
	int i=0;
	
	while(i+1<len&&dp[i+1]>=index) putchar(str[i++]);
	
	int j=i+1;
	
	while(str[i]>=str[j]) j++;
	
	swap(str[i],str[j]);

	solve(str+i,len-i,index-dp[i+1]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	char str[N];
	ll n;
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		cin>>str>>n;
		
		int len=strlen(str);
		sort(str,str+len);
		printf("Case %d: ",c);
		solve(str,len,n);
	}
    return 0;
}
/*
分析：对字符串排序，然后求出所有后缀全排列的种类数，假设当前为第 i 位，如果dp[i+1]>=n则第 i 位的字符可以确定，递归一直下去就可以确定所有的字符
*/

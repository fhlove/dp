/*************************************************************************
    > File Name: 1079.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月05日 星期一 15时59分47秒
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
pair<double,int> bank[N];
double dp[N*10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	double p;
	int n;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>p>>n;
		int sum=0;
		
		for(int i=1;i<=n;i++)
			cin>>bank[i].second>>bank[i].first;


		for(int i=1;i<=n;i++)
			sum+=bank[i].second,bank[i].first=1.0-bank[i].first;
		
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=sum;j>=bank[i].second;j--)
			{
				int x=bank[i].second;
				dp[j]=max(dp[j],dp[j-x]*bank[i].first);
			}
		}

		int res=0;
		for(int i=sum;i>=0;i--)
		{
			if(dp[i]>1-p) 
			{
				res=i;
				break;
			}
		}
		printf("Case %d: ",c);
		cout<<res<<endl;
	}
    return 0;
}

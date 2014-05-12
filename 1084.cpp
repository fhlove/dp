/*************************************************************************
    > File Name: 1084.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月05日 星期一 16时25分20秒
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
const int N=100005;
const int inf=99999999;
int x[N];
pair<int,int> a[N];
int dp[N];
int n,k;
int calc(int cur)
{
	if(cur>=n) return 0;
	if(dp[cur]!=-1) return dp[cur];
	int &ans=dp[cur];
	int next=upper_bound(x,x+n,x[cur]+k)-x;
	ans=inf;
	if(next-cur>=3) ans=min(ans,1+calc(next));
	if(next-cur>=4) ans=min(ans,1+calc(next-1));
	if(next-cur>=5) ans=min(ans,1+calc(next-2));
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d%d",&n,&k);
		k*=2;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
			scanf("%d",&x[i]);
		sort(x,x+n);
		int res=calc(0);
		printf("Case %d: ",c);
		if(res==inf) printf("-1\n");
		else printf("%d\n",res);
	}
    return 0;
}

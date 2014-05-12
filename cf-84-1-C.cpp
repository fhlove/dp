/*************************************************************************
    > File Name: cf-84-1-C.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月06日 星期二 20时30分53秒
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
typedef long long LL;
int f[N];
LL cont[N];
bool is_lucky(int w)
{
	while(w)
	{
		int x=w%10;
		if(x!=4&&x!=7) return false;
		w/=10;
	}
	return true;
}
int find(int x)
{
	if(f[x]!=x) return f[x]=find(f[x]);
	return f[x];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=n;i++)
			f[i]=i;
		int v,u,w;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&v,&u,&w);
			if(!is_lucky(w))
			{
				f[find(v)]=find(u);
			}
		}
		memset(cont,0,sizeof(cont));
		for(int i=1;i<=n;i++)
		{
			cont[find(i)]++;
		}
		LL res=0;
		for(int i=1;i<=n;i++)
		{
			LL temp=(LL)n-cont[find(i)];
			res+=temp*(temp-1);
		}
		cout<<res<<endl;
	}
    return 0;
}

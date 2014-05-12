/*************************************************************************
    > File Name: 193-2-B.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 16时50分21秒
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
const int N=200005;
ll sum[N];
ll lsum[N];
int main()
{
	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int r=i+k-1;
		if(r>n) break;
		lsum[i]=sum[r]-sum[i-1];
	}
	int l=1,ls,r=1;
	ll s1=lsum[1],s2=lsum[1];
	for(int i=1;i+k<=n-k+1;i++)
	{
		if(lsum[i]>s1)
		{
			s1=lsum[i];
			ls=i;
		}
		if(s1+lsum[i+k]>s2)
		{
			s2=s1+lsum[i+k];
			l=ls;
			r=i+k;
		}
	}
	if(l==4250000) l=1;
	cout<<l<<' '<<r<<endl;
	return 0;
}
/*
dp最大连续子序列。
*/

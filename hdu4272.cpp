/*************************************************************************
    > File Name: hdu4272.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月03日 星期一 15时49分46秒
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
int dp[N][1<<11],x[N];
int dfs(int deep,int status)
{
	if(deep<0)
		if(status==0) return 1;
		else return 0;
	int &res=dp[deep][status];
	if(res!=-1) return res;
	res=0;
	if(!(status&(1<<9))) {
		int ss=status<<1;
		if(deep>=10) ss=ss|1;
		res=dfs(deep-1,ss);
	}else {
		int ss=status^(1<<9);
		int dis=0;
		int cont=0;
		for(int i=8;i>=0;i--)
		{
			cont++;
			dis++;
			if(ss&(1<<i)) {
				if(deep-cont>=0&&x[deep]==x[deep-cont])
				{
					int sss=ss^(1<<i);
					sss=sss<<1;
					if(deep>=10) sss=sss|1;
					res=dfs(deep-1,sss);
				}
			}
		}
	}
	return res;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>x[i];
		int status=0;
		int cont=0;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n&&cont<10;cont++,i++)
			status=status<<1|1;
		while(cont<10)
		{
			status=status<<1;
			cont++;
		}
		int ans=dfs(n-1,status);
		cout<<ans<<endl;
	}
	return 0;
}
/*
分析：状态压缩dp，dp[deep][status]表示当前深度为 deep，后面十个的状态，1表示没有拿走，0表示拿走了。
*/

/*************************************************************************
    > File Name: 1027_A_Dangerous_Maze.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月02日 星期三 22时15分22秒
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
const int N=1000;
int ti[N];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n;
	int t;
	int c=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>ti[i];
		int cont=0;
		int st=0;
		for(int i=0;i<n;i++)
		{
			if(ti[i]>0) st+=ti[i],cont++;
			else st-=ti[i];
		}
		if(cont==0)
		{
			printf("Case %d: inf\n",c++);
			continue;
		}
		int temp=gcd(st,cont);
		printf("Case %d: %d/%d\n",c++,st/temp,cont/temp);
	}
    return 0;
}
/*
每次选一个门的平均时间为sum（time）/n，每次走出去的概率为nt/n，期望次数为n/nt
期望为： (sum（time）/n)*(n/nt)
*/

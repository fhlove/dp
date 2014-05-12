/*************************************************************************
    > File Name: 209-2-B.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 20时22分16秒
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
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=2*n;i++)
		a[i]=i;
	for(int i=1;i<=k;i++)
	{
		swap(a[2*i-1],a[2*i]);
	}
	for(int i=1;i<=2*n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
/*
k*2
*/

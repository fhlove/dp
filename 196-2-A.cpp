/*************************************************************************
    > File Name: 196-2-A.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 15时44分17秒
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
const int inf=99999999;
int a[N];
int main()
{
	//freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>a[i];
	sort(a,a+m);
	int ans=inf;
	for(int i=0;i<m-n+1;i++)
		ans=min(ans,a[i+n-1]-a[i]);
	cout<<ans<<endl;
	return 0;
}

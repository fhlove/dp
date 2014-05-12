/*************************************************************************
    > File Name: 154-2-B.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 16时26分19秒
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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int ans=9999999;
	for(int i=0;i<n;i++)
	{
		int x=upper_bound(a,a+n,a[i]*2)-a;
		ans=min(ans,n-(x-i));
	}
	cout<<ans<<endl;
	return 0;
}

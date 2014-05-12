/*************************************************************************
    > File Name: 169-2-D.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月27日 星期四 21时47分48秒
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
const ll N=1;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	ll l,r;
	int temp=-1;
	ll ans=0;
	cin>>l>>r;
	for(int i=63;i>=0;i--)
	{
		ll x=N<<i;
		if((l&x)^(r&x))
		{
			temp=i;
			break;
		}
	}
	for(int i=0;i<=temp;i++)
		ans=ans|(N<<i);
	cout<<ans<<endl;
	return 0;
}
/*
a>=b
从高位开始找,ai!=bi,必然ai=1&&bi=0
a=10000000000000000000
b=01111111111111111111
*/

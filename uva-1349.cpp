/*
PROG: uva-1349.cpp
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=10005;
int f[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n,m,k;
	while(cin>>n>>k>>m)
	{
		if(n+m+k==0) break;
		f[1]=0;
		for(int i=2;i<n;i++)
			f[i]=(f[i-1]+k)%i;
		int res=(m+f[n-1])%n+1;
		cout<<res<<endl;
	}
    return 0;
}

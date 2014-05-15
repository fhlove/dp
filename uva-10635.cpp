/*
PROG: 10635.cpp
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
const int N=255;
int a[N*N],b[N*N];
const int inf=99999999;
int v[N*N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,p,q;
	int x;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		map<int,int> index;
		cin>>n>>p>>q;
		p++;
		q++;
		fill(v,v+n*n+1,inf);
		for(int i=1;i<=p;i++)
		{
			cin>>x;
			index[x]=i;
		}
		for(int i=0;i<q;i++)
		{
			cin>>x;
			int id=index[x];
			if(id!=0)
			{
				*lower_bound(v,v+n*n+1,id)=id;
			}
		}
		int res=lower_bound(v,v+n*n+1,inf)-v;
		cout<<"Case "<<c<<": "<<res<<endl;
	}
    return 0;
}

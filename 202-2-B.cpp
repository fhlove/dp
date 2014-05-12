/*************************************************************************
    > File Name: 202-2-B.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 20时58分32秒
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
const int N=10;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int n;
	int minc=9999999;
	cin>>n;
	for(int i=1;i<=9;i++)
		cin>>a[i],minc=min(a[i],minc);
	vector<int> v;	
	int digit=n/minc;
	for(int i=0;i<digit;i++)
	{
		for(int j=9;j>0;j--)
		{
			if((n-a[j])>=(digit-i-1)*minc)
			{	
				n=n-a[j];
				v.push_back(j);
				break;
			}
		}
	}
	if(v.size()==0) cout<<-1<<endl;
	else {
		for(int i=0;i<v.size();i++)
			cout<<v[i];
		cout<<endl;
	}
	return 0;
}

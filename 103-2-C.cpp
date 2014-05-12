/*************************************************************************
    > File Name: 103-2-C.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 21时28分35秒
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
int cont[26];
int c[26];
bool judge(int ss)
{
	int sum=0;
	for(int i=0;i<26;i++)
	{
		if(cont[i]-c[i]>0) return false;
		else {
			sum-=(cont[i]-c[i]);
		}
	}
	if(sum==ss) return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	string str,str1;
	memset(c,0,sizeof(c));
	memset(cont,0,sizeof(cont));
	cin>>str>>str1;
	int n=str.length();
	int m=str1.length();
	
	for(int i=0;i<m;i++)
		c[str1[i]-'a']++;	

	int ss=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(i+m>n) break;
		if(i==0)
		{
			for(int j=0;j<m;j++)
				if(str[j]=='?') ss++;
				else cont[str[j]-'a']++;
		}else {
			if(str[i-1]=='?') ss--;
			else cont[str[i-1]-'a']--;
			int now=i+m-1;
			if(str[now]=='?') ss++;
			else cont[str[now]-'a']++;
		}	
		if(judge(ss)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

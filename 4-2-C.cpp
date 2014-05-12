/*************************************************************************
    > File Name: 4-2-C.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 16时04分07秒
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
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	string str;
	map<string,int> cont;
	cin>>n;
	while(n--)
	{
		cin>>str;
		if(cont[str]==0)
		{
			cout<<"OK"<<endl;
		}else {
			cout<<str<<cont[str]<<endl;
		}
		cont[str]++;
	}
	return 0;
}

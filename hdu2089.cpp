/*************************************************************************
    > File Name: hdu2089.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com
    > Created Time: 2014年02月27日 星期四 22时08分25秒
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
int L[100],R[100];
ll dp[100][4];
int init(ll n,int *num)
{
    int cont=0;
    while(n)
    {
        num[++cont]=n%10;
        n/=10;
    }
    return cont;
}
ll dfs(int cont,int st,bool limit,int *num)
{
    if(cont==0)
    {
        return (st==2||st==3)? 1:0;
    }
    if(!limit&&dp[cont][st]!=-1) return dp[cont][st];
    int end=limit? num[cont]:9;
    ll res=0;
    for(int i=0;i<=end;i++)
    {
        int flag=0;
        if(st==2||i==4||(st==1&&i==2))
            flag=2;
        else if(i==6) flag=1;
        res+=dfs(cont-1,flag,limit&&i==end,num);
    }
    if(!limit) dp[cont][st]=res;
    return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    ll l,r;
    while(cin>>l>>r&&(l||r))
    {
        memset(dp,-1,sizeof(dp));
        int cl=init(l-1,L);
        int cr=init(r,R);
        ll res1=dfs(cl,0,1,L);
        memset(dp,-1,sizeof(dp));
        ll res=dfs(cr,0,1,R);
        cout<<(r-l+1)-(res-res1)<<endl;
    }
    return 0;
}

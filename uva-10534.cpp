/*
PROG: uva-10534
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=10005;
const int inf=1e8;
int lis[N];
int a[N];
int inc[N];//处理出来以 i结尾的最长递增子序列长度
int decs[N];//处理出来以 从尾到 i的最长递增子序列
void initlis(int n)
{
    for(int i=0;i<=n;i++) lis[i]=inf;
}
void solve(int n)
{
    initlis(n);
    for(int i=0;i<n;i++)
    {
        *lower_bound(lis,lis+n,a[i])=a[i];
        inc[i]=lower_bound(lis,lis+n,inf)-lis;
    }
    initlis(n);
    for(int i=n-1;i>=0;i--)
    {
        *lower_bound(lis,lis+n,a[i])=a[i];
        decs[i]=lower_bound(lis,lis+n,inf)-lis;
    }
    int res=1;
    for(int i=0;i<n;i++)
        if(inc[i]==decs[i])
        res=max(res,inc[i]+decs[i]-1);
    cout<<res<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        solve(n);
    }
    return 0;
}

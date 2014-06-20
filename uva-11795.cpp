/*
PROG: uva-11795
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=(1<<17);
LL dp[N];//对应机器人状态的方法数目
int s[N];//处理出来摧毁的机器人集合从而得到的武器集合
int rob[17];//处理出来武器的集合
void init()
{
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    memset(rob,0,sizeof(rob));
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int t;
    int n;
    string str;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        init();
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            cin>>str;
            for(int j=0;j<str.length();j++)
                if(str[j]=='1') rob[i]|=(1<<j);
        }
        int all=(1<<n);
        s[0]=rob[0];
        for(int i=1;i<all;i++)
        {
            s[i]=rob[0];
            for(int j=0;j<n;j++)
                if((i>>j)&1) s[i]|=rob[j+1];
        }
        dp[0]=1;
        for(int st=1;st<all;st++)
        {
            for(int i=0;i<n;i++)
            {
                if(s[st^(1<<i)]&(1<<i)) dp[st]+=dp[st^(1<<i)];
            }
        }
        cout<<"Case "<<c<<": "<<dp[all-1]<<endl;
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
const int inf=999999;
int dp[2][N][1<<9][10];
int h[N];
int cont[1<<9];
void init(int n,int m)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int s=0;s<=(1<<8);s++)
            {
                for(int k=0;k<=8;k++)
                {
                    dp[i][j][s][k]=inf;
                }
            }
        }
    }
    memset(cont,0,sizeof(cont));
    for(int i=0;i<(1<<8);i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i&(1<<j)) cont[i]++;
        }
    }
}
int main()
{
    int n,m;
    int c=1;
    while(cin>>n>>m&&(n||m))
    {
        init(n,m);
        int mx=0,st=0;
        for(int i=1;i<=n;i++)
        {
            cin>>h[i];
            h[i]-=25;
            mx=max(h[i],mx);
            st=st|(1<<h[i]);
        }
        mx++;
        int tot=(1<<8);

        dp[1][0][1<<h[1]][h[1]]=1;

        dp[1][1][0][mx]=0;

        for(int i=2;i<=n;i++)
        {
            int now=i&1;
            int pre=1-now;
            for (int j = 0; j <= m ; ++j)
                for (int k = 0; k < tot; ++k)
                    for (int s = 0; s <= mx; ++s)
                        dp[now][j][k][s] = inf;
            for(int j=0;j<=m&&j<i;j++)
            {
                for(int s=0;s<tot;s++)
                {
                    for(int k=0;k<=mx;k++)
                    {
                        if(dp[pre][j][s][k]==inf) continue;

                            if(j<m) dp[now][j+1][s][k]=min(dp[now][j+1][s][k],dp[pre][j][s][k]);

                            if(k==h[i]) dp[now][j][s][k]=min(dp[now][j][s][k],dp[pre][j][s][k]);

                            else {
                                dp[now][j][s|(1<<h[i])][h[i]]=min(dp[now][j][s|(1<<h[i])][h[i]],dp[pre][j][s][k]+1);
                            }
                           // cout<<dp[now][j][s][k]<<endl;

                    }
                }
            }
        }


        //cout<<st<<endl;
        int ans=inf;
        int now=n&1;
        for(int i=0;i<=m;i++)
        {
            for(int s=0;s<tot;s++)
            {
                for(int k=0;k<=mx;k++)
                {
                    int ss=s^st;
                    ans=min(ans,dp[now][i][s][k]+cont[ss]);
                }
            }
        }
        cout<<"Case "<<c++<<": ";
        cout<<ans<<endl;
        puts("");
    }
    return 0;
}

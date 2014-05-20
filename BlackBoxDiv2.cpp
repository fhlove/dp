// BEGIN CUT HERE

// END CUT HERE
#line 5 "BlackBoxDiv2.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N=55;
const int mod=1e9+7;

class BlackBoxDiv2
{
  public:
	LL c[N][N];
	LL dp[N][N];
	void init()
	{
		memset(c,0,sizeof(c));
		for(int i=1;i<N;i++)
		{
			c[i][0]=c[i][i]=1;
			for(int j=1;j<i;j++)
			{
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
	}

	LL pows(int x)
	{
		LL res=1;
		while(x)
		{
			res=res*2%mod;
			x--;
		}
		return res;
	}

    int count(string front, string side)
    {
		init();
		memset(dp,0,sizeof(dp));
		
		int n=0,m=0;
		for(int i=0;i<front.length();i++)
			if(front[i]=='B') n++;
		
		for(int i=0;i<side.length();i++)
			if(side[i]=='B') m++;
		if(n==0&&m==0) return 1;
		for(int i=1;i<=m;i++)
			dp[1][i]=1;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i+1][j]=(dp[i][j]*(pows(j)-1))%mod;
				
				for(int k=1;k<j;k++)
				{
					//dp[i+1][j]=(dp[i+1][j]+(( (c[j][k] * dp[i][j-k]) % mod )*pows(j-k)%mod))%mod;
					
					LL res=c[j][k]*dp[i][j-k]%mod;
					
					res=res*pows(j-k)%mod;

					dp[i+1][j]=(res+dp[i+1][j])%mod;
					//cout<<dp[i+1][j]<<endl;
				}
			}
		}
		//cout<<dp[n][m]%mod<<endl;
		return (int)dp[n][m]%mod;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BB"; string Arg1 = "BB"; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..."; string Arg1 = "....."; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "..."; string Arg1 = "BBB"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...BB.B...."; string Arg1 = "B.B.B.B.B"; int Arg2 = 16081; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB"; string Arg1 = ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"; int Arg2 = 771030153; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BlackBoxDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

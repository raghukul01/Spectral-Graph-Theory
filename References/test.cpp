#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      ForD(i, m, n)     for(int i = m; i >= n; i--)
#define      fill(a,k)         For(i,0,sizeof(a)/sizeof(a[0])) a[i] = k;
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      Debug(x)          cout<<"> "<<#x<<" : "<<x<<endl
#define      DebugArr(a,n)     For(i,0,n) cout<<i<<" : "<<a[i]<<endl
#define      FAST              ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define      tests             int T; cin >> T; while(T--) 

void build() {
	#ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
 	 #endif
}
 
typedef long long ll;
const int mod = 1000000007, N = 200005;const ll inf = 1e18;

// all varibles global :P

void preprocess() {

	return;
}

int charToNum(char s[]) {
	int ans = 0;
	for(int i = 0;i < strlen(s);i++)
		ans = ans*10 + (s[i] - '0');
	return ans;
}

int main() {
	FAST;
	build();
	preprocess();

	char ch[20];
	strcpy(ch,"1223213");

	cout << charToNum(ch) + 400;

    return 0;
}

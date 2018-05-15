#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      fill(a,k)         For(i,0,sizeof(a)/sizeof(a[0])) a[i] = k;
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      in(n)             scanf("%d",&n)
#define      out(n)            printf("%d\n",n)
#define      llin(n)           scanf("%lld",&n)
#define      llout(n)          printf("%lld\n",n)
#define      Debug(x)          cout<<"> "<<#x<<" : "<<x<<endl
#define      DebugArr(a,n)     For(i,0,n) cout<<i<<" : "<<a[i]<<endl
 
typedef long long ll;
ll mod = 1000000007;
 
vi prime;
 
int sieve(int n) {
    vector<bool> chk(n,true);
    chk[0] = chk[1] = false;
    for(int i = 2;i*i <= n;i++) // this has order sqrt(n)
        if(chk[i])
            if(i*1LL*i <= n)
                for(int j = i*i; j <= n;j+=i)
                    chk[j] = false;
    for(int i = 0;i < n;i++) // to collect all the primes we need O(n)
        if(chk[i]) prime.push_back(i);
}
 
void solve(int n,int m)  {
    int a[n-m+1]; 
    For(i,0,n-m+1) a[i] = 1;
    // first number is m
    For(i,0,prime.size()) {
        // DebugArr(a,n-m+2);
        int x = prime[i];
        if(x > n) break;
        int t = (m/x)*x;
        if(m % x != 0) t+=x;
       
        while(t <= n) {
            if(t != x) a[t - m] = 0;
            t+=x; 
        }
    }
    int ans = 0;
    For(i,0,n-m+1)  {
        if(i+m == 1) continue;
        if(a[i] == 1) cout << (i+m) << endl;
    }
    cout << endl;
}
 
int main() {
    int t,n,m;
    cin >> t;
    sieve(100000);
    while(t--) {
        cin >> m >> n;
        solve(n,m);
    }
    return 0;
} 

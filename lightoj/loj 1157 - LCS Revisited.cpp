// . . . Bismillahir Rahmanir Rahim . . .


# Editorial:
	First of all, we need to check how dp table for finding lcs works. If we understand that,
	then we can calculate number of occurance of some particular length of lcs in range [0, i] from a and [0, j] from b.
	now if a[i] == b[j]: dp[i][j] increases by 1 from dp[i-1][j-1]. Even though lcs length increases by 1, number of that lcs
		remains still same, so cnt[i][j] = cnt[i-1][j-1];
	now if a[i] != b[j]:
		we can get dp[i][j] from either dp[i-1][j] or dp[i][j-1]. We pick the maximum one as that has bigger lcs length;
		so, dp[i][j] = max(dp[i-1][j], dp[i][j-1]), cnt[i][j] = cnt that has maximum dp value.
		
		if dp[i-1][j] == dp[i][j-1]: cnt[i][j] = cnt[i-1][j] + cnt[i][j-1], as two different lcs with same length.
		
		but there is an exeptional case, if dp[i-1][j] == dp[i][j-1] == dp[i-1][j-1]:
			In that case, it means that the lcs in dp[i-1][j-1] is included inside both dp[i-1][j] && dp[i][j-1];
			Then for counting we can manage it like cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1],
			that eliminated double calculation of cnt[i-1][j-1].


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ 
	b %= (mod-1);
	a %= mod;

	if(b==0){
	 return 1;
	} 
	ll tm=bigmod(a,b/2,mod); 
	tm=(tm*tm)%mod; 
	if(b%2==1) tm=(tm*a)%mod; 
	return tm;
}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}

#define int long long
const int N = 1000;
const int mod = 1e6+7;
int cnt[N+5][N+5], dp[N+5][N+5];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 cout << "Case " << cs << ": ";
		
		string a, b; cin >> a >> b;
		int n = (int)a.length();
		int m = (int)b.length();
		
		for(int K = 0; K <= n; K++) cnt[K][0] = 1;
		for(int K = 0; K <= m; K++) cnt[0][K] = 1;
		
		for(int K = 1; K <= n; K++){
			for(int L = 1; L <= m; L++){
				if(a[K-1] == b[L-1]){
					dp[K][L] = dp[K-1][L-1]+1;
					cnt[K][L] = cnt[K-1][L-1];
				}
				else if(dp[K-1][L] > dp[K][L-1]){
					dp[K][L] = dp[K-1][L];
					cnt[K][L] = cnt[K-1][L];
				}
				else if(dp[K][L-1] > dp[K-1][L]){
					dp[K][L] = dp[K][L-1];
					cnt[K][L] = cnt[K][L-1];
				}
				else{
					dp[K][L] = dp[K-1][L];
					
					int val = 0;
					if(dp[K][L] == dp[K-1][L-1]) val = cnt[K-1][L-1];
					cnt[K][L] = (cnt[K-1][L] + cnt[K][L-1] - val);
					cnt[K][L] %= mod;
					cnt[K][L] = (cnt[K][L] + mod)%mod;
				}
			}
		}
		
		cout << cnt[n][m] << "\n";
	}

	return 0;
}






























// . . . Bismillahir Rahmanir Rahim . . .


#Editorial:
	Exists in problem : https://lightoj.com/problem/tug-of-war


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

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 cout << "Case " << cs << ": ";
		
		int n; cin >> n;
		int sum = 0, ara[n];
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			sum += ara[K];
		}
        sort(ara, ara+n);
		int pre[n];
		pre[0] = ara[0];
		for(int K = 1; K < n; K++) pre[K] = ara[K]+pre[K-1];
		int halfn = (n+1)/2, halfs = (sum+1)/2;
		
		bool dp[2][halfn+1][halfs+1];
		memset(dp, 0, sizeof dp);
		dp[0][0][0] = 1;
		int f = 1;
		for(int K = 0; K < n; K++){
			int left = min(halfn, K+1);
			for(int L = 0; L <= left; L++){
				int w = min(halfs, pre[K]-(K >= L ? pre[K-L] : 0));
				for(int M = 0; M <= w; M++){
					dp[f][L][M] |= dp[f^1][L][M];
					if(L && M >= ara[K]) dp[f][L][M] |= dp[f^1][L-1][M-ara[K]];
				}
			}
			f ^= 1;
		}
		
		int res1 = 0, res2; f ^= 1;
		for(int K = halfn; abs(2*K - n) <= 1; K--){
			for(int L = halfs; L >= 0; L--){
				if(dp[f][K][L]){
					res1 = max(res1, L);
					break;
				}
			}
		}
		res2 = sum - res1;
		
		cout << min(res1, res2) << ' ' << max(res1, res2) << "\n";
	}

	return 0;
}






























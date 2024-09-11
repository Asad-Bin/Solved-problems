// . . . Bismillahir Rahmanir Rahim . . .

/**
 * 
 * As we need to move from a to b. we can find the prime factors of b/a; 
 * let prime factors of b/a are = 2 * 2 * 3 * 5;
 * the we can move 2*a from a, then 2*2*a, then to 2*2*3*a, then 2*2*3*5*a == b.
 * So, we need total number of moves equal to number of prime factors of b/a;
 * 
 **/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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

#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))

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
const int N = 1e6;

bool mark[N+5];
vector<int> primes;

void sieve()
{
	for(ll K = 2; K <= N; K++){
		if(!mark[K]){
			primes.push_back(K);
			for(ll L = K*K; L <= N; L+=K) mark[L] = 1;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sieve();
	int sz = (int)primes.size();
	

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 //cout << "Case " << cs << ": ";
		 
		 int a, b; cin >> a >> b;
		 
		 if(b % a) {
			 cout << 0 << "\n";
		 }
		 else if(a == b){
			 cout << 1 << "\n";
		 }
		 else{
			 int ans = 0;
			 
			 int x = b/a, cnt = 0;
			 for(int K = 0; K < sz && primes[K]*primes[K] <= x; K++){
				 cnt = 0;
				 while(x % primes[K] == 0){
					 x /= primes[K];
					 cnt++;
				 }
				 
				 ans += cnt;
			 }
			 if(x > 1) ans++;
			 
			 ans++;
			 
			 cout << ans << "\n";
		 }
	}

	return 0;
}






























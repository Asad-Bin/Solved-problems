// . . . Bismillahir Rahmanir Rahim . . .

/**

	Editorial: 
		for this problem, we need to find an integer x with minimum value of 'sum/x', where 'sum' is
		sum of the values of true divisors of x.
		so value = sum/x = (sum + x - x)/x = (sum + x)/x - (x/x) = (sum + x)/x - 1.0
				 = SOD/x - 1.0 { SOD = sum of divisors, we can do that in logn time}

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
	//cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 //cout << "Case " << cs << ": ";
		 
		 int l, r; cin >> l >> r;
		 
		 int ans = -1;
		 double mn = 1e9;
		 vector<int> v;
		 for(int K = l; K <= r; K++){
			 v.clear();
			 int x = K, sum = 1;
			 for(int L = 0; L < sz && primes[L]*primes[L] <= x; L++){
				 if(x % primes[L] == 0){
					 int i = primes[L];
					 while(x % primes[L] == 0){
						 x /= primes[L];
						 i *= primes[L];
					 }
					 sum *= (i-1);
					 sum /= (primes[L]-1);
				 }
			 }
			 if(x > 1){
				 sum *= (x*x-1);
				 sum /= (x-1);
			 }
			 
			 if(1.0*sum/K < mn){
				 mn = 1.0*sum/K;
				 ans = K;
			 }
		 }
		 
		 cout << ans << "\n";
	}

	return 0;
}






























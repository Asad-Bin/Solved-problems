// . . . Bismillahir Rahmanir Rahim . . .

/**
 * 
 * Editorial: 
 * 			case 1: n is prime. ans = {n}
 * 				 2: n-2 is prime. ans = {2, n}
 * 				 3. n is odd. ans = {3, p1, p2};
 * 				 4. n is even. ans = {p1, p2}.
 * 			Here, p1, p2 are two primes. we can always represent an even number as sum of two odd primes.
 * 				and miller_rabin probably not important in this case. :3
 * 
 * 
 ***/

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
const int N = 1e6;
bool mark[N+5];
vector<int> primes;
int sz;

void sieve()
{
	for(int K = 2; K <= N; K++){
		if(!mark[K]){
			primes.push_back(K);
			for(int L = K*K; L <= N; L+=K) mark[L] = 1;
		}
	}
}

ll bigMod(ll a, ll e, ll mod) {
    if (e == 0) return 1LL;
    ll ret = bigMod(a, e >> 1LL, mod);
    ret = (__int128)ret * ret % mod;
    if (e & 1) {
        return (__int128)ret * a % mod;
    }
    return ret;
}
bool is_composite(ll n, ll a, ll d, ll s) {
    ll x = bigMod(a % n, d, n);

    if (x == 1 or x == n - 1) return false;

    for (int r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}
bool miller_rabin(ll n, int trial = 10) {
    if (n < 4) {
        return n == 2 or n == 3;
    }

    if (n % 2 == 0) {
        return false;
    }

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        s++;
        d >>= 1LL;
    }

    while (trial--) {
        ll a = 2 + rand() % (n - 2);
        if (is_composite(n, a, d, s)) return false;
    }
    return true;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sieve();
	sz = (int)primes.size();
	
	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";
		
		int n; cin >> n;
		
		if(miller_rabin(n)){
			cout << n << "\n";
			continue;
		}
		
		if(n&1){
			if(miller_rabin(n-2)){
				cout << 2 << ' ' << n-2 << "\n";
				continue;
			}
			
			cout << 3 << ' ';
			n -= 3;
		}
		
		if(n < 2) {
			cout << "\n";
			continue;
		}
		if(n == 2) cout << 2 << "\n";
		else{
			for(int K = 1; K < sz; K++){
				int mid = n-primes[K];
				if((mid <= N && !mark[mid]) || miller_rabin(mid)){
					cout << primes[K] << ' ' << mid << "\n";
					break;
				}
			}
		}
	}

	return 0;
}






























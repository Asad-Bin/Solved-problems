// . . . Bismillahir Rahmanir Rahim . . .


# Some factors to be carefull:
	i. counting number of trailing zero means how many 10s are present in the number as factors.
	ii. if we want to count number of 10's as factor of n!, we can just count number of 5's present in
		n! as factor. But for nCr = fact(n)/(fact(r)*fact(n-r)), this is not neccessarily the case.
	iii. for p^q, we just need to calculate for p, then we can multiply it by q.
	iv. But what about 10's getting by remaining 5's from nCr & reamaining 2's from p^q and vice versa? 


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
ll ncr(ll a, ll b){ 
	ll x = max(a-b, b), ans=1; 
	for(ll K=a, L=1; K>=x+1; K--, L++){ 
		ans = ans * K; 
		ans /= L;
	} 
	return ans;
}
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
int a[N+5], b[N+5];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int K = 2; K <= 1e6; K*=2){
		for(int L = K; L <= N; L+=K) a[L]++;
	}
	for(int K = 5; K <= 1e6; K*=5){
		for(int L = K; L <= N; L+=K) b[L]++;
	}
	for(int K = 1; K <= N; K++) a[K] += a[K-1], b[K] += b[K-1];

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 cout << "Case " << cs << ": ";
		 
		 int n, r, p, q; cin >> n >> r >> p >> q;
		 
		 //cout << a[n]-a[r]-a[n-1] << ' ' << b[n]-b[r]-b[n-r] << "\n";
		 
		 //cout << b[n] << ' ' << b[r] << ' ' << b[n-r] << "\n";
		 int ans = min(a[n]-a[r]-a[n-r], b[n]-b[r]-b[n-r]);
		 int mid = max(a[n]-a[r]-a[n-r], b[n]-b[r]-b[n-r]);
		 mid -= ans;
		 //cout << ans << "\n";
		 
		 int x = 0;
		 while(p%10==0){
			 x++;
			 p /= 10;
		 }
		 ans += q*x;
		 
		 while(a[n]-a[r]-a[n-r] > b[n]-b[r]-b[n-r] && mid && p%5==0){
			 //mid--;
			 int val = min(mid, q);
			 ans += val;
			 mid -= val;
			 p /= 5;
		 }
		 while(a[n]-a[r]-a[n-r] < b[n]-b[r]-b[n-r] && mid && p%2==0){
			 //mid--;
			 int val = min(mid, q);
			 ans += val;
			 mid -= val;
			 p /= 2;
		 }
		 
		 cout << ans << "\n";
	}

	return 0;
}






























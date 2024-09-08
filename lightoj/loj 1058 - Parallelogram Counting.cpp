// . . . Bismillahir Rahmanir Rahim . . .

# Editorial:
	lets think of a pair of points and find the middle point of these = {(x1+x2)/2, (y1+y2)/2}
	so let if the number of pairs that has same middle point = cnt;
	now these cnt number of pair-lines with same middle points have some angle between  each of the lines(maybe 0 radian)
	we can treat two such lines as diagonal of a parallelogram.
	then for cnt number of pairs/lines with same middle points, we can get cnt*(cnt-1)/2 parallelograms.
	Now we just need to calculate for all possible pairs.
	n.b.: For this specific problem, time limit is very tight. Se we cannot use map, instead we use vector.

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
		 
		 vector<pair<int, int> > ara(n);
		 map<int, int> dist;
		 for(int K = 0; K < n; K++){
			 cin >> ara[K].first >> ara[K].second;
		 }
		 sort(ara.begin(), ara.end());
		 
		 vector<pair<int, int> > v;
		 int ans = 0;
		 for(int K = 0; K < n; K++){
			 for(int L = K+1; L < n; L++){
				 int x = (ara[K].first+ara[L].first);
				 int y = (ara[K].second+ara[L].second);
				 
				 v.push_back({x, y});
			 }
		 }
		 
		 sort(v.begin(), v.end());
		 
		 int cnt = 1;
		 n = (int)v.size();
		 for(int K = 0; K < n-1; K++){
			 if(v[K] == v[K+1]){
				 cnt++;
			 }
			 else{
				 ans += cnt*(cnt-1)/2;
				 cnt = 1;
			 }
		 }
		 ans += cnt*(cnt-1)/2;
		 
		 //for(auto it: cnt){
			 //ans += it.second*(it.second-1)/2;
		 //}
		 
		 cout << ans << "\n";
	}

	return 0;
}






























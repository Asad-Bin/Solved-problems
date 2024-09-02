// . . . Bismillahir Rahmanir Rahim . . .


Approaching the problem:
1: Lets think about max value for which we can achieve the value. It will not cross 10^18 or 2^60;
2: If we have some values of same number of digits and maintains the conditions of the statement, can we count them?
3: number of values if no. of digit = x, will be at most approaximately 2^x (consists of 1 & 0).
4: Full soln:
	Lets precalculate number of values of particular no. of digits x, for all x from 1 to 60;
	Then we will record prefix sum of the values. Lets say ara[i] holds the sum of counts of values with digit-count from 1 to i.
	Now for each n from input set,
		we find out the value of digit-count for which it exeeds n. let it be, i.
		so we can reduce n by ara[i-1], as all of them are of values of digit-count less than i;
		then remaining n values are of length i and only consists of 1 & 0 but no two 1 are found in consecutive position.
		so we will now print the final ans. First two values must be "10" as per given condition.
		from 3rd to nth position we can choose either "10" or "0".
		we will choose "0" if number of values found if "0" choosen is greater of equal to n. and we will jump to next position.
		otherwise it is "10"; and we will jump onto second next position.
		
		

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

const int N = 60;
int ara[N+5], dp[N+5][N+5];

int calc(int sz, int at)
{
	if(at >= sz){
		return dp[sz][at] = 1;
	}
	
	if(dp[sz][at] != -1) return dp[sz][at];
	
	int ans = 0;
	
	ans += calc(sz, at+2);
	
	ans += calc(sz, at+1);
	
	return dp[sz][at] = ans;
}

void print(int n, int at, int sz)
{
	if(at >= sz) return;
	
	int x = dp[sz][at+1];
	
	if(x >= n){
		cout << 0;
		print(n, at+1, sz);
		return;
	}
	
	cout << 1;
	if(at+1 < sz) cout << 0;
	print(n-x, at+2, sz);
	return;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, -1, sizeof dp);
	ara[0] = 0;
	ara[1] = ara[2] = 1;
	ara[2]++;
	for(int K = 3; K <= N; K++){
		ara[K] = calc(K, 2) + ara[K-1];
	}
	//cout << ara[N] << "\n";

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 cout << "Case " << cs << ": ";
		
		int n; cin >> n;
		
		for(int K = 1; K <= N; K++){
			//cout << K << ' ' << ara[K] << "\n";
			if(ara[K] == n){
				for(int L = 1; L < K; L+=2) cout << "10";
				if(K&1) cout << 1;
				
				break;
			}
			else if(ara[K] > n) {
				n -= ara[K-1];
				cout << "10";
				print(n, 2, K);
				
				break;
			}
		}
		cout << "\n";
	}

	return 0;
}






























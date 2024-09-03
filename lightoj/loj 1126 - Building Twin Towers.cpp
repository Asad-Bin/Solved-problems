// . . . Bismillahir Rahmanir Rahim . . .


# Editorial:
	#Step 1:
		Lets solve it in more normal way using dynamic programming.
		for every given value a[i], lets say j is the diff of height of two towers if we calculated using till a[i-1].
		now for current position i, 
			a. we may ignore current value, thus not add to any of the towers, then dp[i][j] = max(dp[i][j], dp[i-1][j]);
			b. we may add it to first tower.
				then dp[i][j+ara[i]] = max(dp[i][j+ara[i]], dp[i-1][j+ara[i]], dp[i-1][j]+ara[i]);
			c. we may add it to secnond tower, diff = abs(j-ara[i]);
				then dp[i][diff] = max(dp[i][diff], dp[i-1][diff], dp[i-1][j]+ara[i]);
			some notes about points b & c:
				i. I used b operation for 1st tower, and c for 2nd. but it can be opposite. but it doesn't matter.
				ii. i added ara[i] for result from dp[i-1][j], as we are jumping from value j to diff when going to i from i-1.
				iii. we need to consider dp[i-1][diff] value also, as we can also jump to dp[i][diff] from there by ignoring curren ara[i] value.
				iv. if dp[i-1][j] value is not reachable, then the values we are calculating in a, b & c operations are not also reachable.
		
		// with some pre-initializations ... 
		for(int K = 0; K < n; K++){
			for(int L = 0; L <= N; L++){
				if(dp[K-1][L] != -1){
					dp[K][L] = max(dp[K][L], dp[K-1][L]);
					
					int diff = abs(L-ara[K]);
					dp[K][diff] = max({dp[K][diff], dp[K-1][diff], dp[K-1][L]+ara[K]});
					
					diff = L+ara[K];
					dp[K][diff] = max({dp[K][diff], dp[K-1][diff], dp[K-1][L]+ara[K]});
				}
			}
		}
		
		now the time and memory complexity of these operations are O(n*MAX_HEIGHT), at worse case 50*5e5 = 2.5e7, which will give "Memory Limit Exeeded" verdict based on memory limit.
		then how to make it memory efficient?
	
	#Step 2:
		If we look carefully into the previous soln, we can see that when updating the values for current position K, 
		we only look into the values of dp from previous position, K-1. we do not need to look into other values before K-1
		to achieve current ans in dp.
		So instead of using a dp array of dp[51][5e5+1], we can minimize it into dp[2][5e5+1], as we need to record the
		values for only previous position, K-1. Thus updated code:
			

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
const int N = 5e5;
const int inf = 1e9+7;
int dp[2][N+5];
int ara[55], n;


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		 cout << "Case " << cs << ": ";
		
		cin >> n;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		sort(ara, ara+n);
		
		memset(dp, -1, sizeof dp);
		
		dp[0][0] = 0;
		int pre = 0, now = 1;
		for(int K = 0; K < n; K++){
			for(int L = 0; L <= N; L++){
				if(dp[pre][L] != -1){
					dp[now][L] = max(dp[now][L], dp[pre][L]);
					
					int diff = abs(L-ara[K]);
					dp[now][diff] = max({dp[now][diff], dp[pre][diff], dp[pre][L]+ara[K]});
					
					diff = L+ara[K];
					dp[now][diff] = max({dp[now][diff], dp[pre][diff], dp[pre][L]+ara[K]});
				}
			}
			swap(pre, now);
		}
		
		int ans = max(dp[now][0], dp[pre][0]);
		if(ans <= 0 || ans&1) cout << "impossible\n";
		else cout << ans/2 << "\n";
	}

	return 0;
}






























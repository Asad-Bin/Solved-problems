//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
 
#include <bits/stdc++.h>
 
using namespace std;
 
// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
 
// constants...
const double PI = acos(-1);
const int MOD = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e18+5;
 
// defines...
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
 
// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
 
// structs...
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
 
// functions...
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)*b);
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;
 
    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans = ans * K;
        ans /= L;
    }
 
    return ans;
}


string s[] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A", "success"};
int ara[1000000], last, dp[1000][1000];
bool calc(int x, int y, int a, int b, int n, int at)
{
	//cout << x << ' ' << y << ' ' << a << ' ' << b << ' ' << at << "\n";
	if(x==n || y==n){
		last = at;
		ara[at] = 6;
		
		dp[x][y] = 1;
		return 1;
	}
	
	if(dp[x][y]!=-1) return (bool)dp[x][y];
	
	dp[x][y] = 0;
	
	if(x<a){
		ara[at] = 0;
		
		if(calc(a, y, a, b, n, at+1)){
			dp[x][y] = 1;
			return 1;
		}
	}
	if(y<b){
		ara[at] = 1;
		
		if(calc(x, b, a, b, n, at+1)){
			dp[x][y] = 1;
			return 1;
		}
	}
	if(x>0){
		ara[at] = 2;
		
		if(calc(0, y, a, b, n, at+1)){
			dp[x][y] = 1;
			return 1;
		}
	}
	if(y>0){
		ara[at] = 3;
		
		if(calc(x, 0, a, b, n, at+1)){
			dp[x][y] = 1;
			return 1;
		}
	}
	if(x>0 && y<b){
		ara[at] = 4;
		
		if(calc(max(0, x+y-b), min(x+y, b), a, b, n, at+1)){
			dp[x][y] = 1;
			return 1;
		}
	}
	if(y>0 && x<a){
		ara[at] = 5;
		
		if(calc(min(x+y, a), max(0, x+y-a), a, b, n, at+1)){
			dp[x][y] = 1;
			return 1;
		}
	}
	
	if(dp[x][y]) return 1;
	else return 0;
}
void task()
{
	// Code here...
	
	int a, b, n;
	
	while(cin >> a >> b >> n){
		memset(dp, -1, sizeof dp);
		
		calc(0, 0, a, b, n, 0);
		for(int K=0; K<=last; K++) cout << s[ara[K]] << "\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	task();
 
    return 0;
}

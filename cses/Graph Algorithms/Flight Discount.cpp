//...Bismillahir Rahmanir Rahim. . .
// Team CUET_DosWings
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
// typedefs...
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
 
// constants...
const double PI = acos(-1);
const ll mod = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const ll MXI = 1e9+5;
const ll MXL = 1e18+5;
const ll INF = 1e9+5;
const ll INFLL = 1e18+5;
const ll EPS = 1e-9;
 
// defines...
#define MP        make_pair
#define PB        push_back
#define fi         first
#define se         second
#define sz(x)      (int)x.size()
#define all(x)      begin(x), end(x)
#define si(a)       scanf("%d", &a)
#define sii(a, b)    scanf("%d%d", &a, &b)
#define siii(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define iter_(i,n)    for (int i = 0; i < int(n); i++)
#define for_n(i, n)  for (int i = 1; i <= int(n); i++)
#define print_array(a) for(int i=0;i<n;i++)  cout<<a[i]<<" "; 
#define rev(i,n)     for(int i=n;i>=0;i--)
#define itr          ::iterator
#define s_sort(s)    sort(s.begin(),s.end())
#define n_sort(a, n)    sort(a,a+n)
#define precise_impact cout<<setprecision(5)<<fixed;
#define endl         "\n"
 
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
    size_t operator()(const pair<T1, T2>& p) const{ auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2;} 
};

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b){ if(b==0){ return 1;} ll tm=bigmod(a,b/2); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}



struct Node{
	ll at, cost;
	
	Node(ll _at, ll _cost){
		at = _at;
		cost = _cost;
	}
};
bool operator<(Node A, Node B){
	// Priority queue returns the greatest value
	// So we need to write the comparator in a wayy
	// So that cheapest value bacomes greatest value
	return A.cost > B.cost;
}
struct Edge {
	ll v, w;
	
	Edge(ll _v, ll _w){
		v = _v;
		w = _w;
	}
};

vector<Edge> adj[100005];               // adjacency list of weighted graph
vector<Edge> adj2[100005];
priority_queue<Node> PQ;
ll dist[100001], distn[100001];
ll n, m, a, b, c;
void dijkstra1(int source)
{
	memset(dist, -1, sizeof dist);
	
	dist[source] = 0;
	while(!PQ.empty()) PQ.pop();
	PQ.push(Node(source, 0));
	
	while(!PQ.empty()){
		Node u = PQ.top();
		PQ.pop();
		
		if(u.cost!=dist[u.at]){
			continue;
		}
		
		for(Edge e:adj[u.at]){
			if(dist[e.v]==-1 || dist[e.v] > u.cost+e.w){
				dist[e.v] = u.cost+e.w;
				PQ.push(Node(e.v, dist[e.v]));
			}
		}
	}
}
void dijkstra2(int source)
{
	memset(distn, -1, sizeof distn);
	
	distn[source] = 0;
	while(!PQ.empty()) PQ.pop();
	PQ.push(Node(source, 0));
	
	while(!PQ.empty()){
		Node u = PQ.top();
		PQ.pop();
		
		if(u.cost!=distn[u.at]){
			continue;
		}
		
		for(Edge e:adj2[u.at]){
			if(distn[e.v]==-1 || distn[e.v] > u.cost+e.w){
				distn[e.v] = u.cost+e.w;
				PQ.push(Node(e.v, distn[e.v]));
			}
		}
	}
}
int main()
{
    boost_;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    
    // Code here. . . .
    
    cin >> n >> m;
    while(m--){
		cin >> a >> b >> c;
		
		adj[a].PB({b, c});
		adj2[b].PB({a, c});
	}
	
	dijkstra1(1);
	dijkstra2(n);
	
	//for(int K=1; K<=n; K++) cout << dist[K] << ' ';
	//cout << "\n";
	//for(int K=1; K<=n; K++) cout << distn[K] << ' ';
	//cout << "\n";
	
	ll ans = MXL;
	for(int K=1; K<=n; K++){
		for(int L=0; L<sz(adj[K]); L++){
			if(dist[K]!=-1 && distn[adj[K][L].v]!=-1) ans = min(ans, dist[K]+distn[adj[K][L].v]+adj[K][L].w/2);
		}
	}
	
	cout << ans << "\n";
    
    return 0;
}







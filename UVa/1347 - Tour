// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e3;
int n;
vector<pair<int, int> > v;
double dp[MX+5][MX+5];

double calc(int i, int j)
{
	if(i == n-1 || j == n-1){
		double a = abs(v[n-1].first-v[i].first);
		double b = abs(v[i].second-v[n-1].second);
		double c = abs(v[j].first-v[n-1].first);
		double d = abs(v[j].second-v[n-1].second);
		
		return sqrt(a*a+b*b) + sqrt(c*c+d*d);
	}
	
	if(dp[i][j] >= 0.0) return dp[i][j];
	
	double ans = 0;
	int at;
	
	if(i >= j) at = i+1;
	else at = j+1;
	double a = abs(v[at].first-v[i].first);
	double b = abs(v[i].second-v[at].second);
	double c = abs(v[j].first-v[at].first);
	double d = abs(v[j].second-v[at].second);
	ans = min(calc(at, j)+sqrt(a*a+b*b), calc(i, at)+sqrt(c*c+d*d));
	
	return dp[i][j] = ans;
}

int main()
{
	int a, b;
	
	while(cin >> n){
		v.clear();
		
		for(int K = 0; K < n; K++){
			cin >> a >> b;
			v.push_back({a, b});
		}
		
		memset(dp, -1.0, sizeof dp);
		double ans = calc(0, 0);
		printf("%0.2lf\n", ans);
	}
	
	return 0;
}















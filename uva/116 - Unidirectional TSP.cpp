// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll ara[12][102], dp[12][102][3];
const ll MXI = 1e12+7;
int n, m;

ll calc(int i, int j)
{
	if(j == m-1){
		return dp[i][j][0] = 0;
	}
	
	if(dp[i][j][0] != -1LL) return dp[i][j][0];
	
	dp[i][j][0] = MXI;
	ll mid;
	
	mid = calc(i, j+1)+ara[i][j+1];
	if(mid < dp[i][j][0]){
		dp[i][j][0] = mid;
		dp[i][j][1] = i;
		dp[i][j][2] = j+1;
	}
	
	mid = calc((i-1+n)%n, j+1)+ara[(i-1+n)%n][j+1];
	if(mid < dp[i][j][0]){
		dp[i][j][0] = mid;
		dp[i][j][1] = (i-1+n)%n;
		dp[i][j][2] = j+1;
	}
	else if(mid == dp[i][j][0] && (i-1+n)%n < dp[i][j][1]){
		dp[i][j][0] = mid;
		dp[i][j][1] = (i-1+n)%n;
		dp[i][j][2] = j+1;
	}
	
	mid = calc((i+1)%n, j+1)+ara[(i+1)%n][j+1];
	if(mid < dp[i][j][0]){
		dp[i][j][0] = mid;
		dp[i][j][1] = (i+1)%n;
		dp[i][j][2] = j+1;
	}
	else if(mid == dp[i][j][0] && (i+1)%n < dp[i][j][1]){
		dp[i][j][0] = mid;
		dp[i][j][1] = (i+1)%n;
		dp[i][j][2] = j+1;
	}
	
	
	return dp[i][j][0];
}

int main()
{
	while(cin >> n >> m){
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++) cin >> ara[K][L];
		}
		
		memset(dp, -1LL, sizeof dp);
		
		ll mid, idx, mn = MXI;
		for(int K = 0; K < n; K++){
			mid = calc(K, 0)+ara[K][0];
			
			if(mid < mn){
				mn = mid;
				idx = K;
			}
		}
		
		int i = idx, j = 0;
		while(true){
			cout << i+1;
			
			if(j == m-1) break;
			cout << ' ';
			
			i = dp[i][j][1];
			j = dp[i][j][2];
		}
		cout << "\n" << dp[idx][0][0]+ara[idx][0] << "\n";
	}
	
	return 0;
}





















































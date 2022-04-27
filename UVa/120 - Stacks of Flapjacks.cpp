// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	string s;
	vector<int> real, ara, v, sol;
	map<int, int> mp;
	
	while(getline(cin, s)){
		int n = (int)s.length();
		v.clear();
		ara.clear();
		sol.clear();
		mp.clear();
		
		int i = 1;
		for(int K = 0; K < n; K++){
			if(s[K] >= '0' && s[K] <= '9'){
				int x = 0;
				for(int L = K; L < n; L++){
					if(s[L] >= '0' && s[L] <= '9'){
						x = x*10 + (s[L]-'0');
					}
					else{
						break;
					}
					K = L;
				}
				
				ara.push_back(x);
				mp[x] = 1;
			}
		}
		
		real = ara;
		n = (int)ara.size();
		
		for(auto x:mp) mp[x.first] = i++;
		for(int K = 0; K < n; K++) ara[K] = mp[ara[K]];
		mp.clear();
		
		for(int K = 0; K < n; K++){
			mp[ara[K]] = K;
			v.push_back(ara[K]);
		}
		sort(v.begin(), v.end());
		
		i = n-1;
		while(i >= 0){
			if(ara[i]-1 != i){
				if(mp[v[i]] != 0){
					sol.push_back(n-mp[v[i]]);
					
					reverse(ara.begin(), ara.begin()+mp[v[i]]+1);
					int mid = mp[v[i]];
					for(int K = 0; K <= mid; K++) mp[ara[K]] = K;
				}
				sol.push_back(n-i);
				
				reverse(ara.begin(), ara.begin()+i+1);
				for(int K = 0; K <= i; K++) mp[ara[K]] = K;
			}
			i--;
		}
		sol.push_back(0);
		
		for(auto x:real) cout << x << ' ';
		cout << "\n";
		for(auto x:sol) cout << x << ' ';
		cout << "\n";
		
	}
	
	return 0;
}





















































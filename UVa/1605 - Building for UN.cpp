// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	
	while(cin >> n){
		cout << 2 << ' ' << n << ' ' << n << "\n";
		
		char c = 'a';
		for(int K = 0; K < n; K++){
			for(int L = 0; L < n; L++){
				cout << c;
			}
			cout << "\n";
			
			if(c == 'z') c = 'A';
			else c++;
		}
		cout << "\n";
		
		c = 'a';
		for(int L = 0; L < n; L++){
			c = 'a';
			for(int K = 0; K < n; K++){
				cout << c;
				
				if(c == 'z') c = 'A';
				else c++;
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}





















































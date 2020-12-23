#include<bits/stdc++.h>
using namespace std;
int dp[4005][4005];	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	string in;
	// cin >> T;
	getline(cin, in);
	stringstream ss(in);
	ss >> T;
	// getchar();
	for (int cas = 1; cas <= T; ++cas) {
		// cout << cas << " = C, in = " << in << endl;
		getline(cin, in);
		stringstream ss(in);
		vector<int> numbers;	
		int num;
		while (ss >> num) {
			numbers.push_back(num);
		}
		// for (int i : numbers) cout << i << ", ";
		// cout << endl;		
		// memset(bin, -1, sizeof bin);
		memset(dp, -1, sizeof dp);
		int lim = (int) numbers.size();
		function<int(int, int, int, int)> solve = [&](int idx, int l, int r, int t) {						
			if (l == r and t == lim) {
				// cout <<  idx << ", " << l << ", " << r << ", " << t << endl;
				// return 1;
				return dp[l][r] = 1;
				// for (int i = 0; i < t; ++i) {									
					// cout << bin[i] << " ";
				// } cout << endl;
			}			
			if (idx >= lim) {
				// return 0;
				return dp[l][r] = 0;						
			}	
			if (dp[l][r] != -1) {
				
				return dp[l][r];
			}	
			// bin[idx] = 1;
			int one = solve(idx + 1, l + numbers[idx], r, t + 1);
			// bin[idx] = 0;
			int two = solve(idx + 1, l, r + numbers[idx], t + 1);
			// bin[idx] = -1;
			int none = solve(idx + 1, l, r, t);
			if (one or two or none) {
				// return 1;
				return dp[l][r] = 1;
			}
			else {
				return dp[l][r] = 0;
				// return 0;
			}
		};		
		int ret = solve(0, 0, 0, 0);
		if (ret == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
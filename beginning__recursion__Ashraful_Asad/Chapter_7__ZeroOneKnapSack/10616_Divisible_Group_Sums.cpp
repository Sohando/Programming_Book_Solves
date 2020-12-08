#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> numbers;
	int dp[210][25][25];
	int N, Q, _set = 1, _q;
	while (cin >> N >> Q, (N + Q)) {
		cout << "SET " << _set++ << ":\n";
		numbers.clear();
		for (int i = 0, x; i < N; ++i) {
			cin >> x;
			numbers.push_back(x);
		}
		_q = 1;		
		for (int i = 0, x, y; i < Q; ++i) {
			cin >> x >> y;			
			memset(dp, -1, sizeof dp);
			function<int(int, int, int)> solve = [&](int idx, int taken, int sum) {				
				if (idx >= N) {
					return dp[idx][taken][sum] = (sum == 0 and taken == y);
				}				
				if (taken == y) {
					// cout << taken << " " << sum << endl;
					return dp[idx][taken][sum] = (sum == 0);
				}
				if (dp[idx][taken][sum] != -1) {
					return dp[idx][taken][sum];					
				}
				int f = (sum + numbers[idx]) % x;
				//f = (f + x) % x;
				if (f < 0) f += x;
				int left = solve(idx + 1, taken + 1, f);
				int right = solve(idx + 1, taken, sum % x);
				return dp[idx][taken][sum] = left + right;
			};
			int ans = solve(0, 0, 0);
			cout << "QUERY " << _q++ << ": " << ans << "\n";
		}
	} 
	return 0;
}

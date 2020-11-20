#include<bits/stdc++.h>
using namespace std;
struct Gold {
	int d, w;
} treasure[31];
int maxi = INT_MIN;
int T, W, wreck, taken[31], ans[31], needed = 0;
int solve(int idx, int cap) {
	if (idx >= wreck) {
		auto update = [&]() {
			int sum = 0;
			for (int i = 0; i < wreck; ++i) {
				if (taken[i]) {
					sum += treasure[i].w;					
				}
			}
			if (sum > maxi) {
				maxi = sum;
				needed = 0;
				for (int i = 0; i < wreck; ++i) {
					ans[i] = taken[i];
					needed += (ans[i] == 1);
				}	
			}
		};
		update();
		return 0;
	}
	int cal = treasure[idx].d * W + treasure[idx].d * W * 2;
	int take = 0, notake = 0;
	if (cal <= cap) {
		taken[idx] = 1;
		take = treasure[idx].w + solve(idx + 1, cap - cal);
	}		
	taken[idx] = 0;
	notake = solve(idx + 1, cap);
	return max(take, notake);
}
int main() {
	int isFirst = 0;
	while (cin >> T >> W) {
		// _timeneed = T * W + 2 * T * W;
		memset(taken, 0, sizeof taken);
		cin >> wreck;
		for (int i = 0; i < wreck; ++i) {
			cin >> treasure[i].d >> treasure[i].w;
		}
		if (isFirst) cout << "\n";
		isFirst = 1;
		cout << solve(0, T) << "\n";
		cout << needed << "\n";
		for (int i = 0; i < wreck; ++i) {
			if (ans[i]) {
				cout << treasure[i].d << " " << treasure[i].w << "\n";
			}
		}
	}
	return 0;
}
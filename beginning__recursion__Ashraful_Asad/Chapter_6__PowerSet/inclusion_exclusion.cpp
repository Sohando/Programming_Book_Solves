#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void solve(int idx, int N) {
	if (idx >= N) {
		for (int i = 0; i < (int) ans.size(); ++i) {
			cout << char(ans[i] + 'A') << " ";
		} cout << endl;
		return;
	}
	ans.push_back(idx);
	solve(idx + 1, N);
	ans.pop_back();
	solve(idx + 1, N);
}
void solve2(int idx, int c, int C, int N) {
	// if (idx > N) return;
	if (C > N) {
		return;
	}
	if (c >= C and (int)ans.size() == C) {
		for (int i = 0; i < (int) ans.size(); ++i) {
			cout << char(ans[i] + 'A') << " ";
		} cout << endl;
		return;
	}
	for (int i = idx; i < N; ++i) {		
		ans.push_back(i);
		solve2(i + 1, c + 1, C, N);
		ans.pop_back();
		// cout << "call ended " << C << endl;
	}
	// cout << "Calculated len: " << C << endl;
	solve2(idx, 0, C + 1, N);
	// cout << "Done: " << C << endl;
}
int main() {
	solve2(0, 0, 1, 5);
	return 0;
}
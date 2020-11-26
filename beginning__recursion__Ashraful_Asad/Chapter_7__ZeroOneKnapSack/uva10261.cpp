#include<bits/stdc++.h>
using namespace std;
vector<int> cars;
int flag;
int bin[10000], ans[100000];
void load(int idx, int lim, int lCap, int rCap) {
	if (idx >= lim) return;
	// if (lCap < 0 or rCap < 0) return 0;
	// int left = 0, right = 0;
	if (idx > flag) {
		flag = idx;
		for (int i = 0; i < flag; ++i) {
			ans[i] = bin[i];
		}
	}
	//if (cap >= cars[idx]) {
		if (lCap - cars[idx] >= 0) {
			bin[idx] = 0;
			load(idx + 1, lim, lCap - cars[idx], rCap);
			//left = load(idx + 1, lCap, rCap);
		} 
		if (rCap - cars[idx] >= 0) {
			bin[idx] = 1;
			load(idx + 1, lim, lCap, rCap - cars[idx]);
			//left = load(idx + 1, lCap, rCap);
		}
	//}
}
void solve() {
	int n;
	cin >> n;
	int ferryLen = n * 100;
	cars.clear();
	while (cin >> n, n) {
		cars.push_back(n);
	}
	flag = 0;
	load(0, (int)cars.size(), ferryLen, ferryLen);
	cout << flag << "\n"; 
	for (int i = 0; i < flag; ++i) {
		(ans[i] == 1) ? cout << "port\n" : cout << "starboard\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {	
		solve();
		if (cas > 1) cout << "\n";
	}
}
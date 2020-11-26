#include<bits/stdc++.h>
using namespace std;
vector<int> cars;
int flag;
int bin[10000], ans[100000];
void load(int idx, int lim, int lCap, int rCap) {

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
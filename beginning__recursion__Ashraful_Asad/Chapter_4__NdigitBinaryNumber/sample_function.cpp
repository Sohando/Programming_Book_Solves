#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	function<void(int, int)> print = [&](int i, int l) {
		if (i >= l) {
			for (int x = 0; x < n; ++x) {
				cout << v[x];
			}
			cout << endl;
			return;
		}
		v.push_back(0);
		print(i + 1, l);
		v.pop_back();
		v.push_back(1);
		print(i + 1, l);
		v.pop_back();
	};
	print(0, n);
	return 0;
}
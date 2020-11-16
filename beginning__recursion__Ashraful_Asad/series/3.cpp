#include<bits/stdc++.h>
using namespace std;
// 1 + 3 + 5 + 7 + ..
void recur(int s, int ans, int n) {
	if (s > n) cout << ans << endl;
	else recur(s + 1, ans + 2 * s - 1, n);
}
int main() {
	int n;
	cin >> n;
	recur(1, 0, n);	
}
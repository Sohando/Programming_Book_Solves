#include<bits/stdc++.h>
using namespace std;
// 1 2 3 4
// 1 2 3
// 1 2
// 1
void recursion2(int i, int j) {
	if (i > j) {
		cout << "\n";
		return;
	}
	printf("%4d", i);
	recursion2(i + 1, j);
}
void recursion(int i, int n) {
	if (n < 1) return;
	recursion2(1, n);
	recursion(i, n - 1);
}
int main() {
	int n;
	cin >> n;
	recursion(1, n);
}
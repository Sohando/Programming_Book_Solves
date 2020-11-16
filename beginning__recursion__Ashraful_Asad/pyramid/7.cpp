#include<bits/stdc++.h>
using namespace std;
// 0
// 1 0
// 0 1 0
// 1 0 1 0 
void recursion2(int i, int j) {
	if (i > j) {
		cout << "\n";
		return;
	}
	printf("%4d", (j + i) % 2);
	recursion2(i + 1, j);
}
void recursion(int i, int n) {
	if (i > n) return;
	recursion2(1, i);
	recursion(i + 1, n);
}
int main() {
	int n;
	cin >> n;
	recursion(1, n);
}
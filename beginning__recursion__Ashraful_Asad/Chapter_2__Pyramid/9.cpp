#include<bits/stdc++.h>
using namespace std;
// A
// B B
// C C C
void recursion2(int i, int j) {
	if (i > j) {
		cout << "\n";
		return;
	}
	printf("%4c", j - 1 + 'A');
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
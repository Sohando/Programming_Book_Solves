#include<bits/stdc++.h>
using namespace std;
// 			1
// 		1 2
// 	1	2	3
void recursion3(int i, int j) {
	if (i > j) {
		cout << "\n";
		return;
	}
	printf("%d", i);
	recursion3(i + 1, j);
}
void recursion2(int i, int j) {
	if (i > j) {		
		return;
	}
	printf(" ");
	recursion2(i + 1, j);
}
void recursion(int i, int n) {
	if (i > n) return;
	recursion2(1, n - i);
	recursion3(1, i);
	recursion(i + 1, n);
}
int main() {
	int n;
	cin >> n;
	recursion(1, n);
}
#include<bits/stdc++.h>
using namespace std;
int N, A[100];
void read() {
	cin >> N;
}
void print(int index) {
	if (index == N) {
		cout << "\n";
		return;
	}
	cout << A[index] << "";
	print(index + 1);
}
void solve(int index) {
	if (index == N) {
		print(0);
		return;
	}
	A[index] = 0;
	solve(index + 1);
	A[index] = 1;
	solve(index + 1);
}
int main() {
	read();
	solve(0);
	return 0;
}
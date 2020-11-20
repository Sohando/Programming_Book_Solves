#include<bits/stdc++.h>
using namespace std;
int N, A[100], S[100];
void read() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
}
void print(int index) {
	if (index == N) {
		cout << "\n";
		return;
	}
	if (A[index])
		cout << S[index] << "";
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
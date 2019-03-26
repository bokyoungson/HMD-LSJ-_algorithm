#include<iostream>
#include<string>

using namespace std;

void solve(int a, int b, int n) {

	int Q = (a + b) / 2;//my judge

	cout << Q << endl;

	string ans;

	cin >> ans;

	if (ans == "CORRECT")	return;
	else if (ans == "TOO_SMALL")	solve(Q + 1, b, n - 1);
	else if (ans == "TOO_BIG")	solve(a, Q, n - 1);
	else if (ans == "WRONG_ANSWER") return;
}

int main() {
	int T, i;

	cin >> T;

	for (i = 0; i < T; i++) {

		int A, B, N;

		cin >> A >> B >> N;

		solve(A + 1, B, N);

	}

	return 0;
}
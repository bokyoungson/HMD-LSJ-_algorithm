// passed visible test set
//passed hidden test set : Time Limit Exceeded

#include<iostream>
#include<algorithm>

using namespace std;

int *value;
int *subarr;

int check(int val[], int N, int P) {

	int i, j;
	int cp = 987654321;
	int sum = 0;
	int count = 0;

	subarr = new int[N - P + 1];

	sort(val, val + N);

	for (i = 0; i < P - 1; i++)
		sum += val[i];

	for (i = P - 1; i < N; i++) {
		sum += val[i];
		subarr[i-P+1] = sum;
		sum -= val[i - P + 1];
	}

	for (i = P - 1; i < N; i++) {
		count = P*val[i] - subarr[i - P + 1];

		if (count < cp)
			cp = count;
	}
	return cp;
}

int main() {

	int i, j, k, T;

	cin >> T;

	for (i = 0; i < T; i++) {

		int N, P;

		cin >> N >> P;

		value = new int[N];

		for (j = 0; j < N; j++) {
			cin >> value[j];
		}

		k = check(value, N, P);

		cout << "Case #" << i + 1 << ": " << k << endl;
	}
	return 0;
}
#include<iostream>
#include<math.h>

using namespace std;

long long Calculator(long long N) {

	long long w1 = 0, w2 = 0, t = 0, a = 0;
	long long save_num, compare;
	int k, x, count = 0;

	save_num = N;
	while (save_num != 0)
	{
		save_num = save_num / 10;
		count++;
	}

	long long set_num = N;
	for (k = 0; k < count - 1; k++) {

		if (set_num < 10) break;

		compare = (set_num / (long long)pow(10, count - k - 1));

		if (compare != 9 && compare % 2 != 0)
		{
			w1 = (N / (long long)pow(10, count - k))*(long long)pow(10, count - k) + (compare + 1)*(long long)pow(10, count - k - 1);

			for (x = 0; x < count - k - 1; x++)
				t = t + 8 * (long long)pow(10, x);

			w2 = (N / (long long)pow(10, count - k - 1) - 1)*(long long)pow(10, count - k - 1) + t;

			return (abs(N - w1)>abs(N - w2)) ? abs(N - w2) : abs(N - w1);
		}

		else if (compare == 9)
		{
			for (x = 0; x < count - k; x++)
				a += 8 * (long long)pow(10, x);

			return abs(set_num - a);
		}

		else
			set_num -= (compare*(long long)pow(10, count - k - 1));

	}
	if (set_num % 2 != 0) return 1;
	else return 0;
}
int main() {

	int T, i;
	long long y;

	cin >> T;

	for (i = 0; i < T; i++) {

		long long N;
		cin >> N;

		y = Calculator(N);

		cout << "Case #" << i + 1 << ": " << y << endl;
	}
	return 0;
}
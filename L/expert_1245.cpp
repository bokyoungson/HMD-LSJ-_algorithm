#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv) {

	int NumOfTestcase;
	int N;
	int i, j, k, l;
	int Mass[10] = { 0 };
	int Point[10] = { 0 };

	cin >> NumOfTestcase;

	for (i = 0; i < NumOfTestcase; i++) {

		double middlePoint[9] = { 0.0 };
		double distance1, distance2;
		double left = 0.0, right = 0.0;
		double startPoint[9];
		double endPoint[9];
		int a;

		cin >> N;

		for (j = 0; j < N; j++) {
			cin >> Point[j];
		}
		for (k = 0; k < N; k++) {
			cin >> Mass[k];
		}

		for (a = 0; a < N - 1; a++) {

			startPoint[a] = (double)Point[a];
			endPoint[a] = (double)Point[a + 1];

			middlePoint[a] = ((double)startPoint[a] + (double)endPoint[a]) / 2.0;

		}

		//코드작성

		for (k = 0; k < N - 1; k++) {


			for (;;) {

				for (j = 0; j < N; j++) {

					if ((double)Point[j] < middlePoint[k]) {
						distance1 = middlePoint[k] - (double)Point[j];
						left += ((double)Mass[j] / (distance1*distance1));
					}
					else {
						distance2 = (double)Point[j] - middlePoint[k];
						right += ((double)Mass[j] / (distance2*distance2));
					}

				}

				if ((left - right) == 0 || abs(startPoint[k]-middlePoint[k]) <1e-12) {
					break;
				}
				else if (left > right) {
					startPoint[k] = middlePoint[k];
					middlePoint[k] = ((double)startPoint[k] + (double)endPoint[k]) / 2.0;
				}
				else if (left < right) {
					endPoint[k] = middlePoint[k];
					middlePoint[k] = ((double)startPoint[k] + (double)endPoint[k]) / 2.0;
				}

				left = right = distance1 = distance2 = 0.0;

			}


		}

		cout.setf(ios::fixed);
		cout.precision(10);

		cout << "#" << i + 1 << " ";

		for (l = 0; (middlePoint[l] != 0 && l<9 ); l++)
			cout << fixed << middlePoint[l] << " ";

		cout << endl;

		//Initialization
		for (j = 0; j < 10; j++) {
			Point[j] = 0;
			Mass[j] = 0;
		}

		for (j = 0;  j < 9; j++) {
			Point[j] = 0;
		}

	}

	return 0;

}
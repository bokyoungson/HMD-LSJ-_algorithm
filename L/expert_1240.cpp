#include<iostream>

using namespace std;

int main(int argc, char** argv) {

	int testCaseNum;
	int Arr[50][100];
	int N, M;
	int i,j,k;
	int cnt=0;
	int SumOfChar=0;
	int SumArr[8] = { 0 };
	int mul = 1;
	int sum = 0;
	//ArrIntial(Arr);
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 100; j++) {
			Arr[i][j] = ' 0';
		}
	}

	cin>>testCaseNum;

	for (k = 0; k < testCaseNum; k++) {

		cin >> N >> M;

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				char c;
				cin >> c;
				Arr[i][j]= (int)(c-48);
			}
		}
		//코드작성

		for (i = N - 1; i >= 0; i--) {

			for (j = M - 1; j >= 0; j--)

				if (Arr[i][j] == 0)
					continue;
				else{
					for (k = 6; k >= 0; k--) {
						cout << Arr[i][j - k] ;
						//SumOfChar +=Arr[i][j - k];
						cnt++;
					}
					cout << SumOfChar<<" ";
					SumArr[8-cnt] = SumOfChar;				
					j = j - 6;
					SumOfChar = 0;
					cout << endl << endl;
					if (cnt == 8)
						break;
				}

		}
			//배열 초기화
			//ArrIntial(Arr);
		}

	return 0;
}
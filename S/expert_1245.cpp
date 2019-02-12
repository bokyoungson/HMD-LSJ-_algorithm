#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int N;
int point_d[10], point_m[10];



void solve(){
	double left = 0;
	double right = 0;
	for(int i = 0; i < N-1; i++){
		left = point_d[i];
		right = point_d[i+1];
		bool flag = 0;
		while(!flag){
			double right_sum = 0;
			double left_sum = 0;
			double mid = (left + right) / 2.0;
			for(int j  = 0; j <= i; j++){
				left_sum += point_m[j] / pow((mid - point_d[j]), 2);
			}
			for(int j = i+1; j < N; j++){
				right_sum += point_m[j] / pow((point_d[j] - mid), 2);
			}
			if((right_sum - left_sum) == 0 || abs(right - left) <= (1e-12)){
				cout.setf(ios::fixed);
				cout.precision(10);
				cout << mid << " " ;
				flag = true;
			}else{
				if(right_sum < left_sum){
					left = mid;
				}else{
					right = mid;
				}
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	int test_cnt;
	cin >> test_cnt;
	for(int i = 0; i < test_cnt; i++){
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> point_d[j];
		}
		for(int j = 0; j < N; j++){
			cin >> point_m[j];
		}
		cout << "#" << i+1 << " ";
		solve();
		cout << endl;
	}
	return 0;
}



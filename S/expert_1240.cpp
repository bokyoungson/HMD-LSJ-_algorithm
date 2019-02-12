#include <iostream>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;



void readFile(){
	int index[64] = { 0 };
	index[13] = 0; index[25] = 1; index[19] = 2; index[61] = 3; index[35] = 4; index[49] = 5;
	index[47] = 6; index[59] = 7; index[55] = 8; index[11] = 9;
	
	ifstream input("input.txt");
	ofstream output("output.txt");
	
	int test_case;
	input >> test_case;
	
	int arr[50][100];
	
	for(int i = 0; i < test_case; i++){
		int N, M;
		input >> N >> M;
		
		int ans[8] = {0};
		
		for(int n = 0; n < N; n++){
			for(int m = 0; m < M; m++){
				char c;
				input >> c;
				int x = (int)(c-48);
				arr[n][m] = x;
			}
		}
		
		int code_x = -1; int code_y = -1;
		
		for(int n = 0; n < N; n++){
			for(int m = M; m >= 0; m--){
				if(arr[n][m] == 0){
					continue;
				}else{
					code_x = m; code_y = n;
					break;
				}
			}
			if(code_x != -1){
				break;
			}
		}
		
		for(int j = 7; j >= 0; j--){
			int num = 0;
			int mul = 1;
			for(int p = 0; p < 7; p++){
				num += mul * arr[code_y][code_x];
				mul *= 2;
				code_x--;
			}
			ans[j] = index[num];
		}
	 
	 	int result = 0;
	 	if(((ans[0] + ans[2] + ans[4] + ans[6]) * 3 + (ans[1] + ans[3] + ans[5]) + ans[7]) % 10 == 0){
	 		result = ans[0] + ans[1] + ans[2] + ans[3] + ans[4] + ans[5] + ans[6] + ans[7];
		 }
		output << "#" << i+1 << " " << result << endl;
	}
}
int main(int argc, char** argv) {
	readFile();
	 
	return 0;
}

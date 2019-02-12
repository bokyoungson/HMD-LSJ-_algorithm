#include <iostream>
#include <vector>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int change_num, input_num, line;
vector<int> card_list;

int solve(vector<int> cards, int change){
	int size = line;
	if(change == 0){
		int sum = 0;
		for(int i = 0; i < line; i++){
			sum *= 10;
			sum += cards[i];
		}
		return sum;
	}else if(change_num > line&& change_num - change >= line){
		if(change % 2 == 1){
			int tmp = cards[size-1];
			cards[size-1] = cards[size-2];
			cards[size-2] = tmp;
		}
		int sum = 0;
		for(int i = 0; i < size; i++){
			sum *= 10;
			sum += cards[i];
		}
		return sum;
	}
	int max = -1;
	for(int i = 0; i < line; i++){
		for(int j = i+1; j < line; j++){
			if(cards[i] <= cards[j]){
				int tmp = cards[i];
				cards[i] = cards[j];
				cards[j] = tmp;
				int result = solve(cards, change - 1);
				if(result > max){
					max = result;
				}
				cards[j] = cards[i];
				cards[i] = tmp;
			}
			
		}
	}
	
	return max;
	
}

int main(int argc, char** argv) {
	int test_cnt;
	cin >> test_cnt;
	for(int i = 0; i < test_cnt; i++){
		cin >> input_num >> change_num;
		int tmp = input_num;
		line = 0;
		card_list.clear();
		while(tmp){
			int x = tmp % 10;
			card_list.insert(card_list.begin(), x);
			tmp = tmp / 10;
			line++;
		}
		int result = solve(card_list, change_num);
		cout << "#" << i+1 << " " << result << endl;
	}
	return 0;
}

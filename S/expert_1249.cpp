#include <iostream>
#include <queue> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int size;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef struct point{
	int row;
	int col;
}point;

bool enable_check(int c, int r){
	if(c < 0 || r < 0 || c >= size || r >= size){
		return false;
	}	
	return true;
}

int main(int argc, char** argv) {
	int test_cnt;
	cin >> test_cnt;
	for(int t = 0; t < test_cnt; t++){
		cin >> size;
		int map[100][100];
		int result[100][100];
		bool visit[100][100];
		
		
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				char c;
				int x;
				cin >> c;
				x = (int)(c - 48);
				map[i][j] = x;
				result[i][j] = 0;
				visit[i][j] = false;
			}
		}
		
		point tmp;
		tmp.col = 0;
		tmp.row = 0;
		queue<point> bfs;
		bfs.push(tmp);
		visit[0][0] = false;
		
		while(!bfs.empty()){
			int c = bfs.front().col;
			int r = bfs.front().row;
			bfs.pop();
			for(int i = 0; i < 4; i++){
				int nc = c + dx[i];
				int nr = r + dy[i];
				if(enable_check(nc, nr)){
					if((!visit[nc][nr]) || result[nc][nr] > (result[c][r] + map[nc][nr])){
						
						visit[nc][nr] = true;
						result[nc][nr] = result[c][r] + map[nc][nr];
						tmp.col = nc;
						tmp.row = nr;
						bfs.push(tmp);
						
					}
				}
			}
		}
		
		
		
		
		
		cout << "#" << t+1 << " " << result[size-1][size-1] << endl;
	}
	return 0;
}

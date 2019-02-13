#include<iostream>
#include<queue>

using namespace std;

int N;
int MAP[100][100];//weight value
int dump[100][100];//cumulative value
bool check[100][100];//stepped point

typedef struct node
{
	int row;
	int col;
}node;

bool checkPoint(int c,int r)
{
	if (c < 0 || r < 0 || c >= N || r >= N)
	{
		return false;
	}

	return true;
}

void recur(int c, int r) {//row.column

	int i;
	int dcol[4] = { 1,-1,0,0 };//r,l,u,d
	int drow[4] = { 0,0,1,-1 };

	node tmp;

	tmp.col = c;
	tmp.row = r;

	queue<node> q;
	q.push(tmp);

	while (!q.empty()) {
		int cc, rr;
		cc = q.front().col;
		rr = q.front().row;
		q.pop();

		for (i = 0; i < 4; i++) {// compare r,l,u,d

			int dc = cc + dcol[i];	//cumulative col
			int dr = rr + drow[i];	//cumulative row

			if(checkPoint(dc,dr)){
				if (!check[dc][dr] || dump[dc][dr] > dump[cc][rr] + MAP[dc][dr]) {
					// not checked point || c_val of next > c_val of current + next weight
					node n;
					n.row = dr;
					n.col = dc;
					check[dc][dr] = true;
					dump[dc][dr] = dump[cc][rr] + MAP[dc][dr];//change the value to the smallest one
					q.push(n);
				}
			}
		}
	}
}

int main(int argc, char** argv) {

	short NumOfTestcase;
	int i, j, k;
	char weight;
	int point,p;
	
	cin >> NumOfTestcase;

	for (i = 0; i < NumOfTestcase; i++) {

		cin >> N;
		
		//initialization
		for (j = 0;j<N;j++) {
			for (k = 0; k < N;k++) {
				check[j][k] = false;
				dump[j][k] = 0;
			}
		}
		
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				cin >> weight;
				MAP[j][k]=(int)(weight-48);
			}
		}

		check[0][0] = true;
		
		recur(0,0);

		cout<<"#"<<i+1<<" "<<dump[N - 1][N - 1]<<endl;
	}
	return 0;
}
//didn't try test set

#include<iostream>
#include<algorithm>
#include<vector>

typedef struct node{
	int L;
	int R;
	int value;
	int rank;
}node;

typedef struct seatmark {
	bool *seat;
}seatmark;

bool compare(node a, node b) {
	if (a.value == b.value)
		return a.L > b.L;
	return a.value < b.value;
}

using namespace std;

int func(vector<node> tmp,seatmark s,int Q, int N) {

	int i, j,count=0;
	int k=987654321;
	int point=1000000;
	int r = 0;

	sort(tmp.begin(), tmp.end(),compare);
	
	for (i = 0; i < Q; i++)
	{

		count = 0;

		for (j = (tmp[i].L) - 1; j <= (tmp[i].R)-1; j++) {

			if (s.seat[j] == false) {
				s.seat[j] = true;
				count++;
			}
		}

		if (count < k) {
			k = count;
			cout << count << endl;
		}
	}

	return k;
}

int main(){

	int T, i, j, k = 0;// k = largest value

	seatmark s;

	node tmp;

	vector<node> t;


	cin >> T;

	for (i = 0; i < T; i++) {
		int N, Q;
		cin >> N >> Q;

        t.clear();


		s.seat = new bool[N];

		for (j = 0; j < N; j++)
		{
			s.seat[j] = false;
		}


		for (j = 0; j < Q; j++)
		{
			cin >> tmp.L >> tmp.R;
			tmp.value = tmp.R - tmp.L + 1;
			tmp.rank = j;
			t.push_back(tmp);

		}
		k=func(t,s,Q,N);

		cout << "Case #" << i + 1 << ": " << k<<endl;
	}
	return 0;
}
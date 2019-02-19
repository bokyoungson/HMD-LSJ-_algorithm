#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll X[1001], Y[1001], P[1001], m;//x값,y값, 조상노드번호


struct Edge {//중요!
	ll start, end, cost;
	bool operator < (const Edge &other) const {
		return cost < other.cost; // overloading. low->high value
	}
};

ll cal(ll x1, ll x2, ll y1, ll y2)
{
	return{ abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2) };
}

void Bsort(int N,ll *Z){
	ll can = 0;
	int j,k;

	for (j = N*(N - 1) / 2; j >= 1; j--) {
		for (k = 1; k < j; k++) {
			if (Z[k] > Z[k + 1]) {
				can = Z[k];
				Z[k] = Z[k + 1];
				Z[k + 1] = can;
			}
		}
	}
}

ll Find(ll x) {//부모노드 뭐냐?
	return x == P[x] ? x : P[x] = Find(P[x]);
}

void Union(ll x,ll y) {//부모노드 유니언
	P[Find(x)] = Find(y);
}

int main() {

	int NumOfTestcase;
	int N;
	int i, j;
	double E;

	vector <Edge> a;

	cin >> NumOfTestcase;

	for (i = 1; i <= NumOfTestcase; i++) {

		cin >> N;

		a.clear();

		for (j = 1; j <= N; j++)
			cin >> X[j];

		for (j = 1; j <= N; j++)
			cin >> Y[j];

		cin >> E;

		for (j = 1; j <= N; j++)
			P[j] = j;

		int cnt = 0;
		//1.모든 간선 가중치 계산 및 저장
		for (ll j = 1; j <= N; j++) {
			for (ll k = j+1; k <= N; k++)
				a.push_back({ j, k, cal((ll)X[j], (ll)X[k], (ll)Y[j], (ll)Y[k]) });
				//시작점,도착점,간선가중치
		}

		//2.계산된 가중치(Z) sorting. 작은것->큰것	
		sort(a.begin(),a.end());
		
		m = a.size();

		//3.작은 노드들부터 Union
		ll cul = 0;

		for (ll j = 0; j < m; j++)
		{
			Edge e = a[j];
			ll x = Find(e.start);
			ll y = Find(e.end);

			if (x != y) {
				Union(e.start, e.end);
				cul += e.cost;
				cnt++;
			}

			if (cnt == N - 1)
				break;
		}

		cout << fixed;
		cout.precision(0);

		cout << "#" << i << " " << E*cul << endl;

	}
	return 0;
}
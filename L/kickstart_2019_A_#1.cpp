// passed visible test set
//non-passed hidden test set : Time Limit Exceeded

#include<iostream>
#include<algorithm>

using namespace std;

int *value;

int check(int val[],int N,int P) {

  int i,j;
  int sum = 0;
  int cp=987654321;

  sort(val, val + N);

  for (i = 0; i < N - P + 1; i++) {
     for (j = i; j < i + P; j++)
        sum += val[i + P - 1] - val[j];
     if (sum < cp)
        cp = sum;
     sum = 0;
  }
  return cp;
}

int main(){

  int i, j, k, T;

  cin >> T;

  for (i = 0; i < T; i++) {

     int N, P;

     cin >> N >> P;

     value = new int[N];
     
     for (j = 0; j < N; j++)
              cin >> value[j];

     k=check(value,N,P);
     
     cout << "Case #" << i + 1 << ": " << k << endl;
  }
  return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

double *point_x;
double *mass;
int N;

void solve(double left, double right,int left_index){

	double middle=(right+left)/2.0;	
	double temp_left=0,temp_right=0;
	for(int j=0;j<left_index+1;j++){
		temp_left += mass[j]/pow(middle-point_x[j],2);
	}
	for(int k=left_index+1 ; k<N ; k++){
		temp_right += mass[k]/pow(point_x[k]-middle,2);
	}
	if((temp_right - temp_left) == 0 || abs(right - left) <= (1e-12))
			{
				cout.setf(ios::fixed);
				cout.precision(10);
				cout << middle;
			}
	else{
		if(temp_left<temp_right)
			right=middle;		
		else
			left=middle;
		solve(left,right,left_index);
	}
}
int main(){
	
	int case_test;
	int point_temp;
	int mass_temp;	
	cin >> case_test;		 
	for(int i = 0 ; i < case_test ; i++ ){
		cin >> N;
		point_x=new double[N];
		mass=new double[N];
		for(int n = 0 ; n < N ; n++) {
			cin >> point_temp;
			point_x[n] = point_temp;
		}
		for(int n = 0 ; n < N ; n++) {
			cin >> mass_temp;
			mass[n] = mass_temp;
		}		
		cout<< "#"<< i+1<<" ";
		for(int s=0; s<N-1 ; s++){
			solve(point_x[s],point_x[s+1],s);
			cout<<" ";		
		}
		cout<<endl;
	}	
	return 0;
	
}

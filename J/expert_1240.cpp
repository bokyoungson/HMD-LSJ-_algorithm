#include <iostream>

using namespace std;

int ANS(char *answer);
int main(){
	int C;
	int N,M;
	char *arr;
	char temp='0';
	char *ans2=new char[56];
	bool sign=0;
	int *v;
	
	cin >> C;
	
	v=new int[C];	
	for (int c=0 ; c<C ; c++){
		cin >> N >> M; 
		arr=new char[M];
		for(int l=0;l<M;l++)	
			arr[l]={'0'};

		for(int n=0 ; n<N ; n++){
			for(int l=0;l<56;l++)	ans2[l]={'0'};			
			if (sign==1){
				for (int i=M-1 ; i>=0 ; i--){
					if (arr[i]=='1'){
						for(int j=55 ;j>=0;j--,i--){
							ans2[j]=arr[i];
					 	}
					}
				}
				v[c]=ANS(ans2);	
			}
			sign=0;
			for(int m=0;m<M ;m++){
				cin >> temp;		
				arr[m]=temp;
				if (temp=='1')
					sign = 1;
				
			}

		}	

	}
	for(int i=0;i<C;i++)
		cout<<"#"<<i+1<<" "<<v[i]<<endl;	
	return 0;
	
}
int ANS(char *answer){
	char ans[8][7];
	int k=0;
	int value[8]={0};
	int mul;
	int count=0;
	int Bin[10]={13,25,19,61,35,49,47,59,55,11};
	int final_value=0;
	for(int i=0; i<8 ;i++ ){
		for(int j=0;j<7;j++,k++)	ans[i][j]=answer[k];
		
	}
	for(int i=0;i<8;i++){
		mul=1;
		for(int j=6;j>=0;j--){
			value[i] += mul*(int(ans[i][j])-48);
			mul *= 2;		
		}

	}
	int i=0;
	while (i<9){
		
		if(value[i]==Bin[count]){
			value[i]=count;
			i++;
			count=-1;
		}		
		count++;
	}

	final_value=(value[0]+value[2]+value[4]+value[6])*3+value[1]+value[3]+value[5]+value[7];
	if (final_value%10==0){
		final_value=0;
		for(int i=0;i<8;i++)
			final_value += value[i];
	}
	else
		final_value=0;
		
	return final_value;
}

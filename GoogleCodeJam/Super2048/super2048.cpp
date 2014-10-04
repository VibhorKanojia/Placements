#include <iostream>
#include <string>
#include <map>
using namespace std;


map<string,int> encoder;
void display(int ** array, int N){
	
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cout<<*(*(array+ i) + j)<<" ";
		}
		cout<<endl;
	} 
}

void shiftPass(int ** array, int N , string dir){
	switch (encoder[dir]){
		case 1 :
			for (int i = 0 ; i < N ; i++){
				for (int j = 0 ; j < N ; j++){
					if (array[i][j] == 0){
						int pos = j-1;
						for (int k = pos+2 ; k < N ; k++){
							if (array[i][k] != 0){
								array[i][j]=array[i][k];
								array[i][k] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		
		case 2 :
			for (int i = 0 ; i < N ; i++){
				for (int j = N-1 ; j >= 0 ; j--){
					if (array[i][j] == 0){
						
						int pos = j+1;						// bacause j-- will execute at the end of the loop
						for (int k = pos-2 ; k >= 0 ; k--){
							if (array[i][k] != 0){
								array[i][j]=array[i][k];
								array[i][k] = 0;
								break;
							}
						}
					}
				}
			}
			break;
			
		case 3 :
			for (int j = 0 ; j < N ; j++){
				for (int i = 0 ; i < N ; i++){
					if (array[i][j] == 0){	
						int pos = i-1;						// bacause i++ will execute at the end of the loop
						for (int k = pos+2 ; k < N ; k++){
							if (array[k][j] != 0){
								array[i][j]=array[k][j];
								array[k][j] = 0;
								break;
							}
						}
					}
				}
			}
			break;
			
		case 4 :
			for (int j = 0 ; j < N ; j++){
				for (int i = N-1 ; i >= 0 ; i--){
					if (array[i][j] == 0){					
						int pos = i+1;						// bacause i-- will execute at the end of the loop
						for (int k = pos-2 ; k >= 0 ; k--){
							if (array[k][j] != 0){
								array[i][j]=array[k][j];
								array[k][j] = 0;
								break;
							}
						}
					}
				}
			}
			break;
			
		default :
			break;
	}
}



void mergePass(int ** array, int N , string dir){
	switch (encoder[dir]){
		case 1 :
			for (int i = 0 ; i < N ; i++){
				for (int j = 0 ; j < N-1 ; j++){
					if (array[i][j] == array[i][j+1]){
						array[i][j] = 2*array[i][j];
						array[i][j+1] = 0;
					}
				}
			}
			break;
		
		case 2 :
			for (int i = 0 ; i < N ; i++){
				for (int j = N-1 ; j > 0 ; j--){
					if (array[i][j] == array[i][j-1]){
						array[i][j] = 2*array[i][j];
						array[i][j-1] = 0;
					}
				}
			}
			break;
			
		case 3 :
			for (int j = 0 ; j < N ; j++){
				for (int i = 0 ; i < N-1 ; i++){
					if (array[i][j] == array[i+1][j]){
						array[i][j] = 2*array[i][j];
						array[i+1][j] = 0;
					}
				}
			}
			break;
			
		case 4 :
			for (int j = 0 ; j < N ; j++){
				for (int i = N-1 ; i > 0 ; i--){
					if (array[i][j] == array[i-1][j]){
						array[i][j] = 2*array[i][j];
						array[i-1][j] = 0;
					}
				}
			}
			break;
			
		default :
			break;
	}
	
}


void initialize(){
		encoder.insert(pair<string,int>("left",1));
		encoder.insert(pair<string,int>("right",2));
		encoder.insert(pair<string,int>("up",3));
		encoder.insert(pair<string,int>("down",4));
}

int main(){
	int testcases;
	cin >> testcases;
	initialize();
	int case_num =1;
	while ( testcases-- ){
		int N;
		cin >> N;
		string dir;
		cin >> dir;
		int ** array = new int*[N];
		for (int i = 0 ; i < N ; i++){
			array[i] = new int[N];
		}
		
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < N ; j++){
				cin>>array[i][j];
			}	
		}
		shiftPass(array,N,dir);
		mergePass(array, N, dir);
		shiftPass(array,N,dir);
		cout<<"Case #"<<case_num<<":"<<endl;
		display(array,N);
		case_num++;
	}
	return 0;	
}

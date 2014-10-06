#include <iostream>
#include <cmath>
using namespace std;

int count = 1;
void display(int ** array, int H, int W){
	for (int i = 0 ; i< H ; i++){
		for (int j = 0 ; j < W ; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}

void displayBasin(char ** array, int H, int W){
	for (int i = 1 ; i<= H-2 ; i++){
		for (int j = 1 ; j <= W-2 ; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}

int mymin(int ** array,int i ,int j){
	int min_num = min(array[i][j], min(array[i-1][j], min(array[i+1][j], min(array[i][j-1],array[i][j+1]))));
	if (min_num == array[i][j]){
		return 0;
	}
	else if (min_num == array[i-1][j]){
		return 1;
	}
	else if (min_num == array[i][j-1]){
		return 2;
	}
	else if (min_num == array[i][j+1]){
		return 3;
	}
	else if (min_num == array[i+1][j]){
		return 4;
	}
	
}



char fillCell(char ** basin, int ** array, int i , int j){
	int small = mymin(array, i, j);
		if (small == 0){
				basin[i][j] = 96+count;
				count++;
				return basin[i][j];
				
		}
		
		else if (small == 1){
			if (basin[i-1][j] !='-' && basin[i-1][j] !='+'){
				basin[i][j]= basin[i-1][j];
				return basin[i][j];
			}
			else{
				basin[i][j] =  fillCell(basin, array, i-1, j);
				}
			}
			
		else if (small == 2){
			if (basin[i][j-1] !='-' && basin[i][j-1] !='+'){
				basin[i][j] = basin[i][j-1];
				return basin[i][j];
			}
			else{
				basin[i][j] =  fillCell(basin, array, i, j-1);
				}
			}
			
			
		else if (small == 3){
			if (basin[i][j+1] !='-' && basin[i][j+1] !='+'){
				basin[i][j] = basin[i][j+1];
				return basin[i][j];
			}
			else{
				basin[i][j] =  fillCell(basin, array, i, j+1);
			}
		}
			
		else if (small == 4){
			if (basin[i+1][j] !='-' && basin[i+1][j] !='+'){
				basin[i][j] = basin[i+1][j];
				return basin[i][j];
			}
			else{
			basin[i][j] =  fillCell(basin, array, i+1, j);
			}
		}
}

void fillBasin(char ** basin, int ** array, int H , int W){
	
	for (int i = 1 ; i <= H-2 ; i++){
		for (int j =1 ; j <= W-2 ; j++){
			if (basin[i][j] != '+'){
				continue;
			}
			else {	
				fillCell(basin, array, i, j);
			}
		}
	}
}	


int main(){
	int testcases;
	cin >> testcases;
	int case_num = 1;
	while (testcases--){
		count =1;
		int H,W;
		cin >> H;
		cin >> W;
		int ** array = new int*[H+2];
		for (int i = 0 ; i < H+2 ; i++){
			array[i] = new int[W+2];
		}
		
		char ** basin = new char*[H+2];
		for (int i = 0 ; i < H+2 ; i++){
			basin[i] = new char[W+2];
		}
		
		for (int i = 0 ; i < H+2 ; i++){
			array[i][0] = 10000;
			array[i][W+1] = 10000;
			basin[i][0] = '-';
			basin[i][W+1] = '-';
		}
		
		for (int j = 0 ; j < W+2 ; j++){
				array[0][j] = 10000;
				array[H+1][j] = 10000;
				basin[0][j] = '-';
				basin[H+1][j] = '-';
				
				
		}
		
		for (int i = 1 ; i <= H ; i++){
			for (int j = 1 ; j <= W ; j++){
				cin>>array[i][j];
				basin[i][j]='+';
			}
		}
		
	
		fillBasin(basin, array, H+2, W+2);
		cout<<"Case #"<<case_num<<": "<<endl;
		displayBasin(basin, H+2,W+2);
		case_num++;
		
	}
	
	return 0;
}

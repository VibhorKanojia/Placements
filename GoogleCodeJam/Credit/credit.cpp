#include <iostream>
#include <queue>
using namespace std;


void printArray(int * array, int L){
	for (int i = 0 ; i < L ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

struct elements{
	int value;
	int pos;
};

void radixSort(struct elements * array,int L){
	//given the biggest number could be 1000 => O(4n) complexity
	int base = 10;
	for (int i = 0 ; i < 4 ; i++){
		queue<struct elements> temp_array[10];
		for (int j = 0 ; j < L ; j++){
			int index = (array[j].value%base)*10/base;
			temp_array[index].push(array[j]);
		}
		int k =0;
		int m =0;
		while(k != 10){
			if (!temp_array[k].empty()){
				struct elements num = temp_array[k].front();
				array[m] = num;
				m++;
				temp_array[k].pop();
			}
			else{
				k++;
			}
		}
		base=base*10;
	}
	
}


void findAnswer(struct elements * a, int L, int C, int case_num){
	int i = 0 ;
	int j = L-1;
	int flag = 0;
	while (flag !=1){
		if (a[i].value + a[j].value > C){
			j--;
		}
		else if (a[i].value + a[j].value < C){
			i++;
		}
		else{
			int min = a[i].pos > a[j].pos ? a[j].pos : a[i].pos;
			int max = a[i].pos < a[j].pos ? a[j].pos : a[i].pos;
			cout<<"Case #"<<case_num<<": "<<min<<" "<<max<<endl;
			flag =1;
		}
	}
}




int main(){
	//implementing Radix sort
	int testcases;
	cin >> testcases;
	int case_num = 1;
	while (testcases--){
		int C;
		cin >> C;
		int L;
		cin >> L;
		struct elements array[L];
		for (int i = 0 ; i < L ; i++){
			int val;
			cin >> val;
			struct elements elem;
			elem.value = val;
			elem.pos = i+1;
			array[i] = elem;
		}
		radixSort(array,L);
		findAnswer(array,L,C,case_num);
		case_num++;
	}
	return 0;
}

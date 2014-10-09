#include <iostream>
#include <cmath>
using namespace std;


void printArray(long long * array, long long N){
	for (long long i = 0 ; i < N ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}



int main(){
	int testcases;
	cin >> testcases;
	int case_num= 1;
	while (testcases--){
		long long  N, p, q, r, s;
		cin >> N;
		cin >> p;
		cin >> q;
		cin >> r;
		cin >> s;
		
		long long array[N];
		long long sum = 0;
		for (long long i = 0 ; i < N ; i++){
			array[i] = (i*p + q) % r + s;
			sum = sum + array[i];
		}
	//		printArray(array, N);
		long long div;
		if (N >=3){
		 div = sum /3;
		}
		else if (N == 2){
			div = sum/2;
		}
		else if (N == 1){
			div = sum;
		}
		
		int flag = 1;
		long long temp_sum = 0;
		long long part1 = 0;
		long long part2 = 0;
		long long part3 = 0;
		long long error = div;
		for (int i = 0 ; i < N ; i++){
			temp_sum = temp_sum + array[i];
			
			if (temp_sum > div){
				
				if (temp_sum - div >= error){
				//	cout<<temp_sum<<" "<<error<<endl;
					if (flag ==1){
						part1 = temp_sum -array[i];
						temp_sum =0;
						flag =2;
						i--;
						error = div- error;
					//	cout<<"new error "<<error<<endl;
						continue;
					}
					else if (flag ==2){
						part2 = temp_sum -array[i];
						temp_sum =0;
						flag =3;
						i--;
						error = div- error;
						//cout<<"new error "<<error<<endl;
						continue;
					}
					
					
					
				}
				else if (temp_sum - div < error){
				//	cout<<temp_sum<<" "<<error<<endl;
					if (flag ==1){
						part1 = temp_sum;
						error = temp_sum -div;
						temp_sum =0;
						flag =2;
						error = div- error;
					//	cout<<"new error "<<error<<endl;
						continue;
					}
					else if (flag ==2){
						part2 = temp_sum;
						error = temp_sum -div;
						temp_sum =0;
						flag =3;
						error = div- error;
					//	cout<<"new error "<<error<<endl;
						continue;
					}
				}
			}
			error = error - array[i];	
		} 
		part3 = sum - (part1 + part2);
		//cout<<part1<<" "<<part2<<" "<<part3<<endl;
		long long max_num = max (part3, max(part1, part2));
		//cout<<max_num << " " << sum<<endl;
		double prob = (double)(sum - max_num)/sum;
		cout<<"Case #"<<case_num<<": "<<prob<<endl;
		
		case_num++;
		
		
	}
}

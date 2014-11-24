#include <iostream>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;

	int array[N];
	int cumarray[N];
	map<int,int> mymap;
	for (int i = 0 ; i < N ; i++){
		cin >> array[i];
	}

	//cout<<"here"<<endl;
	int window = 0;
	cumarray[0] = array[0];
	mymap.insert(pair<int,int>(array[0], 0));
	map<int,int>::iterator it;
	map<int,int>::iterator ittemp = mymap.begin();
	for (int i = 1 ; i < N ; i++){
		//cout<<"here1"<<endl;
		if (cumarray[i-1] < 0){
			mymap.clear();
  			mymap.insert(pair<int,int>(array[i], i));
			cumarray[i] = array[i];
		}
		else{
			it = mymap.find(array[i]);
			ittemp = mymap.begin();
			if (it!= mymap.end()){
				
				int sum = 0;

				int k = (it->second) + 1;
				//cout<<"here3 "<<mymap.size()<<endl;
				if (ittemp != it){
					do {
						//cout<<"here4"<<endl;
						mymap.erase(ittemp);
						ittemp = mymap.begin();
					} while (ittemp != it);
					mymap.erase(ittemp);
				}
				else{
					mymap.erase(ittemp);
				}

				//8,1,2,3,3,-1,2,3,4

				for (int j = k ; j <= i ; j++){
					//cout<<"here5"<<endl;
					sum = sum + array[j];
					mymap.insert(pair<int,int>(array[j], j));
				}
				cumarray[i] = sum;
			}
			else{

				if (cumarray[i - 1] >= 0 ){
					mymap.insert(pair<int,int>(array[i], i));
					cumarray[i] = array[i] + cumarray[i-1];
  				}

  			}
		}
	}

	for (int i = 0 ; i < N ; i++){
		cout<<cumarray[i]<<" ";
	}
	cout<<endl;
	return 0;
}













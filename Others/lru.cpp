#include <iostream>
#include <list>
#include <map>

using namespace std;

bool isPresent(int page_num, map<int, list<int>::iterator> & checker ){
	map<int, list<int>::iterator>::const_iterator it = checker.find(page_num);
	if (it != checker.end()){
		return true;
	}
	else return false;
}


void updateList(int page_num, map<int, list<int>::iterator> & checker , list<int> & cache ){
	map<int, list<int>::iterator>::const_iterator it = checker.find(page_num);
	list<int>::iterator itt = (*it).second;
	cout<<"Updating "<<(*itt)<<endl;
	cache.erase(itt);
	itt = cache.insert(cache.end(), page_num);
	checker[page_num] = itt;

}

void insertPage(int page_num, map<int, list<int>::iterator> & checker , list<int> & cache, int cache_size){
	if (cache.size() < cache_size){
		list<int>::iterator it = cache.insert(cache.end(),page_num);
		checker.insert(pair<int, list<int>::iterator>(page_num, it));
	}
	else{
		cout<<"Popping "<<cache.front()<<endl;
		cache.pop_front();
		list<int>::iterator it = cache.insert(cache.end(),page_num);
		checker.insert(pair<int, list<int>::iterator>(page_num, it));	
	}
}







int main(){
	map<int , list<int>::iterator> checker;
	list<int> cache;
	int cache_size;
	cin >> cache_size;
	int page_num;
	cin >>page_num;
	while (page_num != -1){
		if (isPresent (page_num, checker)){
			updateList(page_num, checker, cache);
		}
		else {
			list<int>::iterator it;
			insertPage(page_num, checker, cache, cache_size);
		}
		cin>>page_num;
	}

	return 0;
}
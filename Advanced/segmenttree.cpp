#include <iostream>
#include <cmath>
#include <string>

using namespace std; 

void initializeTree(int * tree, int tree_size, int * array, int N, int start, int end, int node_num){
	cout<<"start "<<start<<" end "<<end<<" node "<< node_num<<endl;
	if (start == end){
		tree[node_num] = start;
	}

	else {
		initializeTree(tree, tree_size, array, N, start, (start+end)/2, 2*node_num);
		initializeTree(tree, tree_size, array, N, (start+end)/2 + 1 ,end, 2*node_num +1);
		
		if (array[tree[2*node_num]] <= array[tree[2*node_num+1]]){
			tree[node_num] = tree[2*node_num];
		}
		else {
			tree[node_num] = tree[2*node_num + 1];
		}
	}
}


int queryGETMIN(int * tree, int tree_size, int * array, int N, int qstart, int qend, int start, int end, int node_num){
	if (end < qstart || start > qend){
		return -1;
	}

	if (start >= qstart && end <=qend){
		return tree[node_num];
	}

	int leftresult = queryGETMIN(tree, tree_size, array, N, qstart, qend, start, (start+end)/2, 2*node_num);
	int rightresult = queryGETMIN(tree, tree_size, array, N, qstart, qend, (start+end)/2 + 1, end, 2*node_num +1);
	
	if (leftresult == -1) {
		tree[node_num] = rightresult;
		return rightresult;
	}

	if (rightresult == -1) {
		tree[node_num] = leftresult;
		return leftresult;
	}

	//if (rightresult == -1) return leftresult;
	//if (leftresult == -1) return rightresult; 
	if (array[rightresult] <= array[leftresult]){
		tree[node_num] = rightresult;
    	return rightresult;
    }
    else{
    	tree[node_num] = leftresult;
    	return leftresult;
    }
}


int main(){
	int N;
	cin >> N;

	int array[N];
	int tree_size = 20;
	int tree[tree_size];


	for (int i = 0 ; i < N ; i++){
		cin >> array[N];
	}
	for (int i = 0 ; i < tree_size ; i++){
		tree[i] = -1;
	}

	initializeTree(tree, tree_size, array, N, 0, N-1, 1);



	string query;
	while(cin>>query){
		if (query == "GETMIN"){
			int b,e;
			cin>>b;
			cin>>e;
			int ans = queryGETMIN(tree, tree_size, array, N, b, e, 0 , N-1 , 1);
			cout<<array[ans]<<endl;
		}
		else if (query == "UPDATE"){
		//	queryUPDATE();
		}
		else{
			cout<<"Invalid Query"<<endl;
		}
	}

	return 0;
}















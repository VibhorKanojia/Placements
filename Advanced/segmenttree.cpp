#include <iostream>
#include <cmath>
#include <string>

using namespace std; 


void printArray(int * array, int size){
	for (int i = 0 ; i < size ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void initializeTree(int * tree, int tree_size, int * array, int N, int start, int end, int node_num){
	
	if (start == end){
		tree[node_num] = start;
	}

	else {
		initializeTree(tree, tree_size, array, N, start, (start+end)/2, 2*node_num);
		initializeTree(tree, tree_size, array, N, (start+end)/2 + 1 ,end, 2*node_num +1);
		
		if (array[tree[2*node_num ]] <= array[tree[2*node_num + 1]]){
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
		return rightresult;
	}

	if (rightresult == -1) {
		return leftresult;
	}
 
	if (array[rightresult] <= array[leftresult]){
    	return rightresult;
    }
    else{
    	return leftresult;
    }
}

void UPDATE(int * tree, int tree_size , int * array, int N, int index, int newval, int start, int end, int node_num){
	if (!(start <= index && index <= end)){
		return;
	}
	else{
		if (start == end){
			tree[node_num] = index;
		}

		else{
			UPDATE(tree, tree_size, array, N, index, newval, start, (start+end)/2 , 2*node_num);
			UPDATE(tree, tree_size, array, N, index, newval, (start+end)/2 + 1, end, 2*node_num + 1);

			if (array[tree[2*node_num]] <= array[tree[2*node_num + 1]]){
				tree[node_num] = tree[2*node_num];
			}  
			else{
				tree[node_num] = tree[2*node_num + 1];
			}
		}
	}
}


int main(){
	int N;
	cin >> N;

	int array[N];
	int tree_size = 4*N + 1;
	int tree[tree_size];


	for (int i = 0 ; i < N ; i++){
		cin >> array[i];
	}

	for (int i = 0 ; i < tree_size ; i++){
		tree[i] = -1;
	}

	initializeTree(tree, tree_size, array, N, 0, N-1, 1);

	//printArray(array, N);
	//cout<<endl<<endl;
	//printArray(tree, tree_size);

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
			int ind, newval;
			cin >> ind;
			cin >> newval;
			array[ind] = newval;
			UPDATE(tree, tree_size, array, N, ind, newval, 0, N -1 , 1);
		}
		else{
			cout<<"Invalid Query"<<endl;
		}
	}

	return 0;
}















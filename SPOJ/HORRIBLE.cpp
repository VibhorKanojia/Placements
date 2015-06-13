#include <bits/stdc++.h>

using namespace std;


#define llint long long int

void initializeTree(llint * tree, llint * array, llint N, llint start, llint end, llint node_num){
  if (start == end) {
    tree[node_num] = array[start];
  }
  else{
    initializeTree(tree,array,N, start, (start+end)/2,2*node_num);
    initializeTree(tree,array,N,(start+end)/2 + 1, end, 2*node_num+1);

    tree[node_num] = tree[2*node_num] + tree[2*node_num+1];
  }
  return;
}

void updateTree(llint * tree, llint p, llint q, llint v, llint start, llint end, llint node_num, llint* lazyNode){
  llint cur_interval_size = (end-start +1);
  llint child1_size = ((start+end)/2) - start + 1;
  llint child2_size = cur_interval_size - child1_size; 
      

  if (lazyNode[node_num] != 0){
    tree[node_num] += lazyNode[node_num];

    if (start != end){
      lazyNode[2*node_num] +=  child1_size*(lazyNode[node_num]/cur_interval_size);
      lazyNode[2*node_num+1] += child2_size*(lazyNode[node_num]/cur_interval_size); 
    }

    lazyNode[node_num] = 0;
  }

  if (p > end || q < start){
    return;
  }

  else if (start >= p && end <=q) {
    tree[node_num] += cur_interval_size*v; // done for all nodes => leaf + non-leaf
    if (start != end){  // for non-leaf nodes; 
      lazyNode[2*node_num] +=  child1_size*v;
      lazyNode[2*node_num+1] += child2_size*v;   
    }
    return;
  }

  else{
    updateTree(tree,p,q,v,start, (start+end)/2, 2*node_num, lazyNode);
    updateTree(tree,p,q,v,(start+end)/2 +1 , end , 2*node_num+1, lazyNode);
    tree[node_num] = tree[2*node_num]+tree[2*node_num+1];
  }

  return;
}


llint queryTree(llint * tree, llint p, llint q, llint start, llint end, llint node_num, llint* lazyNode){

  llint cur_interval_size = (end-start +1);
  llint child1_size = (start+end)/2 - start + 1;
  llint child2_size = cur_interval_size - child1_size; 
      

  if (lazyNode[node_num] != 0){
    tree[node_num] += lazyNode[node_num];

    if (start != end){
      lazyNode[2*node_num] +=  child1_size*(lazyNode[node_num]/cur_interval_size);
      lazyNode[2*node_num+1] += child2_size*(lazyNode[node_num]/cur_interval_size); 
    }

    lazyNode[node_num] = 0;
  }

  if (p > end || q < start){
    return 0;
  }

  else if (start >= p && end <= q){
    return tree[node_num];
  }

  else{
    return queryTree(tree, p, q, start, (start+end)/2, 2*node_num, lazyNode) + queryTree(tree,p,q,(start+end)/2 + 1, end, 2*node_num + 1, lazyNode);
  }
}



void printTree(llint * tree, llint tree_size){
  for(int i = 0; i < tree_size ; i++){
    cout<<tree[i]<<" ";
  }
  cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);

  int testcases;
  cin >> testcases;
  while (testcases--){
    llint N;
    cin >> N;
    llint C;
    cin >> C;
    llint array[N];
    llint tree_size = 4*N+1;
    llint tree[tree_size];
    llint lazyNode[tree_size];
    memset(lazyNode, 0, sizeof(lazyNode));


    for (int i = 0 ; i < N ; i++){
      array[i] = 0;
    }

    initializeTree(tree,array,N,0, N-1,1);

    while(C--){
      char op;
      llint p,q,v;
      cin >> op;
  
      if (op == '0'){
        cin >> p >> q >> v;
        updateTree(tree, p-1, q-1, v, 0, N-1,1, lazyNode);      //array is 1-based in the question => p-1 and q-1
      }
      else if (op =='1'){
        cin >> p >> q;
        llint val = queryTree(tree, p-1, q-1, 0, N-1, 1, lazyNode);
        cout<<val<<endl;
      }

    }


  }

  return 0;
}
#include<iostream>
using namespace std;

struct DSet{
  int rank;
  int parent;
};

int findUltimateParent(int node, DSet arr[]) {
  if (node == arr[node].parent) return node;
  arr[node].parent = findUltimateParent(arr[node].parent, arr);
  return arr[node].parent;
}

void unionByRank(int u, int v, DSet arr[]) {
  int u_ultimate = findUltimateParent(u, arr);
  int v_ultimate = findUltimateParent(v, arr);

  if (u_ultimate == v_ultimate) return;

  if (arr[u_ultimate].rank < arr[v_ultimate].rank) arr[u_ultimate].parent = v_ultimate; 
  else if (arr[u_ultimate].rank > arr[v_ultimate].rank) arr[v_ultimate].parent = u_ultimate; 
  else {
    arr[v_ultimate].parent = u_ultimate;
    arr[u_ultimate].rank += 1;
  }
}

void inSameComponent(int node1, int node2, DSet arr[]) {
  if(findUltimateParent(node1, arr) == findUltimateParent(node2, arr)) {
    cout << "Same\n"; 
  } 
  else cout << "Not same\n"; 
}

int main () {
  int n = 7;+

  DSet arr[n];

  for(int i = 0; i < n; i++) {
    arr[i].parent = i;
    arr[i].rank = 0;
  }

  unionByRank(0, 1, arr);
  unionByRank(1, 2, arr);
  unionByRank(3, 4, arr);
  unionByRank(5, 6, arr);
  unionByRank(4, 5, arr);

  inSameComponent(2, 6, arr); 

  unionByRank(2, 6, arr);

  inSameComponent(2, 6, arr);
}

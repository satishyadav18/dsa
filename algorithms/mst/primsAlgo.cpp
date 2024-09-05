#include<iostream>
#include<climits>
using namespace std;
#define MAX 6 // size of graph

int graph[MAX][MAX] = {
  {0, 5, 0, 6, 0, 0},
  {5, 0, 2, 2, 0, 0},
  {0, 2, 0, 1, 4, 0},
  {6, 2, 1, 0, 3, 0},
  {0, 0, 4, 3, 0, 1},
  {0, 0, 6, 0, 1, 0}
};

void prims(int);
int minEle(bool[] , int[]);
void printMST(int[], int[], int);

int main () {
  prims(0); // start vertex
  return 0;
}

void prims(int start) {
  int key[MAX], parent[MAX];
  bool mstSet[MAX]; // mstSet is basically a true/false array to see visited ele

  for (int i = 0; i < MAX; i++) 
    key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

  key[start] = 0;

  for (int i = 0; i < MAX; i++) {
    int  u = minEle(mstSet, key); // gets min ele from key
    mstSet[u] = true;
    for (int j = 0; j < MAX; j++) 
      if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j])
        parent[j] = u, key[j] = graph[u][j];
  }

  printMST(parent, key, start);
}

int minEle (bool mstSet[], int key[]) {
  int minIdx = 0, minVal = INT_MAX;
  for (int i = 0; i < MAX; i++)
    if (key[i] < minVal && mstSet[i] == false)
      minVal = key[i], minIdx = i;
                
  return minIdx; // since here idx is basically the vertex number
}

void printMST(int parent[], int key[], int start) {
  int sum = 0;
  for (int i = 0; i < MAX; i++) {
    if (parent[i] != -1)
      cout << parent[i] << "->" << i << " " << graph[i][parent[i]] << endl;
      sum += graph[i][parent[i]];
  }
  cout << "MST Weight is: " << sum;
}
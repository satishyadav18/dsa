#include<iostream>
#include<fstream>
using namespace std;

int *rankArr;
int *parentArr;
int *edgeName;
int *edgeArr;
int **graphMatrix;

int findUltimateParent(int node) {
  if (node == parentArr[node]) return node;
  return parentArr[node] = findUltimateParent(parentArr[node]);
}

void unionOf(int u, int v) {
  int u_ult = findUltimateParent(u); // ultimate parent of u
  int v_ult = findUltimateParent(v); // ultimate parent of v

  if (rankArr[u_ult] < rankArr[v_ult]) parentArr[u_ult] = v_ult;
  else if (rankArr[u_ult] > rankArr[v_ult]) parentArr[v_ult] = u_ult;
  else {
    parentArr[v_ult] = u_ult;
    rankArr[u_ult] += 1;
  }
}

void bubbleSort (int edgeSize) {
  for (int i = 0 ; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize - i - 1; j++) { // Fixed the inner loop counter from 'i' to 'j'
      if (edgeArr[j+1] < edgeArr[j]) {
        int temp1 = edgeName[j];
        int temp2 = edgeArr[j];
        
        edgeName[j] = edgeName[j+1];
        edgeArr[j] = edgeArr[j+1];
        
        edgeName[j+1] = temp1;
        edgeArr[j+1] = temp2;
      }
    }
  }
}

void kruskal (int n, int edgeSize) {
  for (int i = 0; i < n; i++) {
    parentArr[i] = i;
  }
  
  bubbleSort(edgeSize);
  
  int totalWeight = 0; // Declare totalWeight outside the for loop
  for (int i = 0; i < edgeSize; i++) {
    int u = edgeName[i] / n; // Calculate the row (u)
    int v = edgeName[i] % n; // Calculate the column (v)

    if (edgeArr[i] == 0) continue;

    if (findUltimateParent(u) != findUltimateParent(v)) {
      cout << u << "->" << v << " with weight " << edgeArr[i] << endl; // Print the edge and its weight
      unionOf(u, v);
      totalWeight += edgeArr[i]; // Accumulate the total weight
    }
  }
  cout << "Total weight of the MST: " << totalWeight << endl; // Print the total weight of the MST
}


int main () {
  ifstream myFile("graph1.txt");

  if (!myFile) {
    cout << "Error reading file";
    return 1;
  }

  int n;
  myFile >> n;

  // redeclare arrays and matrices
  rankArr = new int [n]; // Initialize the arrays
  parentArr = new int [n];
  
  for (int i = 0; i < n; i++) {
    rankArr[i] = 0; // Initialize rankArr to 0
    parentArr[i] = i;
  }

  int edgeSize = n*(n-1)/2;
  edgeArr = new int [edgeSize];  // max no of edges of graph
  edgeName = new int [edgeSize];

  graphMatrix = new int*[n]; // we can't redeclare matrices directly... we need to do like this
  for (int i = 0; i < n; i++) graphMatrix[i] = new int [n];

  // reading file
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      myFile >> graphMatrix[i][j];
    }
  }

  // printing graph
  cout << "Graph is: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graphMatrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // creating edge matrix
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      edgeName[k] = i * n + j; // Store the edge as a single integer
      edgeArr[k] = graphMatrix[i][j];
      k++;
    }
  }

  // printing edge matrix
  cout << "Edge array is: " << endl;
  for (int i = 0; i < k; i++) {
    cout << edgeArr[i] << " ";
  }
  cout << endl;

  kruskal(n, edgeSize);

  // deleting all allocated memories
  delete[] rankArr;
  delete[] parentArr;
  delete[] edgeArr;
  delete[] edgeName;
  for (int i = 0; i < n; i++) delete[] graphMatrix[i];
  delete[] graphMatrix;
  myFile.close();

  return 0;
}


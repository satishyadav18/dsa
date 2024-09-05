#include<iostream>
#include<fstream>
using namespace std;
#define MAX 10

bool visited[MAX] = {false}; // all elements initially set to 0
int graph[MAX][MAX];

void dfs(int node, int n) {
  visited[node] = true;
  cout << node << " ";

  for (int i = 0; i < n; i++) {
    if(graph[node][i] && !visited[i]) { // only go to the unvisited neighbours
      dfs(i, n);
    }
  }
}

int main() {
  ifstream myFile("graph.txt");
  int n;
  myFile >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      myFile >> graph[i][j];
    }
  }

  myFile.close();

  cout << "The graph is: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }

  int start;
  cout << "Enter starting node: ";
  cin >> start;

  if (start >= n) {
    cout << "Start larger than graph size!" << endl;
    return 0;
  }

  dfs(start, n);

  return 0;
}
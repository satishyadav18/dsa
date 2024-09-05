#include <iostream>
using namespace std;
#include <climits>

#define MAX 9 // change this when the matrix is updated

int graph[MAX][MAX] = {
  {0, 4, 0, 0, 0, 0, 0, 8, 0},  
  {4, 0, 8, 0, 0, 0, 0, 11, 0},
  {0, 8, 0, 7, 0, 4, 0, 0, 2},  
  {0, 0, 7, 0, 9, 14, 0, 0, 0},
  {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
  {0, 0, 4, 14, 10, 0, 2, 0, 0},
  {0, 0, 0, 0, 0, 2, 0, 1, 6},  
  {8, 11, 0, 0, 0, 0, 1, 0, 7},
  {0, 0, 2, 0, 0, 0, 6, 7, 0}
};

int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, min_index;

  for (int i = 0; i < MAX; i++){
    if (!sptSet[i] && dist[i] <= min) {
      min = dist[i], min_index = i;
    }
  }

  return min_index;
}

void printSolution(int dist[], int start) {
  cout << "Start node is: " << start << endl;
  cout << "Vertex -> dist from start" << endl;
  for (int i = 0; i < MAX; i++) {
    cout << i << " -> " << dist[i] << endl;
  }
}

void dijkstra(int start) {
  int dist[MAX];
  bool sptSet[MAX];
  for (int i = 0; i < MAX; i++) {
    dist[i] = INT_MAX, sptSet[i] = false;
  }

  dist[start] = 0;

  for (int i = 0; i < MAX - 1; i++) {
    int u = minDistance(dist, sptSet);

    sptSet[u] = true;

    for (int v = 0; v < MAX; v++){
      if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printSolution(dist, start);
}

int main() {
  dijkstra(0);

  return 0;
}

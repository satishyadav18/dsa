#include <iostream>
using namespace std;
#define X 99999
#define MAX 4

int graph[MAX][MAX] = {
  {0, 3, X, 5},
  {2, 0, X, 4},
  {X, 1, 0, X},
  {X, X, 2, 0}
};

int dist[MAX][MAX];

int main () {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < MAX; k++) {
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        if ( dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (dist[i][j] == X) {
        cout << "X";
      }
      else {
        cout << dist[i][j];
      }
      cout << "\t";
    }
    cout << endl;
  }
}
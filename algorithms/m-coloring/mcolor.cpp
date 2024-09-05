#include<iostream>
#include<fstream>
using namespace std;
int graph[100][100];

void nextVal(int m, int n, int k, int ans[]) { // k is the current vertex considered for coloring
  do {
    ans[k] = (ans[k]+1) % (m+1);
    if (ans[k] == 0) return;

    int i;
    for (i = 0; i < k; i++) {
      if (graph[k][i] == 1 && ans[i] == ans[k]) {
        break;
      }
    }
    if (i == k) return;
  } while(true);
}

void mcolor(int m, int n, int k, int ans[]) { // k is the current vertex considered for coloring
  do {
    nextVal(m, n, k, ans);
    if (ans[k] == 0) return;
    if (k == n-1) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
    else {
      mcolor(m, n, k+1, ans);
    }
  } while(true);
}

int main () {
  ifstream myFile("graph.txt");
  if (!myFile) {
    cout << "Error opening file!!";
    return 1;
  }

  int m, n;
  myFile >> n; // no of vertex
  myFile >> m; // no of colors

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      myFile >> graph[i][j];
    }
  }

  myFile.close();

  cout << "Graph is: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }

  cout << "m is: " << m << " and n is: " << n << endl;

  int ans[n] = {0};

  cout << "Possible solutions are: " << endl;
  // n is the no of vertex
  // m is the no of colors
  // 0 is the initial value of k which is the current vertex considered for coloring
  mcolor(m, n, 0, ans);

  return 0;
}
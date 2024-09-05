// aka Kahn's algorithm
// follows the criteria- if there is an edge from a to b, a appears before b,
// always | ∀ (a,b) ∈ {vertex set} only valid for DAC (Directed Acyclic Graph)

#include <fstream>
#include <iostream>
using namespace std;
#define MAX 10

int inDegree[MAX] = {0};  // all elements initially set to 0
int graph[MAX][MAX];
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() { 
  return rear == -1 || front > rear; 
}

bool isFull() {
  int size = sizeof(queue) / sizeof(queue[0]);
  return rear == size - 1;
}

void enqueue(int data) {
  if (!isFull()) {
    if (front == -1) {
      front = 0;
    }

    queue[++rear] = data;
  }
}

void dequeue() {
  if (!isEmpty()) {
    front++;
  }
}

int peek() { 
  return queue[front]; 
}

void topoSort(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      inDegree[j] += graph[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
      enqueue(i);
    }
  }

  while (!isEmpty()) {
    int node = peek();
    cout << node << " ";
    dequeue();

    for (int i = 0; i < n; i++) {
      if (graph[node][i]) {  // Go to unvisited neighbors
        inDegree[i] -= 1;
        if (inDegree[i] == 0) {
          enqueue(i);
        }
      }
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

  cout << "Topo Sort is: " << endl;
  topoSort(n);

  return 0;
}
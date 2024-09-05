#include<iostream>
#include<fstream>
using namespace std;
#define MAX 10

bool visited[MAX] = {false}; // all elements initially set to 0
int graph[MAX][MAX];
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
  return rear == -1 || front > rear;
}

bool isFull() {
  int size = sizeof(queue)/sizeof(queue[0]);
  return rear == size - 1;
}

void enqueue(int data) {
  if(!isFull()){
    if (front == -1) {
      front = 0;
    }

    queue[++rear] = data;
  }
}

void dequeue() {
  if (!isEmpty()){
    front++;
  }
}

int peek() {
  return queue[front];
}

void bfs(int start, int n) {
  visited[start] = true;
  enqueue(start);

  while (!isEmpty()) {
    int node = peek();
    dequeue();
    cout << node << " ";
    for (int i = 0; i < n; i++) {
      if (graph[node][i] && !visited[i]) { // only go to unvisited neighbours
        visited[i] = true;
        enqueue(i);
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

  int start;
  cout << "Enter starting node: ";
  cin >> start;

  if (start >= n) {
    cout << "Start larger than graph size!" << endl;
    return 0;
  }

  bfs(start, n);

  return 0;
}
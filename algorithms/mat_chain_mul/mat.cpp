#include <iostream>
#include <climits>
using namespace std;
#define MAX 5

int input[MAX] = {1, 2, 3, 4, 3};
int m[MAX][MAX] = {0};
int s[MAX][MAX] = {0};

void chainMul() {
  int n = MAX - 1;  // Number of matrices
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int cost = m[i][k] + m[k + 1][j] + input[i - 1] * input[k] * input[j];
        if (cost < m[i][j]) {
          m[i][j] = cost;
          s[i][j] = k;
        }
      }
    }
  }
}

void printOptimalParentheses(int i, int j) {
  if (i == j) {
    cout << "A" << i;
  } else {
    cout << "(";
    printOptimalParentheses(i, s[i][j]);
    cout << " * ";
    printOptimalParentheses(s[i][j] + 1, j);
    cout << ")";
  }
}

int main() {
  chainMul();
  cout << "Optimal Parentheses: ";
  printOptimalParentheses(1, MAX - 1);
  cout << endl;
  cout << "Minimum Cost: " << m[1][MAX - 1] << endl;
  return 0;
}

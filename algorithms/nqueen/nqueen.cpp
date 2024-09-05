// neetcode- https://www.youtube.com/watch?v=Ph95IHmRp5M

#include <iostream>
#include <set>
using namespace std;
#define MAX 4 // size of board

// using set data structure to ensure that there is a unique element in it
set <int> cols; // to check if there is already a queen in the given column
set <int> posDiag; // to check if there is a queen in positive diagonal ie, bottom-left to top-right
set <int> negDiag; // to check if there is a queen in negative diagonal ie, top-left to bottom-right

int board[MAX][MAX] = {0};

void printBoard() {
  cout << "Solution:" << endl;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void nqueen(int r) {
  if (r == MAX) {
    printBoard();
    return;
  }

  for (int c = 0; c < MAX; c++) {
    if (cols.count(c) > 0 || posDiag.count(r+c) > 0 || negDiag.count(r-c) > 0) continue; // I didn't use .find() because it is more complicated than .count()
    
    cols.insert(c);
    posDiag.insert(r+c);
    negDiag.insert(r-c);
    board[r][c] = 1;

    nqueen(r+1);

    cols.erase(c);
    posDiag.erase(r+c);
    negDiag.erase(r-c);
    board[r][c] = 0; 
  }
}

int main () {
  nqueen(0);
  return 0;
}

/*

Output:


D:\sayan\Codes\dsa\algorithms>g++ nqueen.cpp

D:\sayan\Codes\dsa\algorithms>a.exe
Solution:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

Solution:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0


D:\sayan\Codes\dsa\algorithms>

*/

// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

void printm (vector<vector<bool>>& mat, int n, int m) { //prints truth board
  for (int i = 0; i < n; i++) {
    cout << i << ":";
    for (int j = 0; j < m; j++) {
      cout << " | " << mat[i][j];
    }
    cout << " | " << endl;
  }
}

void set_dame(vector<vector<bool>>& board, int n, int line, int col) {
  if (!board[line][col]) {
    printf("ERROR: Invalid postion!\n");
    return;
  }
  for (size_t i = 0; i < n; i++) { //block straight paths
    board[line][i] = false;
    board[i][col]  = false;
  }
  for (int i = 0; i <= n-1; i++) { //block diagonal paths
    if ( (line+i) < n  && (col+i) < n  ) board[line + i][col + i] = false;
    if ( (line+i) < n  && (col-i) >= 0 ) board[line + i][col - i] = false;
    if ( (line-i) >= 0 && (col-i) >= 0 ) board[line - i][col - i] = false;
    if ( (line-i) >= 0 && (col+i) < n  ) board[line - i][col + i] = false;
  }
}



int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  vector<bool>                  btemp;
  vector<vector<bool>>          board;
  vector<vector<vector<bool>>>  b_hist;     //[version][line][col]
  vector<int>                   stemp{0,0};
  vector<vector<int>>           sol;

  int     n = 8;
  int     line = 0;
  bool    could_place = false;

  for (size_t i = 0; i < n; i++) {  //ini board
    for (size_t j = 0; j < n; j++) {
      btemp.push_back(true);
    }
    board.push_back(btemp);
  }

  //Backtracking solution
  while (sol.size() < n) {
    printf("Sol size is %lu\n",sol.size() );
    could_place = false;
    b_hist.push_back(board);
    while (!could_place) {                    //hist

      for (size_t j = 0; j < n; j++) {      //col
        if (board[line][j]) {
          set_dame(board, n, line, j);
          could_place = true;
          stemp[0] = line;
          stemp[1] = j;
          sol.push_back(stemp);
        }

      }   //col loop end
    }       //hist loop end
  }

  cout << sol.size() << endl;
  printm(board,n,n);


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}


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

bool set_dame(vector<vector<bool>>& board, int n, int line, int col) {
  bool stat;
  if (!board[line][col]) {
    //printf("ERROR: Invalid postion!\n");
    return false;
  }
  for (size_t i = 0; i < n; i++) { //check straight paths
    if ( !board[line][i] ) stat = false;
    if ( !board[i][col]  ) stat = false;
  }
  for (int i = 0; i <= n-1; i++) { //check diagonal paths
    if ( !((line+i) < n  && (col+i) < n  ) ) stat = false;
    if ( !((line+i) < n  && (col-i) >= 0 ) ) stat = false;
    if ( !((line-i) >= 0 && (col-i) >= 0 ) ) stat = false;
    if ( !((line-i) >= 0 && (col+i) < n  ) ) stat = false;
  }
  return stat;
}

bool bt_algo (vector<vector<bool>> board, vector<int> sol, int n, int cn) {

}



int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  vector<bool>                  btemp;
  vector<vector<bool>>          board;
  vector<vector<vector<bool>>>  b_hist;     //[version][line][col]
  vector<int>                   stemp{0,0};
  vector<vector<int>>           sol;
  vector<vector<vector<int>>>   all_sol;

  int     n = 8;
  int     line = 0;
  bool    could_place = false;

  bool    backtracking = true;
  bool    bruteforce = false;

  for (size_t i = 0; i < n; i++) {  //ini board
    for (size_t j = 0; j < n; j++) {
      btemp.push_back(true);
    }
    board.push_back(btemp);
  }

  if (backtracking == true) {
  //Backtracking solution

  //if (bt_algo(board, 0) == false) {
  //    printf("Solution does not exist");
  //    return false;
  //}
  printm(board,n,n);
  }

  if (bruteforce == true) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        set_dame(board, n, line, j);
        could_place = true;
        stemp[0] = line;
        stemp[1] = j;
        sol.push_back(stemp);
      }
    }




  }

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

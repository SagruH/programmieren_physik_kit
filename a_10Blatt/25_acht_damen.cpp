
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
  cout << endl;
}

bool set_dame(vector<vector<bool>>& board, int n, int line, int col) {
  //cout << "dame" << endl; //DEBUG
  int i , j;

  if (!board[line][col]) return false;

  for (i = 0; i < col; i++) // str8
      if (!board[line][i])
        return false;
  for (i = line, j = col; i >= 0 && j >= 0; i--, j--) //diagonal up
    if (!board[i][j])
        return false;
  for (i = line, j = col; j >= 0 && i < n; i++, j--) // diagonal low
    if (!board[i][j])
        return false;

  return true;
}

bool bt_algo (vector<vector<bool>>& board, int n, int col) {
    //cout << "algo" << endl; //DEBUG

    if (col >= n) {
      printm  (board, n, n);
      return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
          //cout << i << endl; //DEBUG
        if ( set_dame(board, n, i, col) ) {
            board[i][col] = false;
            res = bt_algo(board, n, col + 1) || res;
            board[i][col] = true; // BACKTRACK
        }
    }
    return res;
}

void solve_queen() {
  vector<bool>                  btemp;
  vector<vector<bool>>          board;
  int                           n = 8; // can be easily changed, shoud work

  for (size_t i = 0; i < n; i++) {  //ini board
    for (size_t j = 0; j < n; j++) {
      btemp.push_back(true);
    }
    board.push_back(btemp);
  }

  if ( !bt_algo(board, n, 0) ) {
    printf("no sol");
    return ;
  }

return ;
}

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  //backtracking
  solve_queen();


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

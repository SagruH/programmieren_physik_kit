
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
  cout << "dame" << endl;
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
    cout << "algo" << endl;
    /* base case: If all queens are placed
      then return true */
    if (col >= n)
        return true;

    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < n; i++) {
        /* Check if the queen can be placed on
          board[i][col] */
          cout << i << endl;
        if (set_dame(board, n, i, col)) {
            /* Place this queen in board[i][col] */
            board[i][col] = false;

            /* recur to place rest of the queens */
            if (bt_algo(board, n, col + 1))
                return true;

            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = true; // BACKTRACK
        }
    }

    /* If the queen cannot be placed in any row in
        this colum col  then return false */
    return false;
}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  vector<bool>                  btemp;
  vector<vector<bool>>          board;
  int                           n = 4;

  for (size_t i = 0; i < n; i++) {  //ini board
    for (size_t j = 0; j < n; j++) {
      btemp.push_back(true);
    }
    board.push_back(btemp);
  }
  //backtracking
  bt_algo (board, n, 0);
  printm  (board, n, n);

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

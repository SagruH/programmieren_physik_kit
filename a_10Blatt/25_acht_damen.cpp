
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



int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int                   n = 8;
  vector<bool>          btemp;
  vector<vector<bool>>  board;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      btemp.push_back(true);
    }
    board.push_back(btemp);
  }

  printm(board,n,n);


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

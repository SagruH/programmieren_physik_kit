
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<double>> readfile(string filename, int n) { //columns ; lines
  fstream ffile;
  ffile.open(filename, ios::in);
  double a;
  int i=0, j=0;
  vector<vector <double>> content;
  vector<double> temp;

  while (ffile >> a) {
    temp.push_back(a);
    i++;
    if (i==n) {
      i=0;
      content.push_back(temp);
      temp.clear();
    }
  }

  ffile.close();
  return content;
}



int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  vector<vector<double>> a_matrix;
  a_matrix = readfile("a13-lgs1.dat",8);
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 9; j++) {
      cout << " " << a_matrix[i][j] << " ";
    }
    cout << endl;
  }







  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

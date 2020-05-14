
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <vector>


using namespace std;

int readfile(string filename, int n, int l) { //columns ; lines
  fstream ffile;
  ffile.open(filename, ios::in);

  int a;
  int i=0;
  int j=0;
  int content[n][l] = {0};

  while (ffile >> a) {
    content[i][j] = a;
    i++;
    if (i==n) {
      i=0;
      j++;
    }
  }

  ffile.close();
  return 0;
}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  /*
  int col = 11;
  int l = 7;
  int content[col][l] = {0};
  content = readfile("a11-toredat.sec",col,l);
  */


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

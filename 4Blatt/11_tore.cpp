
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <vector>


using namespace std;

vector<vector<int>> readfile(string filename, int n) { //columns ; lines
  fstream ffile;
  ffile.open(filename, ios::in);
  int a;
  int i=0, j=0;
  vector<vector <int>> content;
  vector<int> temp;

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

  int col = 11;
  vector<vector <int>> content;
  content = readfile("a11-toredat.sec",col);
  cout << content[0][0];


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

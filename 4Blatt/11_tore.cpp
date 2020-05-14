
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>


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

  //ini and read file to 2d vector
  int col = 11;
  int l = 7;
  int g = 0;
  vector<vector <int>> content;
  content = readfile("a11-toredat.sec",col);

  //sum of goals and max
  vector<int> goals;
  for (size_t i = 0; i < l; i++) {
    for (size_t j = 1; j < col; j++) {
      g += content[i][j];
    }
    goals.push_back(g);
    g = 0;
  }

  int max = *max_element(goals.begin(), goals.end());

  //Output
  printf("TEAM  ||             GOALS               || SUM");
  printf("\n------------------------------------------------------------");
  for (size_t i = 0; i < l; i++) {
    printf("\n%i  ||  ",content[i][0] );
    for (size_t j = 1; j < col; j++) {
      printf(" %i ",content[i][j] );
    }
    printf(" || %i | ",goals[i] );
    if (goals[i] == max) printf("CHAMPION!");
  }

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

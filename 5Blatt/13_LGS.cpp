
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

//@Tutor
//Die Datei wurde minimal verändert um die Funktion aus Aufgabe 11 verwenden zu können.
//Bitte die Angehängte Datei benutzen. ( Es wurden die Zeile mit der Spaltenanzahl entfernt. )

//Funktion zum Datei einlesen
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

//gibt LGS aus
void printLGS(vector<vector<double>> matrix, int n, int m) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      printf("  %5g  ",matrix[i][j] );
      if (j == (m-1)) printf(" | %5g\n",matrix[n][i] );
    }
  }
}

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  vector<vector<double>> a_matrix;

  a_matrix = readfile("a13-lgs1.dat",8);
  printLGS(a_matrix,8,8);







  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

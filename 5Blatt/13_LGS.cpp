
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm> //transform fill
#include <functional> // multiplies

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
  printf("-----   LGS   -----\n");
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      printf("  %5g  ",matrix[i][j] );
      if (j == (m-1)) printf(" | %6g\n",matrix[n][i] );
    }
  }
}
// Einführung von Matrix operationen
//multipliziert zeile a mit x und addiert auf zeile b, gibt ganze Matrix zurück
vector<vector<double>> matrix_line_add(vector<vector<double>> matrix, int a, int b, double x) {
  int rl = 8;
  vector<double> aline = matrix[a];
  vector<double> bline = matrix[b];
  aline.push_back(matrix[rl][a]);
  bline.push_back(matrix[rl][b]);
  vector<double> xline (rl+1);
  fill(xline.begin(), xline.end(), x);

  //(aline * x) + bline = matrix[b]
  transform(aline.begin(), aline.end(), xline.begin(), aline.begin(), multiplies<double>());
  transform(aline.begin(), aline.end(), bline.begin(), bline.begin(), plus<double>());
  matrix[rl][b] = bline[rl];
  bline.pop_back();
  cout << bline[rl]<< endl;
  matrix[b] = bline;
  //DEBUG
  /*
  for (size_t i = 0; i < 9; i++) {cout << aline[i] << " ";}
  cout << endl;
  for (size_t i = 0; i < 9; i++) {cout << bline[i] << " ";}
  cout << endl;
  for (size_t i = 0; i < 9; i++) {cout << xline[i] << " ";}
  cout << endl;
  */
  return matrix;
}
//Zeilentausch
vector<vector<double>> line_swap(vector<vector<double>> matrix, int a, int b) {
  swap(matrix[a],matrix[b]);
  swap(matrix[8][a],matrix[8][b]);
  return matrix;
}


int main(int argc, char const *argv[]) {
  //Pivotiserungs abfrage
  cout << "Mit Pivotisierung? (y / n)";
  string pv;
  cin >> pv;
  int pivot = pv=="y" ? 1 : pv=="n" ? 0 : 2;
  if (pivot == 2) {
    cout << "Das werte ich mal als nein...\n\n";
    pivot = 0;
  }

  auto t_start = chrono::high_resolution_clock::now();
  vector<vector<double>> a_matrix;

  a_matrix = readfile("a13-lgs1.dat",8);
  printLGS(a_matrix,8,8);

  //Dreiecksform



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}


// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm> //transform fill
#include <functional> // multiplies
#include <tuple>

using namespace std;

//Funktion zum Datei einlesen
tuple<vector<vector<double>>, int> readfile(string filename) { //columns ; lines
  fstream ffile;
  ffile.open(filename, ios::in);
  double a;
  int i=0, j=0;
  vector<vector <double>> content;
  vector<double> temp;
  int is_n = 1;
  int n;
  while (ffile >> a) {
    if (is_n==1) {
      is_n=0;
      n = a;
    } else {
    temp.push_back(a);
    i++;
    if (i==n) {
      i=0;
      content.push_back(temp);
      temp.clear();
    }
    }
  }

  ffile.close();
  return make_tuple(content, n);
}

//gibt LGS aus
void printLGS(vector<vector<double>> matrix, int n, int m) {
  printf("-----   LGS   -----\n");
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      printf("  %8g  ",matrix[i][j] );
      if (j == (m-1)) printf(" | %6g\n",matrix[n][i] );
    }
  }
}
// Einführung von matrix operationen
//multipliziert zeile a mit x und addiert auf zeile b, gibt ganze Matrix zurück
vector<vector<double>> line_add(vector<vector<double>> matrix,
                                        int n, int a, int b, double x) {
  int rl = n;
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
vector<vector<double>> line_swap(vector<vector<double>> matrix, int n, int a, int b) {
  swap(matrix[a],matrix[b]);
  swap(matrix[n][a],matrix[n][b]);
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
  int n;
  double x;

  tie(a_matrix, n) = readfile("a13-lgs1.dat");
  printLGS(a_matrix,n,n);
  //Dreiecksform
  if (pivot == 0) {
    //bringt auf Dreiecksform
    for (size_t i = 0; i < n; i++) {
      //cout << "i " << i << endl; //DEBUG
      for (size_t j = (i+1); j < (n); j++) {
        x = (a_matrix[j][i])/((double)a_matrix[i][i]);
        x *= -1;
        a_matrix = line_add(a_matrix, n, i, j, x);
        //printLGS(a_matrix,n,n); // DEBUG
        //cout << "j " << j << " x " << x << endl; //DEBUG
      }
    }
    //Korrektur float additions fehler
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        double s = 1/(pow(10,12));
        if ((abs(a_matrix[i][j]) <= s)&&(abs(a_matrix[i][j])>0)) {
          a_matrix[i][j] = 0;
        }
      }
    }
  } else if (pivot == 1) {

  } else {
    printf("ERROR! (pivot) \n");
  }

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

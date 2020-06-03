
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

//known functions:
void printMatrix(vector<vector<double>> matrix, int n, int m);
vector<vector<double>> readfile(string filename, int n);

//new function(s):
double interpolynom(vector<vector<double>> &data, int n, double x){
  double fx = 0;
  double xi, xk;
  double li;

  for (int i = 0; i < n; i++) {
    //calc Lagrage interpol
    li = 1;
    xi = data[i][0];
    for (int k = 0; k < n; k++) {
      xk = data[k][0];
      li = k == i ? li : li*((x-xk)/(xi-xk));
    }
  //calc f(x)
  fx += data[i][1]*li;
  }
  return fx;
}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  double x;
  double fx;
  int n = 12;
  string filename = "a16-interpol.dat";
  vector<vector<double>> given_data = readfile(filename, 2);

  printf("Given data points:\n");
  printMatrix(given_data, 2, n);
  printf("\n\nEnter x.\nTo exit the program enter 0.\n");
  cin >> x;

  fstream output;
  output.open("a16-interpol-res.dat", ios::app);

  while (x != 0) {
    fx = interpolynom(given_data, n, x);
    printf("\nf(%g) = %8g\n", x, fx);

    output << x << "," << fx << endl;

    printf("Enter new x:  ");
    cin >> x;
    }

  output.close();

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}



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

void printMatrix(vector<vector<double>> matrix, int m, int n) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cout << " " << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

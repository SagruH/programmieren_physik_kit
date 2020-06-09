
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

//new functions
//Berechnung von M
vector<double> M_calc(vector<vector<double>>& data, int n){
  vector<double> x = data[0];
  vector<double> y = data[1];

  vector<double> lambdaj, myj, dj;
  double temp, temp1, temp2, temp3;

  double lambda0 ,myn, d0, dn;
  lambda0 = myn = d0 = dn = 0;
  double my0 = 2;

  vector<double> myi, di;
  double t_f, tempmy, tempd;

  vector<double> M_i(n+1);

  //lambdaj
  lambdaj.push_back(lambda0);
  for (int j = 1; j <= n-1; j++) {
    temp = (x[j+1] - x[j])/(x[j+1] - x[j-1]);
    lambdaj.push_back(temp);
  }
  //lambdaj.push_back(1312); //DEBUG

  //myj
  myj.push_back(my0);
  for (int j = 1; j <= n-1; j++) {
    temp = (x[j] - x[j-1])/(x[j+1] - x[j-1]);
    myj.push_back(temp);
  }
  myj.push_back(myn);

  //dj
  dj.push_back(d0);
  for (int j = 1; j <= n-1; j++) {
    temp1 = 6/(x[j+1]-x[j-1]);
    temp2 = (y[j+1] - y[j])/(x[j+1] - x[j]);
    temp3 = (y[j] - y[j-1])/(x[j] - x[j-1]);
    temp = temp1*(temp2-temp3);
    dj.push_back(temp);
  }
  dj.push_back(dn);

  /*  //DEBUG
  for (size_t i = 0; i <= n; i++) {
    printf("l: %9g  m: %9g  d: %9g\n",lambdaj[i], myj[i], dj[i] );
  }
  */

  //myi & di
  myi.push_back(my0);
  di.push_back(d0);
  for (int i = 1; i <= n; i++) {
    t_f = -myj[i]/myj[i-1];
    tempmy = 2+t_f*lambdaj[i-1];

    tempd = dj[i] + t_f*dj[i-1];
    myi.push_back(tempmy);
    di.push_back(tempd);
  }

  //M
  M_i[n] = di[n]/myi[n];
  for (int i = n-1; i >= 0; i--) {
    M_i[i] = (di[i]-lambdaj[i]*M_i[i+1])/myi[i];
  }

   //DEBUG
  for (int i = 0; i <= n; i++) {
    printf("%2i:  M: %12g  m: %12g  d: %12g\n",i , M_i[i], myi[i], di[i] );
  }


  return M_i;
}

double S_Delta(vector<vector<double>>& data, int n,vector<double>& M){
  double Sx;
  vector<double> x = data[0];
  vector<double> y = data[1];


  return Sx;
}



int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int n = 12;
  vector<double> x, y;
  vector<vector<double>> data;
  vector<double> M_i;

  //print out given .dat file
  string filename = "a16-interpol.dat";
  vector<vector<double>> given_data = readfile(filename, 2);
  printf("Given data points:\n");
  printMatrix(given_data, 2, n);

  //given_data to data (changes format)
  for (size_t i = 0; i < n; i++) {
    x.push_back(given_data[i][0]);
  }
  for (size_t i = 0; i < n; i++) {
    y.push_back(given_data[i][1]);
  }
  data.push_back(x);
  data.push_back(y);

  M_i = M_calc(data,n); // berechnet den Vector Mi





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

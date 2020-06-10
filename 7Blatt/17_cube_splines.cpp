
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
vector<double> M_calc(vector<vector<double>>& data, int n) {
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
  myi = myj;
  di = dj;
  for (int i = 1; i <= n; i++) {
    t_f = -myi[i]/myi[i-1];
    tempmy = 2+t_f*lambdaj[i-1];
    tempd = di[i] + t_f*di[i-1];
    myi[i] = tempmy;
    di[i] = tempd;
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

double S_Delta(vector<vector<double>>& data, int n,vector<double>& M, double x_in) {
  double Sy;
  double alpha, beta, gamma, delta;
  double tb1,tb2,tb3;
  vector<double> x = data[0];
  vector<double> y = data[1];
  int j;
  if ((x_in < x[0] || x_in > x[n-1])) {
    printf("ERROR x not in interval!\n");
    return 0;
  }
  //find j
  for (int i = 0; i < n; i++) {
    if ((x_in >= x[i]) && (x_in <= x[i+1])) j = i;
  }

  alpha = y[j];
  tb1 = (y[j+1] - y[j])/(x[j+1] - x[j]);
  tb2 = (2*M[j] + M[j+1])/6;
  tb3 = x[j+1] - x[j];
  beta = tb1 - tb2*tb3;
  gamma = M[j]/2;
  delta = (M[j+1] - M[j])/(6*(x[j+1] - x[j]));

  Sy = alpha + beta*(x_in-x[j]) + gamma*pow((x_in-x[j]),2) + delta*pow((x_in-x[j]),3);

  return Sy;
}

// copy pasted from https://gist.github.com/mortenpi/f20a93c8ed3ee7785e65#gistcomment-2362409
// Linear interpolation following MATLAB linspace
std::vector<double> LinearSpacedArray(double a, double b, std::size_t N) {
  double h = (b - a) / static_cast<double>(N-1);
  std::vector<double> xs(N);
  std::vector<double>::iterator x;
  double val;
    for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h) {
        *x = val;
    }
    return xs;
  }


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int n = 12;
  int equi_n = 300;
  int plot = 1;
  double x_in, Sy;
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

  // berechnet den Vector Mi
  M_i = M_calc(data,n);
  printf("Create Output file for n equidistant x values between %g and %g\n",x[0], x[n-1]);
  printf("Enter n:  ");
  //cin >> equi_n;


  //calc S for 300 equi-distant x values and outputs in file
  vector<double> linspace_vec = LinearSpacedArray(x[0], x[n-1], equi_n);
  fstream output;
  output.open("a17-cube-spline-res.dat", ios::out);
  for (size_t i = 0; i < equi_n; i++) {
    x_in = linspace_vec[i];
    Sy = S_Delta(data, n, M_i, x_in);
    output << x_in << "," << Sy << endl;
  }
  output.close();

  //opens plot
  printf("\nTo plot with python3 press 1, else press 0\n");
  printf("Requirements: Linux with Python3, numpy and matplotlib\n");
  //cin >> plot;
  if(plot == 1) system("python3 create_plot.py");

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

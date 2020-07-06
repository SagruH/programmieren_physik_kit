
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

double test_func1 (double x) {
  return cos(x) - x;
}
double test_func2 (double x) {
  return exp(x) - pow(x, 3);
}

double nullstellen (double (*f)(double), double x0, double x1, double epsx, double epsf) {
  double x_test;

  if( (f(x0) > 0 && f(x1) > 0) || (f(x0) < 0 && f(x1) < 0) ) {
    printf("Keine Nullstelle im Intervall.\n");
    return 1;
  }
  if ( f(x0 > 0) ) { //x0 immer kleiner 0, x1 immer größer 0
    double t = x1;
    x1 = x0;
    x0 = t;
  }



}

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  double f1x0  = -10.0;
  double f1x1  = 10.0;
  double f2x0  = 2.0;
  double f2x1  = 10;
  double ns1, ns2;

  double epsx = 1.0/pow(10,4);
  double epsf = 1.0/pow(10,3);

  double (*funcPtr)(double) { test_func1 };

  ns1 = nullstellen(funcPtr, f1x0, f1x1, epsx, epsf);
  cout << ns1 << endl;

  //code



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}


// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  double x = 1, e = 2, xe;
  int i = -1;

  do {

    e = e/2;
    xe = x+e;
    i++;

  } while(x != xe);

  cout << "1 + \u03B5 \u2260 1 bis \u03B5 = "
  << 2*e << " Dies ist nach " << i << " halbierungen erreicht.\n";

  // epsilon ist \u03B5 ; ungleich zeichen inst \u2260


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

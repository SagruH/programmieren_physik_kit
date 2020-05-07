
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;

int binom_co(int n, int k) {
  int sol;
  if (k == 0 || n == k) {
    return 1;
  } else {
    return (binom_co(n-1 , k-1 ) + binom_co(n-1 , k));
  }
}

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int line = 10;
  int sol = binom_co(8,6);

  cout << sol << endl;


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

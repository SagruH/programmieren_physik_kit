
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;


int main(int argc, char const *argv[]) {


  int base, n;

  cout << "Count in Base: ";
  cin >> base;
  cout << "Count till (input in Base 10): ";
  cin >> n;
  auto t_start = chrono::high_resolution_clock::now(); //runtime after user input

  for (int i = 0; i <= n; i++) {
    /* code */
  }

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

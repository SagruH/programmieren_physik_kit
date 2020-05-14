
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>


using namespace std;


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  fstream goalfile("a11-toredat.sec", ios_base::in);
  int a;
  while (goalfile >> a) {
    printf("%i ", a);
  }

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

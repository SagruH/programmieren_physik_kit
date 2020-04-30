
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int produkt = 1, n;

  cout << "Enter N: ";
  cin >> n;

  for(int i = 1 ; i<=n ; i++) {
    cout << "For i = " << i-1 << " : Produkt = " << produkt << endl;
    produkt = produkt * (3*i - 1);
  }

  cout << "Final product = " << produkt << endl;

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

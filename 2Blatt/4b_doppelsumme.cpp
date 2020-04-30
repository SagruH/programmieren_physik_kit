
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  double summe = 0, n;

  cout << "--- Doppelsumme ---" << endl << "Enter N: ";
  cin >> n;

  for(int i = 1 ; i <= n ; i++) {
    //cout << i << endl; //debug
    for(int j = 1 ; j <= i ; j++) {
      summe = summe + (1.0/(i*j)); //prevent int / int --> 1.0 not 1
      //cout << j << " // " << summe << endl; //debug
    }
  }

  cout << "Die Doppelsumme mit N = " << n << " ist " << summe << "." << endl;

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

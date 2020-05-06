
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;


int main(int argc, char const *argv[]) {
  double a, b, c;
  double mittel;

  printf("Gib drei verschiedene Zahlen ein: \n");
  cin >> a;
  cin >> b;
  cin >> c;

  auto t_start = chrono::high_resolution_clock::now();

  if (num[0]) {
    /* code */
  } else if (/* condition */) {
    /* code */
  } else {
    /* code */
  }



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

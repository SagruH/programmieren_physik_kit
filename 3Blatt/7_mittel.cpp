
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

  if (a==b || a==c || b==c ) {
    printf("ERROR: Gib 3 VERSCHIEDENE Zahlen ein!\n" );
    return 0;
  } else if ((a<b && a>c) || (a>b && a<c)) {
    mittel = a;
  } else if ((a<b && b<c) || (a>b && b>c)) {
    mittel = b;
  } else if ((c<b && a<c) || (c>b && a>c)) {
    mittel = c;
  } else {
    cout << "ERROR" << '\n';
  }

  printf("Die mittlere Zahl ist: %f .\n",mittel);

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

  double x,sol;

  cout << "Enter x in e^x: ";
  cin >> x;

  sol = exp(x);

  cout << "e^x = " << sol << endl;
  return 0;
}

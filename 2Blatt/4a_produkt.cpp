#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

  int produkt = 1, n;

  cout << "Enter N: ";
  cin >> n;

  for(int i = 1 ; i<=n ; i++) {

    cout << "For i = " << i-1 << " : Produkt = " << produkt << endl;
    produkt = produkt * (3*i - 1);

  }

  cout << "Final product = " << produkt << endl;

  return 0;
}

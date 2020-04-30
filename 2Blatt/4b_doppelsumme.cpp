#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

  double summe = 0, n;

  cout << "--- Doppelsumme ---" << endl << "Enter N: ";
  cin >> n;

  for(int i = 1 ; i <= n ; i++){
    //cout << i << endl; //debug
    for(int j = 1 ; j <= i ; j++){

      summe = summe + (1.0/(i*j)); //prevent int / int --> 1.0 not 1
      //cout << j << " // " << summe << endl; //debug
    }
  }

  cout << "Die Doppelsumme mit N = " << n << " ist " << summe << "." << endl;

  return 0;
}

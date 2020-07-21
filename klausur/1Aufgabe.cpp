
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>

using namespace std;

void printa( int a[], int n) {  //Func zur ausgabe eines arrays
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}


int main(int argc, char const *argv[]) {
  //ini
  int n = 10;
  int temp;
  int aint[n] = {1,2,3,4,5,6,7,8,9,10};
  cout << "Erstes Array\n";
  printa(aint, n);
  //Tausche werte
  for (int i = 0; i < n/2; i++) {
    temp = aint[n-1-i];
    aint[n-1-i] = aint[i];
    aint[i] = temp;
  }
  cout << "Zweites Array\n";
  printa(aint, n);





  return 0;
}

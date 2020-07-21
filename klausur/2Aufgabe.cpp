
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>

using namespace std;


bool isprim(int x) { // testet ob primzahl
  for (int i = 2; i < x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void testprim(int a, int b) { //geht alle zahlen im intervall durch
  for (int i = a; i <= b; i++) {
    if (isprim(i)) cout << i << " ";
  }
}


int main(int argc, char const *argv[]) {
  testprim(8, 35);

  cout << endl;
  return 0;
}

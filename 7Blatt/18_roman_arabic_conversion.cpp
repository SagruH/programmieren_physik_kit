
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <string>
#include <cctype>
#include <vector>



using namespace std;

int valrom(char& rom) {
  if        (rom == 'M') {
    return 1000;
  } else if (rom == 'D') {
    return 500;
  } else if (rom == 'C') {
    return 100;
  } else if (rom == 'L') {
    return 50;
  } else if (rom == 'X') {
    return 10;
  } else if (rom == 'V') {
    return 5;
  } else if (rom == 'I') {
    return 1;
}
}

char to_upper (char rom) {
  return rom &= ~' ';
}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int mode, n;
  int res = 0;
  int arab_num;
  string rom_num;
  char ct;
  vector<int> vals;

  printf("roman --> arabic (1)\narabic --> roman (2)\n");
  cin >> mode;
  if (mode == 1) { //rom -> arab
    printf("Enter Number: ");
    //cin >> rom_num;
    cout << endl;
    //rom_num = "McCXlvI"; // DEBUG
    n = rom_num.length();
    //convert to upper case and push values of numeral in vector
    for (size_t i = 0; i < n; i++) {
      ct = to_upper(rom_num[i]);
      rom_num[i] = ct;
      vals.push_back(valrom(ct));
    }
    //left subtaction
    for (int i = n-1; i >= 0; i--) {
      if (i == n-1) {
        res += vals[i];
      } else if (vals[i] >= vals[i+1]) {
        res += vals[i];
      } else if (vals[i] < vals[i+1]) {
        res -= vals[i];
      }
    }
    cout << res << endl;


  } else if (mode == 2) { // arab --> rom
    printf("Enter Number: ");
    cin >> arab_num;



  } else {
    printf("ERROR");
  }



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

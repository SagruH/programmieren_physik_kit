
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <string>

using namespace std;


string base_converter(int div, int base) {
  string r_str, baseXnum = "";
  int r;
  cout << "div  " << div << endl;
  do {
    div = div / base;
    r = div % base;

    if (r==0) { break; }


    r_str = to_string(r);
    cout << "r_str  " <<  r_str << endl;
    baseXnum = r_str + baseXnum;
    cout << "baseXnum  " << baseXnum << endl;
  } while(r != 0);

  return baseXnum;
}

int main(int argc, char const *argv[]) {
  int base, n;
  string baseXnum;

  cout << "Count in Base: ";
  cin >> base;
  cout << "Count till (input in Base 10): ";
  cin >> n;
  auto t_start = chrono::high_resolution_clock::now(); //runtime after user input

  for (int i = 0; i <= n; i++) {
    if (i==0) { baseXnum = "0"; }
    else {
    baseXnum = base_converter(i,base);
    }

    cout << baseXnum << "[" << base << "]  =  " << i << "[10]" << endl;
  }

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

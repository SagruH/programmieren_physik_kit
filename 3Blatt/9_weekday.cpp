
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;

short ly_test(int y) { //Leap year test

  short leap_year = 0;
  if (((y%100) != 0) && ((y%4) == 0)) {
      leap_year = 1;
  }
  if (y%400 == 0) {
    leap_year = 1;
  }
  return leap_year;
}

int main(int argc, char const *argv[]) {
  int d,m,y;
  printf("---Date to Weekday converter---\n Enter Date: DD/MM/YYYY \n");
  cin >> d >> m >> y;

  auto t_start = chrono::high_resolution_clock::now();
  //ERROR TESTS
  short in_y = ly_test(y);
  if ((d >= 32) || (m >= 12)) {
    printf("Invalid date!\n");
    return 0;
  } else if ((m == 2) && (((d > 29) && (in_y == 1)) || ((d > 28) && (in_y == 0)))) {
    printf("Invalid date!\n");
    return 0;
  } else if ((m == (4,6,9,11)) && (d >= 31)) {
    printf("Invalid date!\n");
    return 0;
  } else if (y <= 1581) {
    printf("Date before Gregorian calendar.\n");
  }

  //referenz daturm 1.1.2018
  string weekdays[7] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};




  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

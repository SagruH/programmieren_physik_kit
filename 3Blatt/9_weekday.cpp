
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
  int dsr = 0; //days since reference
  printf("---Date to Weekday converter---\n Enter Date: DD/MM/YYYY \n");
  cin >> d >> m >> y;

  auto t_start = chrono::high_resolution_clock::now();
  //ERROR TESTS
  short in_y = ly_test(y);
  if ((d >= 32) || (m >= 12)) {
    printf("Invalid date!\n Too many days / months.\n");
    return 0;
  } else if ((m == 2) && (((d > 29) && (in_y == 1)) || ((d > 28) && (in_y == 0)))) {
    printf("Invalid date!\n February has less days.\n");
    return 0;
  } else if (((m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d >= 31)) {
    printf("Invalid date!\n This month has only 30 days.\n");
    return 0;
  } else if (y <= 1581) {
    printf("Date before Gregorian calendar.\n");
  }

  //reference date 1.1.2018
  string weekdays[7] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag"};

  dsr += d;
  m--;
  while (m>=1) {
    if(m == 1) dsr += 31;
    if((m == 2) && (in_y == 1)) dsr += 29;
    if((m == 2) && (in_y == 0)) dsr += 28;
    if(m == 3) dsr += 31;
    if(m == 4) dsr += 30;
    if(m == 5) dsr += 31;
    if(m == 6) dsr += 30;
    if(m == 7) dsr += 31;
    if(m == 8) dsr += 31;
    if(m == 9) dsr += 30;
    if(m == 10) dsr += 31;
    if(m == 11) dsr += 30;
    if(m == 12) dsr += 31;
    m--;
  }

  printf("%d\n",dsr );

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}


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
  if ((d > 31) || (m > 12)) {
    printf("Invalid date!\n Too many days / months.\n");
    return 0;
  } else if ((m == 2) && (((d > 29) && (in_y == 1)) || ((d > 28) && (in_y == 0)))) {
    printf("Invalid date!\n February has less days.\n");
    return 0;
  } else if (((m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d >= 31)) {
    printf("Invalid date!\n This month has only 30 days.\n");
    return 0;
  } else if (y < 1871) {
    printf("Year to small. Choose a Date later then 1870.\n");
    printf("Date before Gregorian calendar in Germany.\n");
    return 0;
  }

  //reference date 1.1.1871 (Formation of German Empire)
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

  int dy = 1871 - y;
  dy *= (-1);
  for (int i = 0; i < dy; i++) {
    if (dy < 0) {
      y--;
    } else {
      y++;
    }
    short is_ly = ly_test(y);
    if (is_ly == 1) {
      dsr += 366;
    } else {
      dsr += 365;
    }
  }

  dsr--;
  int day_index = dsr % 7;
  if(day_index-1 == -1) day_index = 7;
  string day = weekdays[day_index-1];
  cout << day << endl;

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

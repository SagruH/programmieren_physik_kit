
// github: https://github.com/SagruH/programmieren_physik_kit

//@Tutor mir ist ja wirklich ein Rätsel wo

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

int qsum_calc(unsigned long long int a) {
  int sum = 0;
  while (a > 0) {
    sum += a % 10;
    a /= 10;
  }
  return sum;
}

//@Tutor mir ist ja wirklich ein Rätsel wie ich die Quersumme rekursiv bilden soll
//für die reduzierte Quersumme klar aber für die normale...
int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  unsigned long long int num;
  int red_qsum;
  int i = 1;
  printf("Gib eine ganze Zahl größer 0 ein: ");
  cin >> num;
  cout << endl;

  int qsum = qsum_calc(num);
  printf("Die Quersumme von %llu ist %i.\n\n",num, qsum );

  red_qsum = qsum;
  while (red_qsum >= 10) {
    red_qsum = qsum_calc(red_qsum);
    printf("Die %i-fach reduzierte Quersumme von %llu ist %i.\n",i, num, red_qsum );
    i++;
  }

  printf("\nDie reduzierte Quersumme von %llu ist %i.\n",num, red_qsum );


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

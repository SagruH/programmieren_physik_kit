
// github: https://github.com/SagruH/programmieren_physik_kit

//Excepts n as parameter in commandline

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

void tower(int a, char from , char aux, char to) {
  if (a == 1) {
    printf("Move disk from %c to %c\n", from , to);
    return;
  } else {
    tower(a-1, from, to, aux);
    printf("Move disk from %c to %c\n", from , to);
    tower(a-1, aux, from, to);
  }
}


int main(int argc, char const *argv[]) {
  //input
  int n;
  if (argc <= 1) {
    printf("Enter n: ");
    cin >> n;
    cout << endl;
  } else if (argc == 2) {
    n = atoi(argv[1]);
    if (n == 0) {
      printf("Invalid argument!\n");
      return 0;
    }
    printf("n was given as parameter.\nn = %i\n",n );
  } else {
    cout << "Too many arguments!" << endl;
    return 0;
  }
  //programm starts
  auto t_start = chrono::high_resolution_clock::now();

  unsigned long long int steps = pow(2,n)-1;
  printf("For (n = %i) %llu moves are expected.\n\n", n, steps);

  if (n>63) {
    printf("n to large\n");
    return 0;
  }
  if (n>23) {
    printf("Long runtime expected.\nDo you really want to continue with n = %i? (y/n)",n );
    char cont;
    cin >> cont;
    if (cont != 'y') return 0;
  }

  tower(n, 'A', 'B', 'C');




  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

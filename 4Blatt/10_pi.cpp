
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char const *argv[]) {
  printf("Enter n: \n");
  int n;
  int in=0, out=0; //inside outside of circle
  double rx,ry;
  cin >> n;

  auto t_start = chrono::high_resolution_clock::now();

  srand(time(NULL));
  cout << endl << "The following two Numbers should be equal.\n" <<
                  "If they are not equal, accuracy will may be lower.\n";
  cout << "RAND_MAX:   " << RAND_MAX << endl;
  cout << "INT32_MAX:   " << INT32_MAX << endl << endl;

  for (size_t i = 0; i < n; i++) {
    rx = ((double) rand()/RAND_MAX);
    ry = ((double) rand()/RAND_MAX);

    if ((pow(rx,2) + pow(ry,2)) <= 1) {
      in++;
    } else {
      out++;
    }
  }
  if (out == 0) printf("Please Enter bigger n.\n");
  double ratio = in/(double)n;
  printf("The ratio of numbers within the circle %i and n %i is: %f.\n",in , out, ratio);
  double my_pi = 4* ratio;
  printf("This ratio times 4 (= %f)\n will approach \u03C0 for bigger n.\n \u03C0 = ", my_pi);
  cout << M_PI << endl;

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

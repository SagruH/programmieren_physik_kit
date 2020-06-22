
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

class ratio {
  long z;
  long n;
public:
  ratio(long z1 ,long n1) {
    z = z1;
    n = n1;
  }


};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();




  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

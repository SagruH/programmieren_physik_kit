
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

class ratio_num { //ratio is ambiguous
  long z;
  long n;
public:
  ratio_num(long z1 ,long n1) { //constuctor
    z = z1;
    n = n1;
  }
  void kuerzen() {
    //!TODO
  }
  void out() {
    printf("%li/%li",z,n );
  }
  double tof() {
    return z/(double)n;
  }
};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  ratio_num a(5,10);
  a.out();
  cout << endl << a.tof() << endl;



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}


// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

//die class existiert schon als std::normal_distribution :(
//aber ich hab so das gefühl das die Aufgaben älter sind als C++11 =D
class normal_generator {
  bool stat;
  double num1, num2;

  void num_gen() {
    double v1, v2;
    double s;
    do {
      v1 = 2.0*rand() / (double)RAND_MAX - 1;
      v2 = 2.0*rand() / (double)RAND_MAX - 1;
      s = pow(v1,2) + pow(v2,2);
    } while( (s >= 1) || (s == 0) );
    num1 = v1 * sqrt( (-2* log(s) )/s );
    num2 = v2 * sqrt( (-2* log(s) )/s );
  }
public:
  normal_generator(){
    stat = false;
  }

  double get() {
    if (stat) {
      stat = false;
      return num2;
    } else {
      num_gen();
      stat = true;
      return num1;
    }
  }
};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  srand(time(NULL));
  
  normal_generator gen1;
  int n = pow(10,5);
  int ni = n;
  vector<double> x;

  while (ni > 0) {
    ni--;
    x.push_back(gen1.get() );
  }



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}


// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;

class pile{
  int num;
public:
  void set(int n){
    num = n;
  }
  void deg(int x){
    num = num-x;
  }
};

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  printf("Press a Number to choose a gamemode:\n1: One-PC Two Player mode.  ");
  int gm;
  cin >> gm;
  pile pile1;
  pile pile2;

  if (gm==1) {

  } else if (gm == 2) {
    /* code */
  } else {
    /* code */
  }



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

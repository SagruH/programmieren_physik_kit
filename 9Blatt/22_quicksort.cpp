
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <cstdlib>


using namespace std;

void printv(vector<double> v) {
  for (size_t i = 0; i < v.size(); i++) {
    printf(" %f ",v[i]);
    if ((i+1)%10 == 0) cout << endl;
  }
  return;
}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  int n_rand = 1000;
  vector<double> val;

  //Generate 1000 random numbers
  srand(time(NULL));
  for (size_t i = 0; i < n_rand; i++) {
    val.push_back((rand()/(double)RAND_MAX));
  }
  printv(val);





  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

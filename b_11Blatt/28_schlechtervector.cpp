
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

class vector_lite {
  int size;
  int a[];
public:
  vector_lite () {
    size = 0;
    a[0];
  }
  vector_lite (int in[], int s) {
    size = s;
    int b[size];
    for (size_t i = 0; i < s; i++) {
      b[i] = in[i];
    }
    *a = *b;
  }
  int get_size() {
    return size;
  }
  void print() {
    int j = 0;
    for (size_t i = 0; i < size; i++) {
      printf(" %3i ",a[i] );
      j++;
      if (j == 9) {
        j = 0;
        cout << endl;
      }
    }
  }
  void set(int in[], int s) {

  }
  void in(int num, int pl) {

  }
  void del(int pl) {

  }

};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int test[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  vector_lite at (test, 15);
  at.print();



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

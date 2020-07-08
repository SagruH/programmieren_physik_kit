
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstring>


using namespace std;

class vector_lite {
  int size = 0;
  int* a = new int[size];
public:
  vector_lite () {}
  vector_lite (int in[], int s) {
    set(in, s);
  }

  int get_size() {
    return size;
  }

  void print() {
    int j = 0;
    for (size_t i = 0; i < size; i++) {
      printf(" %3i ",a[i] );
      j++;
      if (j == 10) {
        j = 0;
        cout << endl;
      }
    }
    cout << endl;
  }

  void set(int *in, int newSize) {
    int* new_arr = new int[newSize];
    memcpy( new_arr , in, newSize * sizeof(int)) ; // dest , src , amount
    size = newSize;
    delete [] a;
    a = new_arr;
  }

  void in(int num, int pl) { //inserts at given polaces and moves rest to the left
    int new_size = size+1;
    int* new_arr = new int[new_size];

    for (size_t i = 0; i < pl; i++) { // copy everything before element
      new_arr[i] = a[i];
    }
    new_arr[pl] = num;
    for (size_t i = pl+1; i < new_size; i++) { //copy everyting after
      new_arr[i] = a[i-1];
    }

    delete [] a;
    a = new_arr;
    size = new_size;
  }
  void del(int pl) {
    int new_size = size - 1;
    int* new_arr = new int[new_size];

    for (size_t i = 0; i < pl; i++) {
      new_arr[i] = a[i];
    }
    for (size_t i = pl+1; i < size; i++) {
      new_arr[i-1] = a[i];
    }

    delete [] a;
    a = new_arr;
    size = new_size;
  }

};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int test[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int test2[10] = {2, 5, 7, 0, 4, 3, 99, 5, 12, 169};

  cout << "constuctor\n";
  vector_lite at(test,15);
  at.print();

  cout << "\nset\n";
  at.set(test2, 10);
  at.print();

  cout << "\nin\n";
  at.in(69,4);
  at.in(1312,0);
  int n = at.get_size();
  at.in(420,n);
  at.print();

  cout << "\ndel\n";
  at.del(n-1);
  at.del(0);
  at.del(6);
  at.print();




  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

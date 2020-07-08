
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
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
    size++;
    int temp[size];
    for (size_t i = 0; i < pl; i++) { // copy everything before element
      temp[i] = a[i];
    }
    temp[pl] = num;
    for (size_t i = pl+1; i < size; i++) { //copy everyting after
      temp[i] = a[i];
    }

    //delete [] a;
    //a = temp;
  }
  void del(int pl) {

  }

};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  int test[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int test2[10] = {2,5,7,0,4,3,99,5,12,169};

  cout << "constuctor\n";
  vector_lite at(test,15);
  at.print();
  cout << "\nset\n";
  at.set(test2, 10);
  at.print();
  cout << "\nin\n";
  //at.in(69,4);
  //at.in(1312,0);
  //at.in(420,18);
  at.print();



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

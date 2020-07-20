
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>


using namespace std;

void printarr(int a[], int n ) {
  for (size_t i = 0; i < n; i++) {
    cout << a[i] << endl;
  }

}

class prime_gen {
  int size = 0;
  int old_upper_limit;
  int upper_limit;
  int *prime_list = new int[size];
public:
    prime_gen(int n) {
      old_upper_limit = 0;
      upper_limit = n;
      if (upper_limit > 0) calc();
    }

    void set_new_ul (int n) {
      if (n <= upper_limit) {
        printf("More primes already calculated\n");
      } else {
        upper_limit = n;
        calc();
      }
    }

    void calc() {
      int arr_size;
      int *arr;
      int tnum;
      //FILL ARRAY
      if (old_upper_limit == 0) {
        arr_size = upper_limit - 1;
        arr = new int[ arr_size ];
        for (int i = 0; i < upper_limit -1; i++) {
          arr[i] = i+2;
        }
      } else {
        arr_size = size + (upper_limit - old_upper_limit);
        arr = new int [ arr_size ];
        for (int i = 0; i < size; i++) {
          arr[i] = prime_list[i];
        }
        for (int i = size, j = old_upper_limit +1; j <= upper_limit; i++,j++) {
          arr[i] = j;
        }
      }
      //calc primes
      printarr(arr, arr_size);
      for (int i = 0; i < arr_size; i++) {
        
      }


      printarr(arr, arr_size);
      old_upper_limit = upper_limit;
    }

};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  prime_gen pg(100);
  cout << "next\n";
  pg.set_new_ul(200);




  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

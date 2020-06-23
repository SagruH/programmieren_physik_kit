
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

long euclid(long a, long b) { //euclid algo
  if (b == 0) {
    return a;
  } else {
    return euclid(b, (a % b) );
  }
}


class ratio_num { //ratio is ambiguous
  long z;
  long n;
public:
  ratio_num(long z1 ,long n1) { //constuctor
    z = z1;
    n = n1;
  }
  //operator overload
  ratio_num operator + (ratio_num &other) {
     ratio_num rr( (other.n*z + n*other.z), n*other.n );
     rr.kuerzen();
     return rr;
  }
  ratio_num operator - (ratio_num &other) {
     ratio_num rr( (other.n*z - n*other.z), n*other.n );
     rr.kuerzen();
     return rr;
  }
  ratio_num operator * (ratio_num &other) {
     ratio_num rr( z*other.z, n*other.n );
     rr.kuerzen();
     return rr;
  }
  ratio_num operator / (ratio_num &other) {
     ratio_num rr( z*other.n, n*other.z );
     rr.kuerzen();
     return rr;
  }
  ratio_num operator - () { //unary
     ratio_num rr( (z*-1), n );
     rr.kuerzen();
     return rr;
  }
  //functions
  void kuerzen() {
   long gcd = euclid(z,n);
   z /= gcd;
   n /= gcd;
   if ((z < 0) && (n < 0) || (z > 0) && (n < 0)) {
     z *= -1;
     n *= -1;
   }
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

  ratio_num a(2,15);
  ratio_num b(7,5);
  ratio_num c(3,7);
  ratio_num d(1,2);
  ratio_num e(1,3);
  ratio_num f(0,0);
  ratio_num g(0,0);


  g = -d + e;
  g = c * g;
  f = a / b;
  f = f + g;
  f.out();
  cout << endl << f.tof() << endl;

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

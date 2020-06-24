
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <numeric>


using namespace std;

//die class existiert schon als std::normal_distribution :(
//aber ich hab so das gefühl das die Aufgaben älter sind als C++11 =D
class normal_generator {
  bool stat;
  double num1, num2;
  int sval;

  void num_gen() {
    double v1, v2;
    double s;
    do {
      sval++;
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
    sval = 0;
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
  void scount() {
    cout << sval << endl;
  }
};


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();
  srand(time(NULL));

  normal_generator gen1;
  int n = pow(10,5);
  int ni = n;
  vector<double> x;
  vector<double> x2;

  double mean1;
  double sqsum1;
  double sigma1;

  while (ni > 0) { //generate num vector x and x2
    ni--;
    x.push_back(gen1.get() );
    x2.push_back(gen1.get() );
  }

  //first set of numbers
  mean1 = accumulate(x.begin(), x.end(), 0.0) / n;
  sqsum1 = inner_product(x.begin(), x.end(), x.begin(), 0.0);
  sigma1 = sqrt ( ( sqsum1 / n ) - (mean1*mean1) );

  //second set of numbers


  //Output
  printf("First set of numbers:\nmean: %f\n\u03C3: %f\n", mean1, sigma1 );

  //gen1.scount(); // Zusatzfrage 2

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

/*Zusatzfragen:
1: in dem man die c++11 eigene klasse benutzt und nicht selbst sowas zusammen pfuscht
2:für 10000 zahlen werden etwa 63,5k durchläufe der schleife gebraucht
  --> (63,5 - 10)/10 = 5,35 also etwa 5,35 durchläufe

*/

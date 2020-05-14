
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>


using namespace std;


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  FILE *fp;
  fp = fopen ("a11-toredat.sec","r");
  if (fp!=NULL)
  {
    fscanf(fp,"Some String\n");
    fclose (fp);
  }

  //code



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

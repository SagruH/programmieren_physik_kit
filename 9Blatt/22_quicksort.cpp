
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <algorithm>


using namespace std;


void printv(vector<double> v) {
  for (size_t i = 0; i < v.size(); i++) {
    printf(" %f ",v[i]);
    if ((i+1)%10 == 0) cout << endl;
  }
  return;
}

void quicksort(vector<double> &v, int s, int t) {
  //system("sleep 1"); //DEBUG
  if (s >= t) { //return if sub-list is to small
    //printf("If case\n"); //DEBUG
    return;
  }
  vector<double> hv1, hv2;
  int            ht = t;
  double         pve = v[s];

  for (; s <= t; t--) { // sort sub list
    if (v[t] <  pve) {
      hv1.push_back(v[t]);
    } else if (v[t] > pve) {
      hv2.push_back(v[t]);
    }
  }

  //put sublist back in original vector
  v.erase (v.begin() + s, v.begin()+ht+1 );
  v.insert(v.begin() + s, hv1.begin(), hv1.end() );
  v.insert(v.begin() + s + hv1.size(), pve);
  v.insert(v.begin() + s + hv1.size()+1, hv2.begin(), hv2.end() );

  vector<double>::iterator p = find(v.begin(), v.end(), pve);
  int pve_i = distance(v.begin(), p );

  //printv(v);    //DEBUG
  //cout << endl << endl;
  //printf("lower half quicksort\n");
  quicksort(v, s, pve_i-1);

  //printf("upper half quicksort\n");
  quicksort(v, pve_i+1, ht);
}

int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  vector<double> val;
  int n_rand = 1000;


  //Generate 1000 random numbers
  srand(time(NULL));
  for (size_t i = 0; i < n_rand; i++) {
    val.push_back((rand()/(double)RAND_MAX));
  }

  //val.clear(); val = {10,1,2,7,0,8,6,3,4,9,5,11,12,17,14,15,16,13,18,19}; //DEBUG
  printv(val);
  cout << endl << endl;

  //quicksort
  quicksort(val , 0 , n_rand-1);
  printf("End result:\n");
  printv(val);

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

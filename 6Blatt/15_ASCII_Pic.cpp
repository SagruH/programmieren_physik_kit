
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  //User Input
  printf("%s\n","Which picture shall be shown?\nEnter a Number between 1 and 4." );
  int picI;
  cin >> picI;
  auto t_start = chrono::high_resolution_clock::now();
  string dic[16]{".",",","\u02DC","=","+",":","?","$","7","8","D","I","M","N","O","Z"};
  string filename = picI == 1 ? "a15-bild1.dat" : picI == 2 ? "a15-bild2.dat" :
                    picI == 3 ? "a15-bild3.dat" : picI == 4 ? "a15-bild4.dat" : "ERROR";

  if (filename == "ERROR") {
    printf("%s\n","Invalid Input!\nEnter an integer between 1 and 4." );
    return 0;
  }

  //file input
  fstream ffile;
  ffile.open(filename, ios::in);
  vector<int> content;
  int size = 2;
  int a, xsize, ysize;

  while (ffile >> a) {
    if (size == 2) {
      xsize = a;
      size--;
    } else if (size == 1) {
      ysize = a;
      size--;
    } else {
      content.push_back(a);
    }
    }
  ffile.close();

  //picture rendering; file format: sign A B times
  int sign, num;
  int loopcount = 0;
  printf("%d %d\n",xsize,ysize );

  for (size_t i = 0; i < (content.size()-1); i+=2) {
    sign = content[i];
    num = content[i+1];
    int j = 1;
    while (j<=num) {
      cout << dic[sign];
      loopcount++;
      j++;
      if (loopcount==xsize) {
        loopcount = 0;
        cout << endl;
      }
    }
  }


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

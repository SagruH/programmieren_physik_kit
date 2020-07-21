
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>

using namespace std;

class mat {
private:
  double matrix[2][2];
public:
  mat(double a[2][2]);
  mat() {};
  mat add(mat);
  double trace();
  void print() {
    for (int i=0;i<2; i++) {
      for (int j=0;j<2; j++),
      cout << matrix[i][j] << " ";
      cout << endl;
    }
  }
};

int main(int argc, char const *argv[]) {

  return 0;
}

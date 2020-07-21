
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>

using namespace std;

class mat {
private:
  double matrix[2][2];
public:
  mat(double a[2][2]) { //schreibt aus eigegebenem Array in Klasse
      // Ginge schoener mit einer Schleife aber nicht schneller
      matrix[0][0] = a[0][0];
      matrix[1][0] = a[1][0];
      matrix[0][1] = a[0][1];
      matrix[1][1] = a[1][1];
  }
  mat() {};

  mat add(mat nm) {
    //add elements
    double enn = matrix[0][0]+nm.matrix[0][0];
    double eno = matrix[0][1]+nm.matrix[0][1];
    double eon = matrix[1][0]+nm.matrix[1][0];
    double eoo = matrix[1][1]+nm.matrix[1][1];
    //write in mar and return
    double arr[2][2] = { {enn, eno}, {eon, eoo} };
    mat nmat(arr);
    return nmat;
  }

  double trace() {
    double tr = 0;
    for (int i = 0; i < 2; i++) {
      tr += matrix[i][i];
    }
    return tr;
  }
  void print() {
    for (int i=0;i<2; i++) {
      for (int j=0;j<2; j++)
      cout << matrix[i][j] << " ";
      cout << endl;
    }
  }
};

int main(int argc, char const *argv[]) {
  double arr1[2][2] = {{4.1,-9.2},{2.1, 8.3}};
  double arr2[2][2] = {{-6.2,0.},{5., 4.1}};
  mat m1(arr1);
  mat m2(arr2);
  mat m3 = m1.add(m2);
  cout << "M1\n";
  m1.print();
  cout << "M2\n";
  m2.print();
  cout << "M3\n";
  m3.print();
  cout << "Spur: " << m3.trace() << endl;

  return 0;
}

/*
 * Programmieren fuer Physiker, SS 2020, Blatt 8, Aufgabe 19
 *
 * Struct fuer Rechteck
 */

#include <iostream>
using namespace std ;

// zu ergaenzen: struct rechteck und zwei Funktionen
class rechteck {
private:
public:
  double h;
  double w;

  void rotation(){
    double temp = h;
    h = w;
    w = temp;
  }
};

rechteck rotation(rechteck r){ // <-- this is stupid!
  double temp = r.h;
  r.h = r.w;
  r.w = temp;
  return r;
}

bool bedeckt(rechteck r1, rechteck r2){
  return ((r1.h == r2.h) && (r1.w == r2.w)) ? true : false;
}


int main()
{
    cout << "Rechteckstuct" << endl ;
    rechteck r1 = {3.3, 2.0} ;
    rechteck r2 = {2.0, 3.3} ;

    cout << "Vor Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;

    //printf("1h %f 1w %f 2h %f 2w %f\n", r1.h, r1.w, r2.h, r2.w); //DEBUG
    r2 = rotation(r2) ;

    cout << "Nach Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;
}

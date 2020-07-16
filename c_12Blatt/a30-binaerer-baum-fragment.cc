/*
 * Programmieren fuer Physiker, SS 2020. Blatt 12, Aufg. 30
 *
 * Binaerer Baum (der sortiert ist). Zu ergaenzendes Fragment.
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std ;

class Node {

private:
    double value ;  // Wert des Knoten
    Node* left ;    // Zeiger auf linken Ast
    Node* right ;   // Zeiger auf rechten Ast

public:
    Node (double x) {
      value = x;
      left = NULL;
      right = NULL;
    }

    void insert (double x) {
      Node *nd = new Node(x);
      Node *temp = left;
      if (left == NULL) {
        left = nd;
      } else {
        while (temp -> left != NULL) {
          temp = temp -> left;
        }
        temp -> left = nd;
      }
    }

    double min() {
      //TODO
      return 0;
    }
    friend ostream& operator << (ostream& o, Node& nd) {
      if (0 != nd.left) o << *(nd.left);
      o << nd.value << " ";
      if (0 != nd.right) o << *(nd.right);
      return o;
    }
};

int main()
{
    srand ((unsigned int)time(0)) ;
    Node tree(1.0) ;        // Basiselement.
    for(int i=0; i<10; i++) // 10 Zufallszahlen in den Baum einhaengen...
    {
	double x = 2.0*double(rand())/RAND_MAX ;
	cout << "Einzufuegen: " << x << endl ;
	tree.insert(x) ;
    }
    cout << "Die minimale Zahl im Baum ist: " << tree.min() << endl ;
    cout << "Alle Eintraege sortiert: " << endl << "  " << tree << endl ;
}

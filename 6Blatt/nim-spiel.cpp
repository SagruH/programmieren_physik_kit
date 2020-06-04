
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>


using namespace std;

//declaring classes: pile and player
class pile{
public:
  int num;

  void set(int n){
    num = n;
  }
  int take(int x){
    if ((num-x)<0) {
      cout << "Invalid move: Took to many pieces!" << endl;
      return -1; //invalid move
    } else if ((num-x)==0){
      num = num-x;
      cout << "Pile depelted!" << endl;
      return 0; //valid move; pile depleted
    } else {
      num = num-x;
      return 1; //valid move; pile not depleted
    }
  }
};

class player{
public:
  int player_num;
  int p_turn;
  int p_won = 0;

  int one_pile(int p, int x){
    int stat;
    if (p==1) {
      stat = pile1.take(x);
    } else if (p==2) {
      stat = pile1.take(x);
    } else {
      cout << "Invalid move: unknown pile!" << endl;
      return -1;
    }
    has_won();
    return stat;
  }
  int both_pile(int x){
    int stat1, stat2;
    stat1 = pile1.take(x);
    if (stat1 == -1) return -1;
    stat2 = pile2.take(x);
    if (stat2 == -1) return -1;
    has_won();
    return 1;

  }
private:
  void has_won(){
    if ((pile1.num == 0) && (pile2.num == 0)) {
      p_won = 1;
    }
  }
};

//declaring global objects
pile pile1;
pile pile2;
player player1;
player player2;

// game functions
void ini_game() {
  player1.player_num = 1;
  player2.player_num = 2;
  srand(time(NULL));
  int pile1num = rand() % 25 + 5;
  int pile2num = rand() % 25 + 5;
  pile1.set(pile1num);
  pile2.set(pile2num);
  int coinflip = rand();
  if (coinflip > RAND_MAX/2) {
    player1.p_turn = 1;
    player2.p_turn = 0;
  } else {
    player1.p_turn = 0;
    player2.p_turn = 1;
  }
}
void next_player() {
  if (player1.p_turn == 1) {
    player1.p_turn = 0;
    player2.p_turn = 1;
    return;
  } else if (player2.p_turn == 1) {
    player1.p_turn = 1;
    player2.p_turn = 0;
    return;
  } else {
    cout << "ERROR: Player turn management failure."
  }
}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  printf("Press a Number to choose a gamemode:\n1: One-PC Two Player mode.  ");
  int gm;
  cin >> gm;

  ini_game(); //sets all values through RNG

  if (gm==1) {

  } else if (gm == 2) {
    /* code */
  } else {
    /* code */
  }



  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

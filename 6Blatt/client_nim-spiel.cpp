
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080

using namespace std;

class pile;
class player;

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

//declaring global pile
pile pile1;
pile pile2;

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
      stat = pile2.take(x);
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

//declaring global player
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
    cout << "ERROR: Player turn management failure.";
  }
}

int move_gm1(int p, int x){
  int stat;
  if (player1.p_turn == 1) {
    if (p == 0) {
      stat = player1.both_pile(x);
    } else {
      stat = player1.one_pile(p,x);
    }
  } else if (player2.p_turn == 1) {
    if (p == 0) {
      stat = player2.both_pile(x);
    } else {
      stat = player2.one_pile(p,x);
    }
  }

  if (stat==-1) {
    cout << "Try Again" << endl;
    return 0;
  } else if (stat != -1) {
    int end = ((player1.p_won == 1) || (player2.p_won == 1)) ? 1 : 0;
    stat = (end == 1) ? -1 : 0;
    next_player();
    return stat;
  }

}


int main(int argc, char const *argv[]) {
  auto t_start = chrono::high_resolution_clock::now();

  string full_Rules = "Rules:\nThere are 2 piles with matches.\nYou can take (x >= 1) matches either from one pile or from both piles.\nYou frist choose from where you would like to take the matches, then the amount.\nIf the input was valid the next player takes matches.\nThe player which takes the last match(es) wins.\nONLY ENTER INTEGERS!\n\n";
  string rules ="First choose a pile:\nBoth: 0, Pile 1: 1, Pile 2: 2\nThen Enter the amount you like to take:\n";
  int p, x;

  //-------------------------------------------
  //CLIENT INI
  //-------------------------------------------
  int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

  //Game Start

  printf("Press a Number to choose a gamemode:\n1: One-PC Two Player mode.\n2: Multiplayer Clientside\n");
  int gm;
  cin >> gm;

  ini_game(); //sets all values through RNG

  if (gm==1) {//One PC
    int stat = 1;
    cout << full_Rules;
    if (player1.p_turn == 1) {
      printf("Player %i starts!\n", player1.player_num);
    } else if (player2.p_turn == 1) {
      printf("Player %i starts!\n", player2.player_num);
    }

    do {
      //Player info output
      if (player1.p_turn == 1) {
        printf("Player %i:\n", player1.player_num);
      } else if (player2.p_turn == 1) {
        printf("Player %i:\n", player2.player_num);
      }
      printf("Pile 1: %i | Pile 2: %i\n\n",pile1.num, pile2.num );
      //Player interaction
      cout << rules;
      cin >> p;
      cin >> x;
      stat = move_gm1(p,x);

    } while(stat >= 0);
    //win text
    if (player1.p_turn == 1) {
      printf("Player%i has won!\n", player2.player_num);
    } else if (player2.p_turn == 1) {
      printf("Player%i has won!\n", player1.player_num);
    }

  } else if (gm == 2) { //Multiplayer Internet

    //connection to server
    cout << "Trying to connect..." << endl;
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
      printf("\nConnection Failed \n");
      return -1;
    }
    cout << "Connection successful" << endl;

    //info
    cout << full_Rules;
    int stat = 1;
    //game: // CLIENT IS PLAYER 2
    cout << "YOU ARE PLAYER 2" << endl;
    //sync with host
    int p1num, p2num;
    valread = read(sock, &p1num, sizeof(p1num));
    valread = read(sock, &p2num, sizeof(p2num));
    pile1.num = ntohl(p1num);
    pile2.num = ntohl(p2num);

    printf("Pile 1: %i | Pile 2: %i\n\n",pile1.num, pile2.num );
  }

  /*
  cin >> p;
  cin >> x;
  int p_con = htonl(p);
  int x_con = htonl(x);
  write(sock, &p_con, sizeof(p_con));
  write(sock, &x_con, sizeof(x_con));
  */

  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

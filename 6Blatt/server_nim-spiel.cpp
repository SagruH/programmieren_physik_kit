
// github: https://github.com/SagruH/programmieren_physik_kit

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
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
  //SERVER INI
  //-------------------------------------------
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Forcefully attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                        &opt, sizeof(opt)))
  {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  // Forcefully attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr *)&address,
                sizeof(address))<0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0)
  {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  //actual code
  printf("Press a Number to choose a gamemode:\n1: One-PC Two Player mode.\n2: Multiplayer Serverside\n");
  int gm;
  cin >> gm;

  ini_game(); //sets all values through RNG

  if (gm==1) {
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
  } else if (gm == 2) {
    //connection to client
    cout << "Waiting for connection..." << endl;
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
            (socklen_t*)&addrlen))<0)
    {
      perror("accept");
      exit(EXIT_FAILURE);
    }
    cout << "Connection successful" << endl;
    //info
    cout << full_Rules;
    int stat = 1;
    //game: //HOST IS PLAYER 1
    cout << "YOU ARE PLAYER 1" << endl;
    //sync player 2 to player 1
    int p1num = htonl(pile1.num);
    int p2num = htonl(pile2.num);
    write(new_socket, &p1num, sizeof(p1num));
    write(new_socket, &p2num, sizeof(p2num));
    printf("Pile 1: %i | Pile 2: %i\n\n",pile1.num, pile2.num );
    if (player1.p_turn == 1) {
      printf("Player %i:\n", player1.player_num);
      int pts = htonl(1);
      write(new_socket, &pts, sizeof(pts));
    } else if (player2.p_turn == 1) {
      printf("Player %i:\n", player2.player_num);
      int pts = htonl(2);
      write(new_socket, &pts, sizeof(pts));
    }
    //start game
    do {
      if (player1.p_turn == 1) {
        printf("Your turn:\n");
        printf("Pile 1: %i | Pile 2: %i\n\n",pile1.num, pile2.num );
        cout << rules;

        cin >> p;
        cin >> x;
        int p_con = htonl(p);
        int x_con = htonl(x);
        write(new_socket, &p_con, sizeof(p_con));
        write(new_socket, &x_con, sizeof(x_con));
        stat = move_gm1(p,x);


      } else if (player2.p_turn == 1) {
        printf("Opponents turn:\n");
        valread = read(new_socket, &p, sizeof(p));
        valread = read(new_socket, &x, sizeof(x));
        p = ntohl(p);
        x = ntohl(x);
        stat = move_gm1(p,x);
      }
    } while(stat >=0);
    
    if (player1.p_turn == 1) {
      printf("Player%i has won!\n", player2.player_num);
    } else if (player2.p_turn == 1) {
      printf("Player%i has won!\n", player1.player_num);
    }

  }


    /*
    valread = read(new_socket, &p, sizeof(p));
    valread = read(new_socket, &x, sizeof(x));
    cout << "p " << ntohl(p) << endl;
    cout << "x " << ntohl(x) << endl;
    */


  auto t_end = chrono::high_resolution_clock::now();
  chrono::duration<double> runtime = t_end - t_start; // runtime calc
  cout << endl << "Runtime: " << runtime.count() << "s\n";

  return 0;
}

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
void drawBoard(char *spaces);
void P_move(char *spaces, char player);
void C_move(char *spaces, char computer);
bool Winner(char *spaces, char player, char computer);
bool Tie(char *spaces);
using namespace std;

int main() {
  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player = 'O';
  char computer = 'X';
  bool running = true;
  drawBoard(spaces);
  while (running) {
    P_move(spaces, player);
    drawBoard(spaces);
    if (Winner(spaces, player, computer)) {
      running = false;
      break;
    } else if (Tie(spaces)) {
      running = false;
      break;
    }
    C_move(spaces, computer);
    drawBoard(spaces);
    if (Winner(spaces, player, computer)) {
      running = false;
      break;
    } else if (Tie(spaces)) {
      running = false;
      break;
    }
  }
  cout << "ty for playing\n";
  return 0;
}

void drawBoard(char *spaces) {
  cout << '\n';
  cout << "     |     |    " << endl;
  cout << "   " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2]
       << " " << endl;
  cout << "_____|_____|____" << endl;
  cout << "     |     |    " << endl;
  cout << "   " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5]
       << " " << endl;
  cout << "_____|_____|____" << endl;
  cout << "     |     |    " << endl;
  cout << "   " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8]
       << " " << endl;
  cout << "     |     |    " << endl;
  cout << '\n';
}
void P_move(char *spaces, char player) {
  int num;
  do {
    cout << "enter a spot to place a marker (1-9)" << endl;
    cin >> num;
    num--;
    if (spaces[num] == ' ') {
      spaces[num] = player;
      break;
    }

  } while (!num > 0 || !num < 8);
}
void C_move(char *spaces, char computer) {

  int num;
  srand(time(0));
  while (true) {

    int num = rand() % 9;
    if (spaces[num] == ' ') {
      spaces[num] = computer;
      break;
    }
  }
}
bool Winner(char *spaces, char player, char computer) {

  if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) &&
      (spaces[1] == spaces[2])) {
    spaces[0] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) &&
             (spaces[4] == spaces[5])) {
    spaces[3] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) &&
             (spaces[7] == spaces[8])) {
    spaces[6] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) &&
             (spaces[3] == spaces[6])) {
    spaces[0] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) &&
             (spaces[4] == spaces[7])) {
    spaces[0] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) &&
             (spaces[5] == spaces[8])) {
    spaces[0] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) &&
             (spaces[4] == spaces[8])) {
    spaces[0] == player ? cout << "you win\n" : cout << "You lose\n";
  } else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) &&
             (spaces[4] == spaces[6])) {
    spaces[0] == player ? cout << "you win\n" : cout << "You lose\n";
  } else {
    return false;
  }

  return true;
}

bool Tie(char *spaces) {

  for (int i = 0; i < 9; i++) {
    if (spaces[i] == ' ') {
      return false;
    }
  }
  cout << "A tie\n";
  return true;

  return 0;
}

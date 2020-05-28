#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>


using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define UI unsigned int

bool eq(char &a, char &b) {
  if (a == 'T' && b != '.') return true;
  if (b == 'T' && a != '.') return true;
  if (a != '.' && a == b) return true;
  return false;
}

int main() {
  // Declare members
  int num_case;
  cin >> num_case;

  char board[4][4];
  char bin;
  bool complete = true;
  bool won = false;
  char who = ' ';

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    complete = true;
    won = false;
    who = ' ';

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> board[i][j];
        if (board[i][j] == '.') {
          complete = false;
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      int j = 1;
      for (; j < 4; j++) {

        if (!eq(board[i][j], board[i][j-1])) {
          break;
        }
      }
      if (j == 4 && eq(board[i][0], board[i][3])) {
        won = true;
        who = (board[i][0] == 'T'?board[i][1]:board[i][0]);
        break;
      }
    }

    if (!won) {
      for (int i = 0; i < 4; i++) {
        int j = 1;
        for (; j < 4; j++) {
          if (!eq(board[j][i], board[j-1][i])) {
            break;
          }
        }
        if (j == 4 && eq(board[0][i], board[3][i])) {
          won = true;
          who = (board[0][i] == 'T'?board[1][i]:board[0][i]);
          break;
        }
      }
    }

    if (!won) {
      int i = 1;
      for (; i < 4; i++) {
        if (!eq(board[i][i], board[i-1][i-1])) {
          break;
        }
      }
      if (i == 4 && eq(board[0][0], board[3][3])) {
          won = true;
          who = (board[0][0] == 'T'?board[1][1]:board[0][0]);
      }
    }

    if (!won) {
      int i = 1;
      for (; i < 4; i++) {
        if (!eq(board[i][3 - i], board[i-1][3 - i + 1])) {
          break;
        }
      }
      if (i == 4 && eq(board[0][3], board[3][0])) {
          won = true;
          who = (board[0][3] == 'T'?board[1][2]:board[0][3]);
      }
    }

    string result;
    if (won) {
      result = who + string(" won");
    } else {
      if (complete) {
        result = "Draw";
      } else {
        result = "Game has not completed";
      }
    }
    // Print output for case j
    cout << "Case #" << nc << ": " << result << endl;
  }


  return 0;
}

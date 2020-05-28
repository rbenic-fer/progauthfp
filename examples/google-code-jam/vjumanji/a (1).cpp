#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int T; scanf("%d\n", &T);
  string g[30];
  for(int t = 1; t <= T; t++) {
    int r, c;
    scanf("%d %d\n", &r, &c);
    for(int i=0; i<r; i++) std::cin >> g[i];
    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        if (g[i][j] == '?') {
          if (j > 0) g[i][j] = g[i][j-1];
        }
      }
      for(int j=c-1; j>=0; j--) {
        if (g[i][j] == '?') {
          if (j < c-1) g[i][j] = g[i][j+1];
        }
      }
    }

    for (int i=0; i<r; i++) {
      bool rowIsEmpty = true;
      for (int j=0; j<c; j++) if (g[i][j] != '?') rowIsEmpty = false;
      if (rowIsEmpty) {
        if (i > 0) {
          for (int j=0; j<c; j++) g[i][j] = g[i-1][j];
        }
        else {
          for (int j=0; j<c; j++) g[i][j] = g[i+1][j];
        }
      }
      g[i][c] = 0;
    }
    for (int i=r-1; i>=0; i--) {
      bool rowIsEmpty = true;
      for (int j=0; j<c; j++) if (g[i][j] != '?') rowIsEmpty = false;
      if (rowIsEmpty) {
        if (i < r-1) {
          for (int j=0; j<c; j++) g[i][j] = g[i+1][j];
        }
        else {
          for (int j=0; j<c; j++) g[i][j] = g[i-1][j];
        }
      }
      g[i][c] = 0;
    }
    printf("Case #%d:\n", t);
    for(int i=0; i<r; i++) std::cout << g[i] << '\n';
  }
  return 0;
}

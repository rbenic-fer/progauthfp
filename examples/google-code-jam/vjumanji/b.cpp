#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  int T;
  std::cin >> T;
  for (size_t i = 0; i < T; i++) {
    std::string s;
    std::cin >> s;
    int n = s.size();
    for (int j = n-2; j >= 0; j--) {
      if (s[j] > s[j+1]) {
        s[j] --;
        for (int k = j+1; k < n; k++) {
          s[k] = '9';
        }
      }
    }
    long long N = 0;
    for (int j = 0; j < n; j++) {
      N = N * 10 + (s[j] - '0');
    }
    std::cout << "Case #" << (i+1) <<": " << N << '\n';
  }
  return 0;
}

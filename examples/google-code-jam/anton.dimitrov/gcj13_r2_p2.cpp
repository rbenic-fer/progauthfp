#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

const char* INPUT_FILE = "/Users/pierrelombard/Anton/ProgrammingContests/CodeJam/B-small-attempt1.in";
// const char* INPUT_FILE = "/Users/pierrelombard/Anton/ProgrammingContests/CodeJam/input.txt";
const char* OUTPUT_FILE = "/Users/pierrelombard/Anton/ProgrammingContests/CodeJam/output.txt";

int gt;
int n, p;

int main() {
    freopen(INPUT_FILE, "r", stdin);
    // freopen(OUTPUT_FILE, "w", stdout);

    scanf("%d", &gt);
    for (int gi = 1; gi <= gt; gi++) {
        scanf("%d %d", &n, &p);
        int a1 = 0;
        int a2 = 0;
        if (p == (1 << n)) {
            printf("Case #%d: %d %d\n", gi, p-1, p-1);
        } else {
            for (int i = 0; i < p; i++) {
                int countl = 0;
                int countw = 0;
                for (int j = n-1; j >= 0; j--) {
                    if ((i & (1 << j)) == 0) {
                        countw++;
                    } else if (countw == 0) {
                        countl++;
                    }
                }
                int v1 = (1 << (countl+1)) - 2;
                int v2 = (1 << n) - (1 << countw);
                // printf("%d -> %d, %d\n", i, v1, v2);
                a1 = max(a1, v1);
                a2 = max(a2, v2);
            }
            printf("Case #%d: %d %d\n", gi, a1, a2);
        }
    }

    return 0;
}
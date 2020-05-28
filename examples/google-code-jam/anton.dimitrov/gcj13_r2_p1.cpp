#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

const char* INPUT_FILE = "/Users/pierrelombard/Anton/ProgrammingContests/CodeJam/A-large.in";
// const char* INPUT_FILE = "/Users/pierrelombard/Anton/ProgrammingContests/CodeJam/input.txt";
const char* OUTPUT_FILE = "/Users/pierrelombard/Anton/ProgrammingContests/CodeJam/output.txt";

const int MOD = 1000002013;

int gt;
int n, m;
vector< pair <int, int> > points;
vector< pair <int, int> > pax;

long long getsum(int stops) {
    long long res = ((long long)stops * (long long)n) % MOD;
    res = (res - (long long)stops * (stops - 1) / 2 + MOD) % MOD;
    return res;
}

int main() {
    freopen(INPUT_FILE, "r", stdin);
    // freopen(OUTPUT_FILE, "w", stdout);

    scanf("%d", &gt);
    for (int gi = 1; gi <= gt; gi++) {
        points.clear();
        pax.clear();

        long long legal_pay = 0;

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int st, en, pi;
            scanf("%d %d %d", &st, &en, &pi);
            points.push_back(make_pair(st, -pi));
            points.push_back(make_pair(en, pi));
            legal_pay = (legal_pay + pi * getsum(en-st)) % MOD;
        }

        sort(points.begin(), points.end());

        for (int i = 0; i < points.size(); i++) {
            if (points[i].second < 0) {
                if (pax.size() == 0 || pax.back().first != points[i].first) {
                    pax.push_back(make_pair(points[i].first, 0));
                }
            }
        }

        long long to_pay = 0;
        for (int i = 0; i < points.size(); i++) {
            if (points[i].second < 0) {
                for (int j = 0; j < pax.size(); j++) {
                    if (pax[j].first == points[i].first) {
                        pax[j].second -= points[i].second;
                        break;
                    }
                }
            } else {
                int to_leave = points[i].second;
                for (int j = pax.size()-1; j >= 0 && to_leave > 0; j--) {
                    if (pax[j].second > 0) {
                        int left = min(to_leave, pax[j].second);
                        to_leave -= left;
                        pax[j].second -= left;
                        to_pay = (to_pay + left * getsum(points[i].first - pax[j].first)) % MOD;
                    }
                }
            }
        }

        printf("Case #%d: %lld\n", gi, (legal_pay - to_pay + MOD) % MOD);
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define IOS do { ios_base::sync_with_stdio(0);cin.tie(0); } while (0)
#define SZ(x) ((int)(x).size())
#ifndef OFFLINE
    #define ONLINE_JUDGE
#endif
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
    do { \
        freopen(name".in", "r", stdin); \
        freopen(name".out", "w", stdout); \
    } while (0)
#else
    #define FILEIO(name) do { } while(0)
#endif

#define _TOKEN_CAT2(x, y) x ## y
#define _TOKEN_CAT(x, y) _TOKEN_CAT2(x, y)
#define _MACRO_OVERL3(_1, _2, _3, _N, ...) _N
#define _RANGE1(a) int _TOKEN_CAT(_t, __LINE__)=0; _TOKEN_CAT(_t, __LINE__)<(a); (_TOKEN_CAT(_t, __LINE__))++
#define _RANGE2(i, a) int (i)=0; (i)<(a); (i)++
#define _RANGE3(i, a, b) int (i)=(a); (i)!=(b); (i)+=((b)>(a)?1:-1)
#define loop(...) for (_MACRO_OVERL3(__VA_ARGS__, _RANGE3, _RANGE2, _RANGE1)(__VA_ARGS__))

#ifdef OFFLINE
template<typename T>
void _dump(const char* s, T&& head) { 
    cerr << s << " = " << head << " <<" << endl; 
}

template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c = 0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{' || *s=='<') c++;
        if (*s==')' || *s==']' || *s=='}' || *s=='>') c--;
        cerr << *s++;
    }
    cerr << " = " << head << ", ";
    _dump(s+1, tail...);
}

#define dump(...) do { \
    cerr << "\033[32m>> " << __LINE__ << ": " << __PRETTY_FUNCTION__ << endl; \
    cout << "   "; \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
    cout << "\033[0m"; \
} while (0)
#else
#define dump(...) 
#endif

#define au auto
template<class T>
using vec = vector<T>;

template<typename Iter>
ostream& _IterOutput_(ostream &o, Iter b, Iter e, const string ss="", const string se="") {
    o << ss;
    for (auto it=b; it!=e; it++) o << (it==b ? "" : ", ") << *it;
    return o << se;
}

template<typename T1, typename T2>
ostream& operator << (ostream &o, const pair<T1, T2> &pair) {
    return o << "(" << pair.F << ", " << pair.S << ")";
}

template<typename T>
ostream& operator << (ostream &o, const vector<T> &vec) {
    return _IterOutput_(o, ALL(vec), "[", "]");
}

template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    return _IterOutput_(o, ALL(st), "{", "}");
}

template<typename T, size_t N>
ostream& operator << (ostream &o, const array<T, N> &arr) {
    return _IterOutput_(o, ALL(arr), "|", "|");
}

template<typename T1, typename T2>
ostream& operator << (ostream &o, const map<T1, T2> &mp) {
    o << "{";
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        o << (it==mp.begin()?"":", ") << it->F << ":" << it->S;
    }
    o << "}";
    return o;
}

void lucky_test() {
    std::random_device rd;
    std::mt19937 gen_(rd());
    std::normal_distribution<double> dist_(0.0, 1.0);

    if (dist_(gen_) >= 4.44444444) {
        cout << "Not lucky" << endl;
        exit(0);
    }
}

using A34 = array<int, 4>;
int nT;
int N, P;
int C[10];
A34 fin;
unordered_map<int, int> mp;

static void init() {
    mp.clear();
    for (int i=0; i<5; i++) C[i] = 0;
}
int cnt = 0;
int encode(A34 a) {
    int t = 0;
    for (int i=0; i<4; i++) {
        t *= 110;
        t += a[i];
    }
    return t;
}
A34 decode(int t) {
    A34 a;
    for (int i=3; i>=0; i--) {
        a[i] = t % 110;
        t /= 110;
    }
    return a;
}
int dp(A34 st) {
    cnt++;
    if (st == fin) return 0;
    int q = encode(st);
    if (mp.find(q) != end(mp)) {
        return mp[q];
    }

    int c = 0;
    int ans = 0;

    for (int i=0; i<P; i++) {
        if (st[i] < C[i]) {
            st[i]++;
            ans = max(ans, dp(st));
            st[i]--;
        }
    }

    for (int i=0; i<P; i++) c += i * st[i];
    if (c % P == 0) ans++;

    mp[q] = ans;
    return ans;
}

int32_t main() {
    IOS;
    cin >> nT;
    for (int cas=1; cas<=nT; cas++) {
        cin >> N >> P;
        init();

        for (int i=0; i<N; i++) {
            int x; cin >> x;
            C[x%P] ++;
        }
        for (int i=0; i<4; i++) fin[i] = 0;
        for (int i=0; i<P; i++) fin[i] = C[i];

        int ans = dp({0, 0, 0, 0});
        cout << "Case #" << cas << ": " << ans << endl;
    }

    return 0;
}


#include<cstdio>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

char buf[200];

int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int n, m;
		scanf("%d%d", &n, &m);
		set<string> dirs;
		dirs.insert("/");
		for (int i=0; i<n; i++) {
			scanf("%s", buf);
			vector<string> ar = split(buf, "/");
			stringstream ss;
			ss << "/";
			for (int j=0; j<ar.size(); j++) {
				ss<<ar[j]<<"/";
				dirs.insert(ss.str());
			}
		}
		int res = 0;
		for (int i=0; i<m; i++) {
			scanf("%s", buf);
			vector<string> ar = split(buf, "/");
			stringstream ss;
			ss << "/";
			for (int j=0; j<ar.size(); j++) {
				ss<<ar[j]<<"/";
				if (dirs.find(ss.str()) == dirs.end()) {
					dirs.insert(ss.str());
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", t, res);
	}
	return 0;
}
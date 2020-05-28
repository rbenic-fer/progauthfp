#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

map<char,char> M;

string inputs[] = 
{"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 "de kr kd eoya kw aej tysr re ujdr lkgc jv"};

string outputs[] = 
{"our language is impossible to understand",
 "there are twenty six factorial possibilities",
 "so it is okay if you want to just give up"};

int main()
{
    ios::sync_with_stdio(false);
    M[' '] = ' ';
    M['y'] = 'a', M['e'] = 'o', M['q'] = 'z', M['z'] = 'q';

    string s,t;
    for (int k = 0; k < 3; k++){
        stringstream ss(inputs[k]), tt(outputs[k]); 
        while(ss >> s){
            tt >> t;
            for (int i = 0; i < s.size(); i++){
                M[s[i]] = t[i];
            }
        }
    }

    int T;
    getline(cin,t); stringstream tt(t); tt >> T;

    for (int q = 1; q <= T; q++){
        getline(cin,s);
        cout << "Case #"<<q<<": ";
        for (int i = 0; i < s.length(); i++){
            cout << M[s[i]];
        }
        cout << '\n';
    }
    return 0;
}


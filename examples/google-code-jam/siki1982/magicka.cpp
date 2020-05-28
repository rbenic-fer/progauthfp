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



int main() {
  // Declare members
  uint32_t num_case;
  cin >> num_case;



  for (int j = 1; j <= num_case; j++) {
    // Init members
    int num;
    string s;
    map<string, string> comb;
    map<string, int> opp_to_int;
    vector<string> is_opp;
    map<string, int> num_opp;
    
    string res;


    cin >> num;
    for (int i = 0; i < num; i++) {
      cin >> s;
      comb[string(&s[0], 1) + string(&s[1], 1)] = string(&s[2], 1);
      comb[string(&s[1], 1) + string(&s[0], 1)] = string(&s[2], 1);
    }

    cin >> num;
    is_opp.resize(num);
    for (int i = 0; i < num; i++) {
      cin >> s;
      opp_to_int[string(&s[0], 1)] = i;
      opp_to_int[string(&s[1], 1)] = i;
      num_opp[string(&s[0], 1)] = 0;
      num_opp[string(&s[1], 1)] = 0;
    }

    cin >> num;
    cin >> s;

    map<string, string>::iterator it;
    map<string, int>::iterator it2;
    for (int k = 0; k < num; k++) {
      if (res.size() > 0) {
	if ((it = comb.find(string(&res[res.size() - 1], 1) + string(&s[k], 1))) != comb.end()) {
	  if ((it2 = opp_to_int.find(string(&res[res.size() - 1], 1))) != opp_to_int.end()) {
	    num_opp[string(&res[res.size() - 1], 1)]--;
	    if (num_opp[string(&res[res.size() - 1], 1)] == 0) {
	      is_opp[it2->second] = "";
	    }
	  }

	  res[res.size() - 1] = *(it->second.c_str());
	  continue;
	}
      } 
      
      if ((it2 = opp_to_int.find(string(&s[k], 1))) != opp_to_int.end()) {
	if (is_opp[it2->second].size() > 0) {
	  if (is_opp[it2->second] != string(&s[k], 1)) {
	    res.clear();
	    for (int z = 0; z < is_opp.size(); z++) {
	      is_opp[z] = "";
	    }
	    for (map<string, int>::iterator iter = num_opp.begin(); iter != num_opp.end(); ++iter) {
	      iter->second = 0;
	    }
	    continue;
	  } else {
	    num_opp[string(&s[k], 1)]++;
	  }
	} else {
	  is_opp[it2->second] = string(&s[k], 1);
	  res.append(string(&s[k], 1));
	  num_opp[string(&s[k], 1)]++;
	  continue;
	}
      }
      res.append(string(&s[k], 1));
    }

    // Print output for case j
    cout << "Case #" << j << ": ";
    cout << "[";
    if (res.size() > 0) {
      cout << res[0];
    }
    for (int i = 1; i < res.size(); i++) {
      cout << ", " << res[i];
    }
    cout << "]" << endl;
  }


  return 0;
}

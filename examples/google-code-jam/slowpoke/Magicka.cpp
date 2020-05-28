#include <fstream>
#include <ext/hash_set>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int toInt(char c){
	return c-'A';
}

int main(){
	ifstream in("B-large.in");
	ofstream out("B-large.out");

	int tc;
	in >> tc;
	for(int c=0; c<tc; c++){
		int combine[26][26];
		int oppose[26];

		for(int i=0; i<26; i++){
			oppose[i] = -1;
			for(int j=0; j<26; j++){
				combine[i][j] = -1;
			}
		}

		int numC;
		in >> numC;
		for(int i=0; i<numC; i++){
			string s;
			in >> s;
			int first = toInt(s[0]);
			int second = toInt(s[1]);
			int result = toInt(s[2]);
			combine[first][second] = result;
			combine[second][first] = result;
		}

		int numO;
		in >> numO;
		for(int i=0; i<numO; i++){
			string s;
			in >> s;
			int first = toInt(s[0]);
			int second = toInt(s[1]);
			oppose[first] = second;
			oppose[second] = first;
		}

		int len;
		string seq;
		in >> len;
		in >> seq;

		hash_multiset<int> set;
		vector<int> cur;

		for(int i=0; i<len; i++){
			int el = toInt(seq[i]);
			if(cur.empty()){
				cur.push_back(el);
				set.insert(el);
			} else{
				int last = cur.back();
				if(combine[el][last] >= 0 ){
					cur.pop_back();
					cur.push_back(combine[el][last]);
					hash_multiset<int>::iterator it = set.find(last);
					if(it!=set.end()){
						set.erase(it);
					}
				} else{
					int op = oppose[el];
					if(set.find(op) != set.end()){
						set.clear();
						cur.clear();
					} else{
						cur.push_back(el);
						set.insert(el);
					}
				}
			}
		}

		out << "Case #" << c+1 << ": " << "[";
		for(int i=0; i<cur.size(); i++){
			out << (char)(cur[i]+'A');
			if(i+1<cur.size()){
				out << ", ";
			}
		}
		out << "]" << endl;

	}

	in.close();
	out.close();
}

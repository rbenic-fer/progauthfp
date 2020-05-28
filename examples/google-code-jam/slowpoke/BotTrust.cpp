#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ifstream in("A-large.in");
	ofstream out("A-large.out");

	int tc;
	in >> tc;
	for(int c=0; c<tc; c++){
		int numButton;
		in >> numButton;
		vector<pair<int,int> > vec;
		for(int i=0; i<numButton; i++){
			string s;
			int n;
			in >> s;
			in >> n;
			if(s[0] == 'O'){
				vec.push_back(make_pair(0, n));
			} else{
				vec.push_back(make_pair(1, n));
			}
		}

		int lastPos[] = {1,1};
		int timing[] = {0,0};

		for(vector<pair<int,int> >::iterator it=vec.begin(); it!=vec.end(); it++){
			int index = it->first;
			int button = it->second;
			int moves = abs(lastPos[index] - button);
			lastPos[index] = button;
			int newTiming = max(timing[index] + moves, timing[!index]) + 1;
			timing[index] = newTiming;
		}

		int finalTiming = max(timing[0], timing[1]);
		out << "Case #" << c+1 << ": " << finalTiming << endl;

	}

	in.close();
	out.close();
}

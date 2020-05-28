#include <fstream>
#include <algorithm>

using namespace std;

int main(){

	ifstream in("D-large.in");
	ofstream out("D-large.out");

	int tc;
	in >> tc;
	for(int c=0; c<tc; c++){
		int n;
		in >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			in >> arr[i];
			arr[i]--;
		}
		int mess = n;
		for(int i=0; i<n; i++){
			if(arr[i] == i){
				mess--;
			}
		}
		out << "Case #" << c+1 << ": " << mess << endl;
	}

	in.close();
	out.close();
}

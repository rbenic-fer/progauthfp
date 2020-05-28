#include <fstream>

using namespace std;

int main(){
	ifstream in("C-large.in");
	ofstream out("C-large.out");

	int tc;
	in >> tc;
	for(int c=0; c<tc; c++){
		int n;
		in >> n;
		int min=1<<30;
		int sum=0;
		int Xor=0;

		for(int i=0; i<n; i++){
			int t;
			in >> t;
			if(t<min) min = t;
			sum += t;
			Xor ^= t;
		}
		if(Xor == 0){
			out << "Case #" << (c+1) << ": " << sum-min << endl;
		} else{
			out << "Case #" << (c+1) << ": NO" << endl;
		}
	}

	in.close();
	out.close();
}

#include <iostream>
#include <string>

using namespace std;
int r, c, mini;
char a[101][101];
bool contin;

void buscar (int i, int j){
	int k;
	for (k=0; k <r;++k )
		if (a[k][j] != '.' && k!=i ){
			++mini;
			return;
		}
	for (k=0; k <c;++k )
	if (a[i][k] != '.' && k!=j ){
		++mini;
		return;
	}
	contin = true;
}


int main() {
    int i, j, t, n, k, cont=0;
    cin >>t;

    bool seguir;


    for (i=0; i<t; i++){
    	mini =0;
    	contin = false;
    	cout << "Case #" << ++cont << ": ";
    	cin >> r >> c;
    	for (j=0; j< r; j++){
    		for (k=0; k< c; k++){
				cin >> a[j][k];
			}
    	}
    	for (j=0; j< r; j++){
    		seguir = false;
    		for (k=0; k< c; k++){
    			if (a[j][k] != '.'){
    				if (a[j][k]=='<') {seguir = true; }
    				break;
    			}
    		}
    		if (seguir){
    			buscar (j, k);
    		}
    	}
    	if (contin){cout << "IMPOSSIBLE" << endl; continue;}
    	for (j=0; j< r; j++){
			seguir = false;
			for (k=c-1; k>=0; --k){
				if (a[j][k] != '.'){
					if (a[j][k]=='>') {seguir = true; }
					break;
				}
			}
			if (seguir){
				buscar (j, k);
			}
		}
    	if (contin){cout << "IMPOSSIBLE" << endl; continue;}
    	for (k=0; k< c; k++){
			seguir = false;
			for (j=0; j< r; j++){
				if (a[j][k] != '.'){
					if (a[j][k]=='^') {seguir = true; }
					break;
				}
			}
			if (seguir){
				buscar (j, k);
			}
		}
    	if (contin){cout << "IMPOSSIBLE" << endl; continue;}
    	for (k=0; k< c; k++){
			seguir = false;
			for (j=r-1; j>=0 ; j--){
				if (a[j][k] != '.'){
					if (a[j][k]=='v') {seguir = true; }
					break;
				}
			}
			if (seguir){
				buscar (j, k);
			}
		}
    	if (contin){cout << "IMPOSSIBLE" << endl; continue;}
    	cout << mini << endl;

    }
    return 0;
}

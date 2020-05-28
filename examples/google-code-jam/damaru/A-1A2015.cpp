#include <iostream>
#include <string>

using namespace std;


int main() {
    int i, j, t, n, cont=1, aux, ant, max, sum2, sum1;
    int an[1001];
    cin >>t;

    for (i=0; i<t; i++){
    	cout << "Case #" << cont++ << ": ";
    	cin >> n;
    	cin >> ant;
    	max =0;
    	sum2 =0;
    	an[0]=ant;
    	for (j=1; j<n; j++){
    		cin >> aux;
    		an[j] = aux;
    		if (aux < ant){
    			if (ant -aux > max) max = ant -aux;
    			sum2+= ant-aux;
    		}
    		ant = aux;
    	}
    	sum1=0;
    	for (j=0; j<n-1; j++){
    		if (an[j] > max) sum1+=max;
    		else sum1+= an[j];
    	}
    	cout << sum2 << " "<< sum1 <<endl;
    }

    return 0;
}
/*

*/

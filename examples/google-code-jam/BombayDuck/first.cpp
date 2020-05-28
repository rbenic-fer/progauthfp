#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long int NoOfInputs;
    cin >> NoOfInputs;
    
    for( long int i = 0; i < NoOfInputs; i++ )
    {
	long int alphaSize, keys, alphabets, temp;
	cin >>alphaSize >> keys >> alphabets;
	
	int * frequency;
	frequency = new int[alphabets];
	long int count = 0;
	
	for(int j=0; j < alphabets; j++)
	{
	    cin >> frequency[j];
	}

	for( int j = 0; j < alphabets -1 ; j++ )
	{
	    int minimum = frequency[j] ;
	    int position = j;
	    for( int k = j + 1; k < alphabets; k++ )
	    {
		int current = frequency[k] ;
		if( minimum > current )
		{
		    minimum = current;
		    position = k;
		}
	    }
	    if( position != j )
	    {
		temp = frequency[j];
		frequency[j] = frequency[position];
		frequency[position] = temp;
	    }
	}

	int r = 1;
	int temp2 = 0;
	for(int j=alphabets-1; j>=0; j--)
	{
	    temp2++;
	    count += frequency[j]*r;
	    if(temp2==keys)
	    {
		temp2=0;
		r++;
	    }
	}
	cout << "Case #" << i+1 << ": " << count << endl;

    }

    return 0;
}


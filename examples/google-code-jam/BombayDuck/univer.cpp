#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int NoOfInputs;
    cin >> NoOfInputs;
//    cout << NoOfInputs << endl;
    int temp = 0;
    for( int i = 0; i < NoOfInputs; i++ )
    {
	//Input for case started
	int NoofEngine;
	cin >> NoofEngine;
	bool *flag;
	flag = new bool[NoofEngine];
	string *SearchEngine;
	SearchEngine = new string[NoofEngine];

	if( NoofEngine != 0 )
	{
	    getline( cin , SearchEngine[0] , '\n' );
	}

//	cout << NoofEngine << endl;

	for( int j = 0; j < NoofEngine; j++ )
	{
	    getline( cin, SearchEngine[j], '\n' );
	    flag[j] = false;
//	    cout << j << SearchEngine[j] << endl;
	}

	

	int NoinList;
	cin >> NoinList;
	string *ListofEngine;
	ListofEngine = new string[NoinList];

//  	cout << NoinList << endl;

	if( NoinList != 0 )
	{
	    getline( cin , ListofEngine[0] , '\n' );
	}

	for( int j = 0; j < NoinList; j++ )
	{
	    getline( cin, ListofEngine[j], '\n' );
//	    cout << j << ListofEngine[j] << endl;
	}
	//Input for case completed

	int NoofSwitch = 0;
	int count = 0;
	int tempvar;
	for( int j = 0; j < NoinList; j++ )
	{
	    
	    for( int k = 0; k < NoofEngine; k++ )
	    {
		if( ListofEngine[j] == SearchEngine[k] )
		{
		    tempvar = k;

		    if( flag[k]!= true )
		    {
			flag[k]= true;
			count++;
		    }
		}
	    }

	    if( count == NoofEngine )
	    {
		NoofSwitch++;
		for( int k = 0; k < NoofEngine; k++ )
		{
		    flag[k] = false;
		}
		flag[tempvar] = true;
		count = 1;
	    }
	}

	cout << "Case #" << (i + 1) << ": " << NoofSwitch << endl;

	
    }

    cout << endl;
    return 0;
}

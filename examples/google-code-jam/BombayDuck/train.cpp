#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

bool comparetime(tm A, tm B, int turntime);
int main()
{
    int NoOfInputs;
    cin >> NoOfInputs;
    
    for( int i = 0; i < NoOfInputs; i++ )
    {
	int TurnAroundTime;
	cin >> TurnAroundTime;
	int TrainA, TrainB;
	cin >> TrainA >> TrainB;
	tm *ArrivalA, *DepartureA, *ArrivalB, *DepartureB;

	ArrivalA = new tm[TrainA];
	DepartureA = new tm[TrainA];
	
	ArrivalB = new tm[TrainB];
	DepartureB = new tm[TrainB];
	
	char tmp;
	for( int j = 0; j < TrainA; j++ )
	{
	    cin >> DepartureA[j].tm_hour;
	    cin >> tmp; 
	    cin >> DepartureA[j].tm_min;
	    cin >> ArrivalA[j].tm_hour;
	    cin >> tmp; 
	    cin >> ArrivalA[j].tm_min;
	}
	
	for( int j = 0; j < TrainB; j++ )
	{
	    cin >> DepartureB[j].tm_hour;
	    cin >> tmp; 
	    cin >> DepartureB[j].tm_min;
	    cin >> ArrivalB[j].tm_hour;
	    cin >> tmp; 
	    cin >> ArrivalB[j].tm_min;
	}

	for( int j = 0; j < (TrainA - 1); j++ )
	{
	    int minimum = 100 * ArrivalA[j].tm_hour + ArrivalA[j].tm_min ;
	    int position = j;
	    for( int k = j + 1; k < TrainA; k++ )
	    {
		int current = 100 * ArrivalA[k].tm_hour + ArrivalA[k].tm_min ;
		if( minimum > current )
		{
		    minimum = current;
		    position = k;
		}
	    }
	    if( position != j )
	    {
		tm temptime = ArrivalA[j];
		ArrivalA[j] = ArrivalA[position];
		ArrivalA[position] = temptime;
	    }
	}

	//cout << "TrainA" << TrainA << endl;
	

	for( int j = 0; j < TrainA ; j++ )
	{
	    //cout << ArrivalA[j].tm_hour << ":" << ArrivalA[j].tm_min << endl;
	}
	

	for( int j = 0; j < (TrainA - 1); j++ )
	{
	    int minimum = 100 * DepartureA[j].tm_hour + DepartureA[j].tm_min ;
	    int position = j;
	    for( int k = j + 1; k < TrainA; k++ )
	    {
		int current = 100 * DepartureA[k].tm_hour + DepartureA[k].tm_min ;
		if( minimum > current )
		{
		    minimum = current;
		    position = k;
		}
	    }
	    if( position != j )
	    {
		tm temptime = DepartureA[j];
		DepartureA[j] = DepartureA[position];
		DepartureA[position] = temptime;
	    }
	}

	//cout << "TrainA" << TrainA << endl;
	

	for( int j = 0; j < TrainA ; j++ )
	{
	    //cout << DepartureA[j].tm_hour << ":" << DepartureA[j].tm_min << endl;
	}

	
	for( int j = 0; j < (TrainB - 1); j++ )
	{
	    int minimum = 100 * ArrivalB[j].tm_hour + ArrivalB[j].tm_min ;
	    int position = j;
	    for( int k = j + 1; k < TrainB; k++ )
	    {
		int current = 100 * ArrivalB[k].tm_hour + ArrivalB[k].tm_min ;
		if( minimum > current )
		{
		    minimum = current;
		    position = k;
		}
	    }
	    if( position != j )
	    {
		tm temptime = ArrivalB[j];
		ArrivalB[j] = ArrivalB[position];
		ArrivalB[position] = temptime;
	    }
	}

	//cout << "TrainB" << TrainB << endl;
	

	for( int j = 0; j < TrainB ; j++ )
	{
	    //cout << ArrivalB[j].tm_hour << ":" << ArrivalB[j].tm_min << endl;
	}

	
	for( int j = 0; j < (TrainB - 1); j++ )
	{
	    int minimum = 100 * DepartureB[j].tm_hour + DepartureB[j].tm_min ;
	    int position = j;
	    for( int k = j + 1; k < TrainB; k++ )
	    {
		int current = 100 * DepartureB[k].tm_hour + DepartureB[k].tm_min ;
		if( minimum > current )
		{
		    minimum = current;
		    position = k;
		}
	    }
	    if( position != j )
	    {
		tm temptime = DepartureB[j];
		DepartureB[j] = DepartureB[position];
		DepartureB[position] = temptime;
	    }
	}

	//cout << "TrainB" << TrainB << endl;
	

	for( int j = 0; j < TrainB ; j++ )
	{
	    //cout << DepartureB[j].tm_hour << ":" << DepartureB[j].tm_min << endl;
	}

// sorting ends here . the algorithm starts now

	int limit = 0;
	int countA = TrainA, countB = TrainB;

	for(int j = 0 ; j < TrainA ; j++)
	{
	    for(int k = limit ; k < TrainB ; k++)
	    {
		if (comparetime( ArrivalA[j], DepartureB[k], TurnAroundTime)== true)
		{
		    countB--;
		    //cout << "times are" << ArrivalA[j].tm_hour << DepartureB[k].tm_hour << endl;
		    limit = k+1;
		    break;
		} 

	    }
	}

	//cout << "count B is " << countB << endl;
	
	limit = 0;	
	for(int j = 0 ; j < TrainB ; j++)
	{
	    for(int k = limit ; k < TrainA ; k++)
	    {
		if (comparetime( ArrivalB[j], DepartureA[k], TurnAroundTime)== true)
		{
		    countA--;
		    //cout << "times are" << ArrivalB[j].tm_hour << DepartureA[k].tm_hour << endl;
		    limit = k+1;
		    break;
		} 

	    }
	}

	//cout << "count A is " << countA << endl;

	cout << "Case #" << ( i + 1 ) << ": " << countA << " " << countB << endl;
    }

    return 0;
}



bool comparetime(tm A, tm B, int turntime)
{
    if(A.tm_hour*60 + A.tm_min + turntime <= B.tm_hour*60 + B.tm_min )
	return true;
    else
	return false;
}



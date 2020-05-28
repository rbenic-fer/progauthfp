#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<queue>
#include<algorithm>
#define MAXSIZE 100000
using namespace std ;
int main()
{
	//freopen( "C-small-attempt0 (1).in" , "r" , stdin ) ;
	FILE *in = fopen( "C-large (1).in" , "r" ) ;
	FILE *out = fopen( "output3.txt" , "w" ) ;
	//freopen( "output3.txt" , "w" , stdout ) ;
	int T , t , sum , N , i ;
	int candy[MAXSIZE] , ans ;
	fscanf( in , "%d" , &t ) ;
	T = t ;
	while( t-- )
	{
		memset( candy , 0 , sizeof( candy ) ) ;
		ans = sum = 0 ;
		fscanf( in , "%d" , &N ) ;
		for( i = 0 ; i < N ; i++ )
		{
			fscanf( in , "%d" , &candy[i] ) ;
			sum += candy[i] ;
			ans = ans ^ candy[i] ;
		}	
		sort( candy , candy+N ) ;
		fprintf( out , "Case #%d: " , T - t ) ;
		if( ans != 0 )
			fprintf( out , "NO\n" ) ;
		else
			fprintf( out , "%d\n" , sum - candy[0] ) ;
	}
	return 0 ;
}

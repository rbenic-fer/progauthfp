#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<queue>
#include<algorithm>
#define MAXSIZE 100000
using namespace std ;
int main( )
{
	//freopen( "C-small-attempt0 (1).in" , "r" , stdin ) ;
	FILE *in = fopen( "D-large.in" , "r" ) ;
	FILE *out = fopen( "output4.txt" , "w" ) ;
	//freopen( "output3.txt" , "w" , stdout ) ;
	int T , t , sum , N , i ;
	int number , ans ;
	fscanf( in , "%d" , &t ) ;
	T = t ;
	while( t-- )
	{
		ans = 0 ;
		fscanf( in , "%d" , &N ) ;
		for( i = 0 ; i < N ; i++ )
		{
			fscanf( in , "%d" , &number ) ;	
			if( i+1 != number )
				ans++ ;
		}
		fprintf( out , "Case #%d: " , T - t ) ;
		fprintf( out , "%d.000000\n" , ans ) ;
	}
	return 0 ;
}

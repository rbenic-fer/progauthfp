#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
#define MAXSIZE 100000
using namespace std ;
int main( )
{
	//freopen( "C-small-attempt0 (1).in" , "r" , stdin ) ;
	FILE *in = fopen( "ABigin.in" , "r" ) ;
	//FILE *in = fopen( "test.in" , "r" ) ;
	FILE *out = fopen( "out.txt" , "w" ) ;
	//freopen( "output3.txt" , "w" , stdout ) ;
	int T , t ;
	bool ans ;
	long long int N , i , j , PD , PG  ;
	fscanf( in , "%d" , &t ) ;
	T = t ;
	while( t-- )
	{
		ans = false ;
		fscanf( in , "%I64d %I64d %I64d" , &N , &PD , &PG ) ;
		if( PG != 0 && PG != 100 )
		{
			for( i = 1 ; i <= N ; i++ )
			{
				if( i * PD % 100 == 0 )
				{
					for( j = i ;  ; j++ )
					{
						if( i * PD <= PG * j && j * PG % 100 == 0 )
						{
							ans = true ;
							break ;
						}	
					}
				}	
				if( ans )
					break ;
			}
		}
		if( ans || ( PD == 0 && PG == 0 ) || ( PD == 100 && PG == 100 ) )
			fprintf( out , "Case #%d: Possible\n" , T - t ) ;
		else
			fprintf( out , "Case #%d: Broken\n" , T - t ) ;
	}
	system("pause");
	return 0 ;
}

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
#define MAXSIZE 500
using namespace std ;
int main( )
{
	//freopen( "C-small-attempt0 (1).in" , "r" , stdin ) ;
	FILE *in = fopen( "test.in" , "r" ) ;
	//FILE *in = fopen( "test.in" , "r" ) ;
	FILE *out = fopen( "out.txt" , "w" ) ;
	int T , t ;
	int n , i , j ;
	double wp , owp , oowp , mother , rpi , tmp[3] = { 0 , 0.5 , 1 } ;
	fscanf( in , "%d" , &t ) ;
	T = t ;
	while( t-- )
	{
		fscanf( in , "%d" , &n ) ;
		char map[MAXSIZE][MAXSIZE] ;
		double wwp[MAXSIZE] , motherr[MAXSIZE] ;
		double RPI[MAXSIZE] , WP[MAXSIZE] , OWP[MAXSIZE] , OOWP[MAXSIZE] ;
		for( i = 0 ; i < n  ; i++ )
			fscanf( in ,"%s" , &map[i] ) ;
			
		for( i = 0 ; i < n  ; i++ )
		{
			wp = 0 ;
			mother = 0 ;
			for( j = 0 ; j < n ; j++ )
			{	
				if( map[i][j] == '1' )
				{
					mother++ ;
					wp++ ;
				}
				else if( map[i][j] == '0' )
				{
					mother++ ;		
				}
			}			
			wwp[i] = wp ;
			motherr[i] = mother ;
			WP[i] = wp / mother ;
		}
		for( i = 0 ; i < n  ; i++ )
		{
			owp = 0 ;
			mother = 0 ;
			for( j = 0 ; j < n ; j++ )
			{	
				
				if( map[j][i] == '1' )
				{
					owp += (wwp[j]-1) / (motherr[j]-1) ;//printf("x%lf %lf %lf\n" , owp , wwp[j] , motherr[j] );
				}
				else if( map[j][i] == '0' )
				{	
					owp += (wwp[j]) / (motherr[j]-1) ;//printf("u%lf %lf %lf\n" , owp , wwp[j] , motherr[j] );	
				}
				
			}
			OWP[i] = owp / motherr[i] ;
		}		
		//system("pause");
		for( i = 0 ; i < n  ; i++ )
		{
			oowp = 0 ;
			mother = 0 ;
			for( j = 0 ; j < n ; j++ )
			{
				
				if( map[i][j] == '1' )
				{
					mother++ ;
					oowp += OWP[j] ;
				}
				else if( map[i][j] == '0' )
				{
					mother++ ;	
					oowp += OWP[j] ;
				}
			}
			OOWP[i] = oowp / mother ;
		}		
		fprintf( out , "Case #%d:\n" , T - t ) ;
		for( i = 0 ; i < n ; i++ )
		{
			//fprintf( out , "%lf %lf %lf\n"  , WP[i] , OWP[i] ,  OOWP[i] ) ;
				fprintf( out , "%.6lf\n" , 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i] ) ;
		}
	}
	
	return 0 ;
}

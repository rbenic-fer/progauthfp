#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<queue>
#define MAXSIZE 120
using namespace std ;
char s[MAXSIZE] , newlist[MAXSIZE] ;		
char com[MAXSIZE][4] , opp[MAXSIZE][4] ;	
int c_m  , o_m , N ;
void f(  )
{
	int i = 0 , j , k = 0 , co = 0 ; 
	char tra[MAXSIZE] = "" ;	
	for( i = strlen( newlist )-1 ; i >= 0 ; )
	{
		co = 0 ;
		for( j = 0 ; j < c_m ; j++ )
		{
			if( com[j][0] == newlist[i] && com[j][1] == newlist[i-1] )
			{
				tra[k++] = com[j][2] ;
				i -= 2 ;
				co = 1 ;
				break ;
			}
			if( com[j][1] == newlist[i] && com[j][0] == newlist[i-1] )
			{
				tra[k++] = com[j][2] ;
				i -= 2 ;
				co = 1 ;
				break ;
			}
		}
		if( co == 0 )
		{
			tra[k++] = newlist[i] ;
			i-- ;
		}
	}
	tra[k] = '\0' ;
	k = 0 ;
	for( i = strlen( tra )-1 ; i >= 0 ; i-- )
		newlist[k++] = tra[i] ;
	newlist[k] = '\0' ;	
}
void g(  )
{
	int i , j , k = 0 , l , co = 0 ; 
	for( i = strlen( newlist )-1 ; i >= 0 ; )
	{
		co = 0 ;
		for( j = 0 ; j < o_m ; j++ )
		{
			if( opp[j][0] == newlist[i] )
			{
				for( l = 0 ; l <= i-1 ; l++ )
					if( newlist[l] == opp[j][1] )
					{
						i = l-1 ;
						co = 1 ;
						newlist[0] = '\0' ;
						break ;
						
					}
			}
			if( opp[j][1] == newlist[i] )
			{
				for( l = 0 ; l <= i-1 ; l++ )
					if( newlist[l] == opp[j][0] )
					{
						co = 1 ;
						i = l-1 ;
						newlist[0] = '\0' ;
						break ;
					}	
			}
			if( co == 1 )
				break ;
		}
		if( co == 0 )
			i-- ;
		if( co == 1 )
			break ;
	}
}
int main( )
{
	int T , t , i , j , k , len ;
	FILE *in = fopen( "B-large.in" , "r" ) ;
	fscanf( in , "%d" , &T ) ;
	t = T ;
	FILE *file = fopen( "output2-2.txt" , "w" ) ;
	while( t-- )
	{
		fscanf( in , "%d" , &c_m ) ;
		for( i = 0 ; i < c_m ; i++ )
			fscanf( in , "%s" , &com[i] ) ;
		fscanf( in , "%d" , &o_m ) ;
		for( i = 0 ; i < o_m ; i++ )
			fscanf( in , "%s" , &opp[i] ) ;
		fscanf( in , "%d" , &N ) ;
		fscanf( in , "%s" , &s ) ;
		newlist[0] = '\0' ;
		j = k = 1 ;
		for( i = 0 ; i < N ; i++ )
		{
			len = strlen( newlist ) ;
			newlist[len] = s[i] ;
			newlist[len+1] = '\0' ;
			f( ) ;
			g( ) ;
		}
		fprintf( file , "Case #%d: " , T-t ) ;
		fprintf( file , "[" ) ;
		for( i = 0 ; i < strlen( newlist ) ; i++ )
		{
			if( i == strlen( newlist ) -1 )
				fprintf( file , "%c" , newlist[i] ) ; 
			else
				fprintf( file , "%c, " , newlist[i] ) ; 
		}
		fprintf( file , "]\n" ) ;
	}
	return 0 ;
}

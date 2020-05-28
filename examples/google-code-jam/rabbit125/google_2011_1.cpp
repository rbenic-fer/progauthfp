#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<queue>
#define MAXSIZE 120
using namespace std ;
struct G
{
	int r , s ;
};
G c ;
vector<G> total ;
int main( )
{
	int T , t , n , p , ans1 , ans2 , ans , now1 , now2 , i , j ;
	bool A[MAXSIZE] , B[MAXSIZE] ;
	vector<int> a , b ;
	char r ; 	
	FILE *in = fopen( "A-large.in" , "r" ) ;
	fscanf( in , "%d" , &T ) ;
	t = T ;

	FILE *file = fopen( "output.txt" , "w" ) ;
	while( t-- )
	{
		ans = ans1 = ans2 = 0 ;
		now1 = now2 = 1 ;
		a.clear( ) ;
		b.clear( ) ;
		total.clear( ) ;
		memset( A , false , sizeof( A ) ) ;
		memset( B , false , sizeof( B ) ) ;
		fscanf( in , "%d" , &n ) ;
		for( i = 0 ; i < n ; i++ )
		{
			fscanf( in , " %c%d" , &r , &p ) ;
			if( r == 'O' )
			{
				A[p] = true ;
				c.r = 1 ;
				c.s = p ;
				total.push_back( c ) ;
			}
			if( r == 'B' )
			{
				B[p] = true ;
				c.r = 2 ;
				c.s = p ;
				total.push_back( c ) ; 
			}
		}
		for( i = 1 ; i <= 100 ; i++ )
		{
			if( A[i] == true )
				a.push_back( i ) ;
			if( B[i] == true )
				b.push_back( i ) ;
		}
		for( i = 0 ; i < total.size( ) ; i++ )
		{
			if( total[i].r == 1 )
			{
				ans1 += max( total[i].s , now1 ) - min( total[i].s , now1 ) + 1 ;
				if( total[i-1].r == 2 && i != 0 )
				{
					if( ans1 <= ans2 )
						ans1 = ans2 + 1  ;
				}				
				now1 = total[i].s ;
			}	
			if( total[i].r == 2 )	
			{		
				ans2 += max( total[i].s , now2 ) - min( total[i].s , now2 ) + 1 ;
				if( total[i-1].r == 1 && i != 0 )
				{
					if( ans2 <= ans1 )
						ans2 = ans1 + 1  ;
				}
				now2 = total[i].s ;
			}
			//printf( "%d : %d %d\n" , i , ans1 , ans2 ) ;
		}
		fprintf( file , "Case #%d: " , T-t ) ;
		fprintf( file , "%d\n" , max( ans1 , ans2 ) ) ;
	}
	return 0 ;
}

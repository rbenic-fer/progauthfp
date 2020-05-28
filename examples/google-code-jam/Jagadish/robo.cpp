#include<iostream>
#include<stdio.h>

using namespace std;
int q[101],orange_q[101],blue_q[101];
int top_q = 0,top_oq = 0, top_bq = 0;
int cur_o = 1, cur_b = 1;
int cur_oq = 0, cur_bq = 0;

int main(){
	int T = 0,L =0;
	int a = 0,i = 0,value = 0,next_rob = 0, b_dest = 0, o_dest = 0, time_dest = 0, min_time = 0;
	char c;
	scanf("%d\n",&T);
	for(a = 1; a<=T; a++){
		top_q = 0;
		top_oq = 0;
		top_bq = 0;
		cur_o = 1;
		cur_b = 1;
		cur_oq = 0;
		cur_bq = 0;
		b_dest = 0;
		o_dest = 0;
		min_time = 0;
		scanf("%d",&L);
		for(i=0;i<L; i++){
			scanf(" %c %d",&c,&value);
			if(c == 'B'){
				q[top_q++] = 'B';
				blue_q[top_bq++] = value;
			}
			else if(c== 'O'){
				q[top_q++] = 'O';
				orange_q[top_oq++] = value;
			}
		}
		for(i=0;i<top_q;i++){
			next_rob = q[i];
			time_dest = 0;
			if(next_rob == 'B'){
				b_dest = blue_q[cur_bq++];
				time_dest = (b_dest>= cur_b)? (b_dest - cur_b): (cur_b - b_dest);
				time_dest += 1;
				min_time += time_dest;
				//cout<<"Before cur_b = "<<cur_b<<endl;
				cur_b = b_dest;
				if(cur_oq < top_oq){
					o_dest = orange_q[cur_oq];
					if(o_dest != cur_o){
						if(o_dest > cur_o)
							cur_o = (cur_o+time_dest <= o_dest)?(cur_o+time_dest):(o_dest);
						else  cur_o = (cur_o - time_dest >=  o_dest)?(cur_o-time_dest):(o_dest);
					}
				}
				
			}
			else if(next_rob == 'O'){
				o_dest = orange_q[cur_oq++];
				time_dest = (o_dest>= cur_o)? (o_dest - cur_o): (cur_o - o_dest);
				time_dest += 1;
				min_time += time_dest;
				//cout<<"Before cur_o = "<<cur_o<<endl;
				cur_o = o_dest;
				if(cur_bq < top_bq){
					b_dest = blue_q[cur_bq];
					if(b_dest != cur_b){
						if(b_dest > cur_b)
							cur_b = (cur_b+time_dest <= b_dest)?(cur_b+time_dest):(b_dest);
						else  cur_b = (cur_b - time_dest >=  b_dest)?(cur_b-time_dest):(b_dest);
					}
				}
				
			}
/*
cout<<" next_rob = "<<next_rob<<" min_time = "<<min_time<<" time_dest = "<<time_dest<<" cur_b = "<<cur_b<<" cur_o = "<< cur_o<<" b_dest = "<<b_dest<<" o_dest = "<<o_dest<<endl<<flush;
*/
			
		}
		printf("Case #%d: %d\n",a, min_time);
	}

	return(0);
}
			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_DIGITS 21

int totalDigits;

char * nextNumber(char * number, int digits);
void qSort(char numbers[],int a,int b);

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int caseId,T;
    char number[MAX_DIGITS+2];
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("nextNumber.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("nextNumber.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
       }
    fscanf(fin,"%d",&T);
    for (caseId=1;caseId<=T;caseId++)
    {
       fscanf(fin,"%s",number+1);
       totalDigits=strlen(number+1);
       fprintf(fout,"Case #%d: %s\n",caseId,nextNumber(number+1,totalDigits));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

char * nextNumber(char * number, int digits)
{
    int i;
    char ch;
       
    if(digits==1)
    {
       if(totalDigits==1)
       {
          *(number-1)=number[0];
          number[0]='0';
          return number-1;
       }
       else
          return NULL;
    }
    if(nextNumber(number+1,digits-1)==NULL)
    {
       if(number[0]>=number[1])
       {
          if(digits<totalDigits)
             return NULL;
          else
          {
             for(i=digits-1;i>0 && number[i]=='0';i--)
                ;
             *(number-1)=number[i];
             number[i]='0';
             qSort(number,0,digits-1);
             totalDigits++;
             return number-1;
          }
       }
       else
       {
          for(i=digits-1;number[0]>=number[i];i--)
             ;
          ch=number[0];
          number[0]=number[i];
          number[i]=ch;
          qSort(number+1,0,digits-2);
          return number;
       }
    }
    else
       return number;
}


void qSort(char numbers[],int a,int b)
{
  int ll,rr,pp;
  char p;
  
  p=numbers[a];
  ll=a;
  rr=b;
  while(a<b){
     while((numbers[b]>=p)&&(a<b))
        b--;
     if(a!=b){
        numbers[a]=numbers[b];
        a++;
        }
     while((numbers[a]<=p)&&(a<b))
        a++;
     if(a!=b){
        numbers[b]=numbers[a];
        b--;
        }
     }
  numbers[a]=p;
  pp=a;
  a=ll;
  b=rr;
  if(a<pp)
     qSort(numbers,a,pp-1);
  if(b>pp)
     qSort(numbers,pp+1,b);
}



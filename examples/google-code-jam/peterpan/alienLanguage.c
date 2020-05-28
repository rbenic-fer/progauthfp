#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXL 15
#define MAXD 5000

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int i,j,D,L,N,caseId,entry,counter;
    char * dictionary[MAXD], * lemma, ch;
    bool breakFlag, filter[MAXL][256];
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("alienLanguage.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("alienLanguage.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
       }
    fscanf(fin,"%d",&L);
    fscanf(fin,"%d",&D);
    fscanf(fin,"%d",&N);
    for (entry=0;entry<D;entry++)
    {
       lemma = (char *) malloc((L+1)*sizeof(char));
       if(lemma==NULL)
          exit(1);
       lemma[L]=0;
       for(i=0;i<L;i++)
       {
          do
          {
             lemma[i]=getc(fin);
          }
          while((lemma[i]<'a' || lemma[i]>'z') && lemma[i]!=EOF);
          if(lemma[i]==EOF)
             exit(1);
       }
       dictionary[entry]=lemma;
    }
    /*****************************************
    for(entry=0;entry<D;entry++)
       fprintf(fout,"%s\n",dictionary[entry]);
    return 0;
    *****************************************/
    for (caseId=1;caseId<=N;caseId++)
    {
       for(i=0;i<L;i++)
       {
          for(j='a';j<='z';j++)
             filter[i][j]=false;
          do
             ch=getc(fin);
          while((ch<'a' || ch>'z') && ch!='(' && ch!=EOF);
          if(ch==EOF)
             exit(1);
          if(ch!='(')
             filter[i][(int) ch]=true;
          else
          {
             for(ch=getc(fin);ch!=')' && ch!=EOF;ch=getc(fin))
                filter[i][(int) ch]=true;
             if(ch==EOF)
                exit(1);
          }
       }
       counter=0;
       for(entry=0;entry<D;entry++)
       {
          breakFlag=false;
          for(i=0;i<L;i++)
             if(!filter[i][(int) (dictionary[entry][i])])
             {
                breakFlag=true;
                break;
             }
          if(breakFlag==false)
             counter++;
       }
       fprintf(fout,"Case #%d: %d\n",caseId,counter);
    }
    fclose(fin);
    fclose(fout);
    for (entry=0;entry<D;entry++)
       free(dictionary[entry]);
    return 0;
}

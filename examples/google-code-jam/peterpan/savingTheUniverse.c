#include <stdio.h>

int iseq(char *s1, char *s2);
int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int N,n,i,j,k,S,Q,eng[100],sum,switches;
    char engines[100][102],word[102],ch;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("savingTheUniverse.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("savingTheUniverse.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
       }
    fscanf(fin,"%d\n",&N);
       /***************
       printf("Cases: %d\n",N);
       //getchar();
       /***************/
    for (n=1;n<=N;n++){
       switches=0;
       fscanf(fin,"%d",&S);
       /***************
       printf("#egines: %d\n",S);
       //getchar();
       /***************/
       do
          fscanf(fin,"%c",&ch);
       while (ch!='\n');
       for (i=0;i<S;i++){
          fgets(engines[i],102,fin);
          /***************
          printf("egine #%d:%s.\n",i+1,engines[i]);
          //getchar();
          /***************/
          eng[i]=1;
          }
       fscanf(fin,"%d",&Q);
       /***************
       printf("#queries: %d\n",Q);
       //getchar();
       /***************/
       do
          fscanf(fin,"%c",&ch);
       while (ch!='\n');
       sum=S;
       for (i=0;i<Q;i++){
          fgets(word,102,fin);
          for (j=0;j<S;j++)
             if (iseq(engines[j],word))
                break;
          if(j==S) {printf("BUG!!\ncase #%d\nword #%d/%d:%s.\n",n,i+1,Q,word); system("pause");}
          /***************
          printf("word #%d ->%d:%s.\n",i+1,j+1,word);
          //getchar();
          /***************/
          if (eng[j]){
             sum--;
             if (!sum){
                switches++;
                sum=S-1;
                for (k=0;k<S;k++)
                   eng[k]=1;
                }
             eng[j]=0;
             }
          /***************
          printf("sum:%d ",sum);
          for(j=0;j<S;j++) printf("%d",eng[j]);
          printf("\n");
          //getchar();
          /***************/
          }
       fprintf(fout,"Case #%d: %d\n",n,switches);
       }
       fclose(fin);
       fclose(fout);
    return 0;
}

int iseq(char *s1, char *s2){
   int i=0;
   while (s1[i] && s2[i] && s1[i]==s2[i]) i++;
   if (s1[i]==s2[i])
      return 1;
   if ((s1[i]==0 && s2[i]=='\n') || (s2[i]==0 && s1[i]=='\n'))
      return 2;
   return 0;
}

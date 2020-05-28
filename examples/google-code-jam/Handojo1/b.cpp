#include<iostream>
#include<string>
#include<cstring>

using namespace std;

char hasil[1000];
char ngaruh[300][300];
bool hapus[300][300];
int kasus,sem,isi;
string haha;

int main()
{
	scanf("%d",&kasus);
	for (int l=1;l<=kasus;l++)
	{
		memset(ngaruh,0,sizeof(ngaruh));
		memset(hapus,0,sizeof(hapus));
		scanf("%d",&sem);
		for (int i=1;i<=sem;i++)
		{
			cin>>haha;
			ngaruh[haha[1]][haha[0]] = ngaruh[haha[0]][haha[1]] = haha[2];
		}
		
		scanf("%d",&sem);
 		for (int i=1;i<=sem;i++)
		{
			cin>>haha;
			hapus[haha[1]][haha[0]] = hapus[haha[0]][haha[1]] = true;
		}
		
		scanf("%d",&sem);
		cin>>haha;
		isi = 0;
		for (int i=0;i<sem;i++)
		{
			isi++;
			hasil[isi] = haha[i];
			if (isi == 1) continue;
			
			if (ngaruh[hasil[isi]][hasil[isi-1]])
			{
				hasil[isi-1] = ngaruh[hasil[isi]][hasil[isi-1]];
				isi--;
			}
			
			for (int j=1;j<isi;j++)
			{
				if (hapus[hasil[j]][hasil[isi]])
				{
					isi = 0;
					break;
				}
			}
		}
		
		printf("Case #%d: [",l);
		if (isi > 0)
		{
			printf("%c",hasil[1]);
			for (int i=2;i<=isi;i++) printf(", %c",hasil[i]);
		}
		printf("]\n");
	}
	return 0;
}

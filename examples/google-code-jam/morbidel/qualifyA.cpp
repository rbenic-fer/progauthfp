/*
 *  Google Code Jam 2009
 *  Qualification Round - Problem A - Alien Language
 */


#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

#define INPUT_FILE    "input.txt"
#define OUTPUT_FILE   "output.txt"

int L, D, N;
vector<vector<string> > Patterns;
vector<string> Words;


void ProcessPattern(int pz, char *patt)
{
  int group;
  int i, cnt, len = strlen(patt);

  cnt = 0;
  group = 0;
  for (i = 0; i < len; i++)
    {
      if (patt[i] == '(')
	{
	  group = 1;
	}
      else if (patt[i] == ')')
	{
	  cnt++;
	  group = 0;
	}
      else
      if (group)
	{
	  int poz = patt[i] - 'a';
	  Patterns[pz][cnt][poz] = '1';
	}
      else if (!group)
	{
	  int poz = patt[i] - 'a';
	  Patterns[pz][cnt][poz] = '1';
	  cnt++;
	}
    }
}

void ReadData()
{
  int i, j;
  char sz[1024];
  char patt[64];


  freopen(INPUT_FILE, "rt", stdin);

  scanf("%ld %ld %ld", &L, &D, &N);

  for (i = 0; i < D; i++)
    {
      scanf("%s\n", &sz);
      Words.push_back(sz);
    }

  Patterns.resize(N);

  for (i = 0; i < N; i++)
    {
      Patterns[i].resize(L);

      for (j = 0; j < L; j++)
	Patterns[i][j] = "                                ";
    }

  for (i = 0; i < N; i++)
    {
      scanf("%s\n", &sz);

      memset(patt, 0, sizeof(patt));
      ProcessPattern(i, sz);
    }

  fclose(stdin);
}

int Match(string w, vector<string> &patt)
{
  int i;

  for (i = 0; i < L; i++)
    {
      int poz = w[i] - 'a';

      if (patt[i][poz] != '1')
	return 0;
    }

  return 1;
}

void Solve()
{
  int i, j, sol = 0;

  freopen(OUTPUT_FILE, "wt", stdout);

  for (i = 0; i < N; i++)
    {
      sol = 0;

      for (j = 0; j < D; j++)
	{
	  sol += Match(Words[j], Patterns[i]);
	}

      printf("Case #%d: %d\n", i + 1, sol);
    }

  fclose(stdout);
}


int main()
{
  ReadData();
  Solve();
  return 0;
}

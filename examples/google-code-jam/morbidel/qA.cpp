/*
 * Google Code Jam 2011
 * Qualifying Round - Problem A - Bot Trust
 */

#include <stdio.h>

#define MAXN	128
#define INPUT	"A-large.in"
#define OUTPUT	"A-large.out"

struct Instr
{
	int robot, button;
} I[MAXN];
int T, N;


void ReadData()
{
	int i;
	char ch;

	scanf("%d ", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%c %d ", &ch, &I[i].button);

		I[i].robot = (ch == 'O') ? 1 : 0;
	}
}

int Solve()
{
	int i, j, count;
	char pos[2];
	int ipos = 0;	/* current instruction to analyse. 0..ipos - 1 instr are already done */


	pos[0] = pos[1] = 1;

	if (N == 0)
		return 0;

	/* we do not iterate on instructions, but on seconds! 
	 * determine on each second what is to be done
	 */
	for (count = 1; count < 100000; count++)
	{
		//printf("sec %d: \n", count);

		/* search other's robot next instruction */
		for (i = ipos + 1; i < N; i++)
			if (I[i].robot != I[ipos].robot)
			{
				break;
			}

		/* the robot from current instruction is not at position -> move */
		if (I[ipos].button != pos[I[ipos].robot])
		{
			pos[I[ipos].robot] += (I[ipos].button > pos[I[ipos].robot]) ? 1 : -1;
			//printf("robot %d MOVE to %d.\n", I[ipos].robot, pos[I[ipos].robot]);
		}
		else
		{
			/* robot is at position -> push button */
			//printf("robot %d PUSH button at %d.\n", I[ipos].robot, pos[I[ipos].robot]);
			ipos ++;

			/* all instructions processed ? */
			if (ipos == N)
			{
				break;
			}
		}

		if (i != N)
		{
			/* found the next instruction for the other robot */
			/* we either can move it towards that button or stay */

			if (I[i].button != pos[I[i].robot])
			{
				pos[I[i].robot] += (I[i].button > pos[I[i].robot]) ? 1 : -1;
				//printf("robot %d MOVE to %d.\n", I[i].robot, pos[I[i].robot]);
			}
			else
			{
				/* stay */
				//printf("robot %d STAY at %d.\n", I[i].robot, pos[I[i].robot]);
			}
		}
	}

	return count;
}


int main()
{
	int i;

	freopen(INPUT, "rt", stdin);
	scanf("%d\n", &T);

	freopen(OUTPUT, "wt", stdout);
	for (i = 1; i <= T; i++)
	{
		ReadData();
		printf("Case #%d: %d\n", i, Solve());
	}

	return 0;
}
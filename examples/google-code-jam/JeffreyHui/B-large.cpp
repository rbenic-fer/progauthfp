#include <cstdio>
bool solution;
int T;
int N, R, O, Y, G, B, V;
int R1, O1, Y1, G1, B1, V1, R2, Y2, B2;

void red(){
	if (G1 > 1){
		printf("RGR");
		R -= 2;
		G--;
		R1--;
		G1--;
	} else if (G1 == 1){
		for (int j = 0; j < G; j++)
			printf("RG");
		printf("R");
		R -= G + 1;
		G = 0;
		R1--;
		G1--;
	} else {
		printf("R");
		R1--;
	}
}

void yellow(){
	if (V1 > 1){
		printf("YVY");
		Y -= 2;
		V--;
		Y1--;
		V1--;
	} else if (V1 == 1){
		for (int j = 0; j < V; j++)
			printf("YV");
		printf("Y");
		Y -= V + 1;
		V = 0;
		Y1--;
		V1--;
	} else {
		printf("Y");
		Y1--;
	}
}

void blue(){
	if (O1 > 1){
		printf("BOB");
		B -= 2;
		O--;
		B1--;
		O1--;
	} else if (O1 == 1){
		for (int j = 0; j < O; j++)
			printf("BO");
		printf("B");
		B -= O + 1;
		O = 0;
		B1--;
		O1--;
	} else {
		printf("B");
		B1--;
	}
}
int main (){
	freopen ("B-large.in", "r", stdin);
	freopen ("B-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d %d %d %d %d %d", &N, &R, &O, &Y, &G, &B, &V);
		printf("Case #%d: ", i);
		if (R < G)
			printf("IMPOSSIBLE");
		else if (Y < V)
			printf("IMPOSSIBLE");
		else if (B < O)
			printf("IMPOSSIBLE");
		else if (R == G && G > 0){
			if (N == R + G){
				for (int i = 0; i < R; i++)
					printf("RG");
			} else {
				printf("IMPOSSIBLE");
			}
		} else if (Y == V && V > 0){
			if (N == Y + V){
				for (int i = 0; i < Y; i++)
					printf("YV");
			} else {
				printf("IMPOSSIBLE");
			}
		} else if (B == O && O > 0){
			if (N == B + O){
				for (int i = 0; i < B; i++)
					printf("BO");
			} else {
				printf("IMPOSSIBLE");
			}
		} else {
			solution = true;
			if (G > 0){
				R1 = R - G;
				G1 = 1;
			} else {
				R1 = R;
				G1 = 0;
			}
			if (V > 0){
				Y1 = Y - V;
				V1 = 1;
			} else {
				Y1 = Y;
				V1 = 0;
			}
			if (O > 0){
				B1 = B - O;
				O1 = 1;
			} else {
				B1 = B;
				O1 = 0;
			}
			while (solution && (R1 > Y1 + B1 || Y1 > R1 + B1 || B1 > R1 + Y1)){
				solution = false;
				while (R1 > Y1 + B1 && G1 < G && R1 > 0){
					solution = true;
					R1--;
					G1++;
				}
				while (Y1 > R1 + B1 && V1 < V && Y1 > 0){
					solution = true;
					Y1--;
					V1++;
				}
				while (B1 > R1 + Y1 && O1 < O && B1 > 0){
					solution = true;
					B1--;
					O1++;
				}
			}
			if (!solution){
				printf("IMPOSSIBLE");
			} else {
				if (R1 >= Y1 && R1 >= B1){
					if (R1 > Y1 + B1)
						printf("IMPOSSIBLE");
					else {
						while (R1 < Y1 + B1){
							if (R1 > 0)
								red();
							if (Y1 > 0)
								yellow();
							if (B1 > 0)
								blue();
						}
						Y2 = Y1;
						for (int j = 0; j < Y2; j++){
							red();
							yellow();
						}
						B2 = B1;
						for (int j = 0; j < B2; j++){
							red();
							blue();
						}
					}
				} else if (Y1 >= R1 && Y1 >= B1){
					if (Y1 > R1 + B1)
						printf("IMPOSSIBLE");
					else {
						while (Y1 < R1 + B1){
							if (Y1 > 0)
								yellow();
							if (R1 > 0)
								red();
							if (B1 > 0)
								blue();
						}
						R2 = R1;
						for (int j = 0; j < R2; j++){
							yellow();
							red();
						}
						B2 = B1;
						for (int j = 0; j < B2; j++){
							yellow();
							blue();
						}
					}
				} else {
					if (B1 > R1 + Y1)
						printf("IMPOSSIBLE");
					else {
						while (B1 < R1 + Y1){
							if (B1 > 0)
								blue();
							if (R1 > 0)
								red();
							if (Y1 > 0)
								yellow();
						}
						R2 = R1;
						for (int j = 0; j < R2; j++){
							blue();
							red();
						}
						Y2 = Y1;
						for (int j = 0; j < Y2; j++){
							blue();
							yellow();
						}
					}
				}
			}
		}
		printf("\n");
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}

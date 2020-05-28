// Luke Harrison
// 03/05/10

#include <stdio.h>
#include <stdlib.h>

int main () {
   FILE *input = fopen ("snapperin.txt", "r");
   FILE *output = fopen ("snapperout.txt", "w");
   int numCases;
   int i;
   int snappers, snaps;
   fscanf (input, "%d ", &numCases);
   int pwr;
   for (i = 0; i < numCases; i++) {
      fscanf (input, "%d %d ", &snappers, &snaps);
      pwr = 1 << snappers;
      fprintf (output, "Case #%d: ", i + 1);
      if ((snaps % pwr) == pwr - 1) {
         fprintf (output, "ON\n");
      } else {
         fprintf (output, "OFF\n");
      }
   }

   fclose (input);
   fclose (output);
   return 0;
}





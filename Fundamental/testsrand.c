#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main() {
   // Lower bound
   int lb = 20; 
   // Upper bound
   int ub = 100;
   
   // Initialize random seed based on current time
   srand(time(NULL)); 
   
   int i;
   for (i = 0; i < 5; i++) {
      // Generate a random number between lb and ub (inclusive)
      printf("%d ", (rand() % (ub - lb + 1)) + lb );
   }
   return 0;
}
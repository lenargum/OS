#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
   int i = INT_MAX;
   float f = FLT_MAX;
   double d = DBL_MAX;
   printf("Max integer: %d\n",i);
   printf("Max float: %f\n",f);
   printf("Max double: %f",d);
  
   return(0);
}

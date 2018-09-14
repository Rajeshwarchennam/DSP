#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
float x=5.0;
for(int i=0;i<=49;i++){
  x +=-((x*x*x)-x-1)/(3*x*x-1);
}
printf("%lf\n",x);
return 0;
}

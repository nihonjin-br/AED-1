#include <stdio.h>
 
int main() {
  double r, pi = 3.14159;

  scanf("%lf", &r);

  double area = pi * r * r;

  printf("A=%.4lf\n", area);

  return 0;
}

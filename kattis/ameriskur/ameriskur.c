#include <stdio.h>

#define CONVERT_CONSTANT 0.09144

int main()
{
  long a;
  double b;

  scanf("%ld", &a);
  b = (double)a * CONVERT_CONSTANT;

  printf("%.5lf\n", b);
}

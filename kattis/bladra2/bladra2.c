#include <stdio.h>

int main()
{
  int v, a, t;
  scanf("%d %d %d", &v, &a, &t);
  printf("%lf", 0.5 * (double)a * (double)t * (double)t + (double)v * (double)t);
}

#include <stdio.h>

int main()
{
  long x, y, r;

  scanf("%ld %ld", &x, &y);
  scanf("\n%ld", &r);

  printf("%ld %ld\n", x-r, y+r);
  printf("%ld %ld\n", x-r, y-r);
  printf("%ld %ld\n", x+r, y-r);
  printf("%ld %ld\n", x+r, y+r);
}

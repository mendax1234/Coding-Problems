#include <stdio.h>

int main()
{
  long n;
  scanf("%ld", &n);

  long sum = 0;
  for (long i = 0; i < n; i += 1)
  {
    long cur;
    scanf("%ld", &cur);
    sum += cur;
  }

  printf("%ld\n", sum);
}

#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int minus_zero = 0;
  for (int i = 0; i < n; i += 1)
  {
    int deg;
    scanf("%d", &deg);
    if (deg < 0)
    {
      minus_zero += 1;
    }
  }
  printf("%d\n", minus_zero);
}

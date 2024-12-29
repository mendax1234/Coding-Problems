#include <stdio.h>

int main()
{
  long n;
  scanf("%ld", &n);
  long layer = 0;
  long height = 0;
  long sum = 0;
  while (1)
  {
    if (layer == 0)
    {
      layer += 1;
    }
    else
    {
      layer += 2;
    }
    sum += layer * layer;
    if (sum <= n)
    {
      height += 1;
    }
    else
    {
      break;
    }
  }
  printf("%ld\n", height);
}


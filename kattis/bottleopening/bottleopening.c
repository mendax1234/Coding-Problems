#include <stdio.h>

int main()
{
  int n, k;
  scanf("%d \n %d", &n, &k);
  if (k >= n)
  {
    printf("impossible\n");
  }
  else
  {
    for (int i = 1; i <= k; i += 1)
    {
      printf("open %d using %d\n", i, i + 1);
    }
  }
}

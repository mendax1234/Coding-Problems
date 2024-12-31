#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int num_odd = 0;
  for (int i = 0; i < n; i += 1)
  {
    int prob;
    scanf("%d", &prob);
    if (prob % 2 == 1)
    {
      num_odd += 1;
    }
  }
  printf("%d\n", num_odd);
}


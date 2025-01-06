#include <stdio.h>

int calc_sum(int a1, int d1, int n)
{
  int sum = a1;
  for (int i = 1; i < n; i += 1)
  {
    sum += a1 + d1 * i;
  }
  return sum;
}

int main()
{
  int n;
  scanf("%d", &n);

  int a1, d1, a2, d2;
  scanf("%d %d\n%d %d", &a1, &d1, &a2, &d2);
  
  int sum1 = calc_sum(a1, d1, n);
  int sum2 = calc_sum(a2, d2, n);

  if (sum1 > sum2)
  {
    printf("Bob\n");
  }
  else if (sum1 < sum2)
  {
    printf("Alice\n");
  }
  else
  {
    printf("=\n");
  }
}

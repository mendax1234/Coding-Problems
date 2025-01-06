#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
 
  int cur_sum = 0;
  int i;
  for (i = 0; i < m; i += 1)
  {
    int cur;
    scanf("%d", &cur);
    cur_sum += cur;
    if (cur_sum > n)
    {
      break;
    }
  }
  printf("%d\n", m - i);
} 

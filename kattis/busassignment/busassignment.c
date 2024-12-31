#include <stdio.h>

int main()
{
  int n;
  scanf("%d\n", &n);
  long cur = 0;
  long max = 0;
  for (int i = 0; i < n; i += 1)
  {
    int get_off, get_on;
    scanf("%d %d\n", &get_off, &get_on);
    cur -= get_off;
    cur += get_on;
    if (cur >= max)
    {
      max = cur;
    }
  }
  printf("%ld\n", max);
}

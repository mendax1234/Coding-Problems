#include <stdio.h>

int main()
{
  int sum = 0;
  for (int i = 0; i < 5; i += 1)
  {
    int w = 0;
    int l = 0;
    scanf("%d %d", &w, &l);
    sum += w * l;
  }

  int avg = sum / 5;
  
  int n;
  int kwf;
  scanf("%d %d", &n, &kwf);

  printf("%d\n", avg * n / kwf);
}

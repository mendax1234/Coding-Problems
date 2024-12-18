#include <stdio.h>

int main()
{
  int percent;
  scanf("%d", &percent);
  double option1 = (double)(100 - percent) / (double)percent;
  double option2 = (double)percent / (double)(100 - percent);
  printf("%lf\n", (double)1 + option1);
  printf("%lf\n", (double)1 + option2);
}

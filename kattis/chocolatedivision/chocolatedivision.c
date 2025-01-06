#include <stdio.h>

int main()
{
  int r, c;
  scanf("%d %d", &r, &c);
  int total_cuts = r * c - 1;
  if (total_cuts % 2 == 0)
  {
    printf("Beata\n");
  }
  else
  {
    printf("Alf\n");
  }
}

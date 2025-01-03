#include <stdio.h>

int main()
{
  int recipe;
  scanf("%d", &recipe);
  if (recipe != 0 && recipe != 7)
  {
    recipe += 1;
  }
  printf("%d\n", recipe);
}

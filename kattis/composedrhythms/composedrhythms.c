#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int two = 0;
  int three = 0;
  if (n == 2)
  {
    two = 1;
    three = 0;
  }
  else if (n == 3)
  {
    two = 0;
    three = 1;
  }
  else if (n == 4)
  {
    two = 2;
    three = 0;
  }
  else
  {
    three = n / 3;
    if (n - three * 3 == 1)
    {
      three -= 1;
      two = 2;
    }
    else 
    {
      two = (n - three * 3) / 2;
    }
  }
  printf("%d\n", two + three);
  for (int i = 0; i < three; i += 1)
  {
    printf("3 ");
  }
  for (int i = 0; i < two; i += 1)
  {
    printf("2 ");
  }
  putchar('\n');
}

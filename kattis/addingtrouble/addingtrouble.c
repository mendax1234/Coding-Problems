#include <stdio.h>

int main()
{
  long a, b ,c;
  scanf("%ld %ld %ld", &a, &b, &c);
  if (c == a + b)
  {
    printf("correct!\n");
  }
  else
  {
    printf("wrong!\n");
  }
}

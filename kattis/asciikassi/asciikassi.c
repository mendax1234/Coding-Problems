#include <stdio.h>

#define CORNER '+'
#define TOP '-'
#define SIDE '|'
#define WHITE_SPACE ' '

void print_top_bottom(long n)
{
  putchar(CORNER);
  for (long i = 0; i < n; i += 1)
  {
    putchar(TOP);
  }
  putchar(CORNER);
  putchar('\n');
}

void print_mid(long n)
{
  for (long i = 0; i < n; i += 1)
  {
    putchar(SIDE);
    for (long j = 0; j < n; j += 1)
    {
      putchar(WHITE_SPACE);
    }
    putchar(SIDE);
    putchar('\n');
  }
}

int main()
{
  long n;
  scanf("%ld", &n);
  print_top_bottom(n);
  print_mid(n);
  print_top_bottom(n);
}

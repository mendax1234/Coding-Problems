#include <stdio.h>

#define CORNER 'x'
#define LEFT '/'
#define RIGHT '\\'

void print_space(int times)
{
  for (int i = 0; i < times; i += 1)
  {
    putchar(' ');
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  // Print Top line
  print_space(n + 1);
  putchar(CORNER);
  putchar('\n');

  // Print Upper half
  int j = 1;
  for (int i = n; i > 0; i -= 1, j += 2)
  {
    print_space(i);
    putchar(LEFT);
    print_space(j);
    putchar(RIGHT);
    putchar('\n');
  }

  // Print Middle
  putchar(CORNER);
  print_space(j);
  putchar(CORNER);
  putchar('\n');

  // Print Lower half
  j -= 2;
  for (int i = 1; i <= n; i += 1, j -= 2)
  {
    print_space(i);
    putchar(RIGHT);
    print_space(j);
    putchar(LEFT);
    putchar('\n');
  }

  // Print Bottom line
  print_space(n + 1);
  putchar(CORNER);
  putchar('\n');
}

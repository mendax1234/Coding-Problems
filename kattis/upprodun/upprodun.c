#include <stdio.h>

#define STAR '*'

void print_row(long n)
{
  for (long i = 0; i < n; i += 1)
  {
    putchar(STAR);
  }
  putchar('\n');
}

int main()
{
  long n, m;

  scanf("%ld", &n);
  scanf("\n%ld",&m);

  long num_room_more = m % n;
  long base_num_per_room = m / n;
  for (long i = 0; i < num_room_more; i += 1)
  {
    print_row(base_num_per_room + 1);
  }
  for (long i = 0; i < n - num_room_more; i += 1)
  {
    print_row(base_num_per_room);
  }
}

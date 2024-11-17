#include <stdio.h>

int main()
{
  long secs;
  scanf("%ld", &secs);
  // Get hours
  long hours = secs / 3600;
  secs -= 3600 * hours;
  // Get mins
  long mins = secs / 60;
  secs -= 60 * mins;
  printf("%ld : %ld : %ld\n", hours, mins, secs);
}

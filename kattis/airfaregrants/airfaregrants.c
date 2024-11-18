#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

long read_long()
{
  long a;
  char buf[1024]; // use 1KiB just to be sure
  int success; // flag for successful conversion

  do
  {
    if (!fgets(buf, 1024, stdin))
    {
        // reading input failed:
        return 1;
    }

    // have some input, convert it to integer:
    char *endptr;

    errno = 0; // reset error number
    a = strtol(buf, &endptr, 10);
    if (errno == ERANGE)
    {
        printf("Sorry, this number is too small or too large.\n");
        success = 0;
    }
    else if (endptr == buf)
    {
        // no character was read
        success = 0;
    }
    else if (*endptr && *endptr != '\n')
    {
        // *endptr is neither end of string nor newline,
        // so we didn't convert the *whole* input
        success = 0;
    }
    else
    {
        success = 1;
    }
  } while (!success); // repeat until we got a valid number
  
  return a;
}

long find_min(long *list, long n)
{
  long min = list[0];
  for (long i = 1; i < n; i += 1)
  {
    if (list[i] < min)
    {
      min = list[i];
    }
  }
  return min;
}

long find_max(long *list, long n)
{
  long max = list[0];
  for (long i = 0; i < n; i += 1)
  {
    if (list[i] > max)
    {
      max = list[i];
    }
  }
  return max;
}

int main()
{
  long n;
  scanf("%ld\n", &n);
  long *list = calloc((size_t)n, sizeof(long));
  if (list == NULL)
  {
    return 1;
  }
  for (long i = 0; i < n; i += 1)
  {
    list[i] = read_long();
  }
  long min = find_min(list, n);
  long max = find_max(list, n) / 2;
  if (min <= max)
  {
    printf("%ld\n", (long)0);
  }
  else
  {
    printf("%ld\n", min - max);
  }
}

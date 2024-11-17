#include <stdio.h>

#define TUNGSTEN_W 29260
#define DIFF 110

int main()
{
  long w;
  long s;
  long c;
  long init_w;
  long tar = 0;

  scanf("%ld %ld", &w, &s);
  c = s * (s + 1) / 2;
  init_w = TUNGSTEN_W * c;
  
  for (long i = 1; i <= s; i += 1)
  {
    long cur_w = init_w + DIFF * i;
    if (cur_w == w)
    {
      tar = i;
      break;
    }
  }

  printf("%ld\n", tar);
}

    

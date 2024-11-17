#include <stdio.h>

int main()
{
  long input;
  long output;

  scanf("%ld", &input);
  output = (input + 5) * 3 - 10;
  
  printf("%ld\n", output);
}

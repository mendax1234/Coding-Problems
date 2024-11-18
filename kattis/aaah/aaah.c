#include <stdio.h>
#include <string.h>

int main()
{
  char input1[1001];
  char input2[1001];
  
  scanf("%1000s", input1);
  scanf("%1000s", input2);

  if (strlen(input1) >= strlen(input2))
  {
    printf("go\n");
  }
  else
  {
    printf("no\n");
  }
}

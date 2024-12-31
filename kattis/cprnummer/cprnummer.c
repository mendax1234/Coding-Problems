#include <stdio.h>

#define LEN 12

int calc_sum(char *cpr)
{
  int sum = 0;
  sum += (cpr[0] - '0') * 4;
  sum += (cpr[1] - '0') * 3;
  sum += (cpr[2] - '0') * 2;
  sum += (cpr[3] - '0') * 7;
  sum += (cpr[4] - '0') * 6;
  sum += (cpr[5] - '0') * 5;
  sum += (cpr[7] - '0') * 4;
  sum += (cpr[8] - '0') * 3;
  sum += (cpr[9] - '0') * 2;
  sum += (cpr[10] - '0') * 1;

  return sum;
}


int main()
{
  char cpr[LEN] = { 0 };
  scanf("%s", cpr);
  int sum = calc_sum(cpr);
  if (sum % 11 == 0)
  {
    printf("1\n");
  }
  else
  {
    printf("0\n");
  }
}

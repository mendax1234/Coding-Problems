#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 32
static
int skip_space() {
  int c;
  do {
    c = fgetc(stdin);
  } while (isspace(c) && c != EOF);
  return c;
}
static
size_t fill_buffer(char *buf, size_t len) {
  int c;
  size_t i = 0;
  while (1) {
    c = fgetc(stdin);
    if (c == EOF || isspace(c)) {
      buf[i] = 0;
      return i + 1;
    }
    buf[i] = (char)c;
    i = i + 1;

    if (i == len) {
      return i;
    }
  }
}

/**
 * @brief Read and return a string from standard input (until
 * we reach a spa
 *
 * @return The string read if successful.  The caller is
 * responsible for freeing the memory allocated to the string.
 * Return NULL if an error is encountered when reading.
 *
 * @note Based on FIO20-C. Avoid unintentional truncation when
 * using fgets() or fgetws()
 * https://wiki.sei.cmu.edu/
 */
char* cs1010_read_word()
{
  char buf[BUF_SIZE];
  char *ret = malloc(1);
  if (ret == NULL) {
    return NULL;
  }
  size_t total_len = 1;
  size_t len;

  int c = skip_space();
  if (c == EOF) {
    free(ret);
    printf("EOF encountered.  return NULL\n");
    return NULL;
  }
  *ret = (char)c;

  do {
    len = fill_buffer(buf, BUF_SIZE);
    char *temp = realloc(ret, total_len + len + 1);
    if (temp == NULL) {
      free(ret);
      return NULL;
    }
    ret = temp;
    memcpy(ret + total_len, buf, len); // concat the string
    total_len += len;
  } while (len == BUF_SIZE && buf[len-1] != 0);
  return ret;
}

/**
 * @brief Read and return a long int from standard input.
 *
 * @details Based on INT05-C from SEI CERT C Coding Standard
 * https://wiki.sei.cmu.edu/
 *
 * @return the value read if successful.  Return LONG_MAX
 * with an error message printed if an error occured.
 */

long cs1010_read_long()
{
  char *buff;
  char *end_ptr;
  long number;

  buff = cs1010_read_word();
  if (buff == NULL) {
    fprintf(stderr, "cs1010_read_long: EOF or read error\n");
    return LONG_MAX;
  }
  errno = 0;

  number = strtol(buff, &end_ptr, 10);

  if (ERANGE == errno) {
    fprintf(stderr, "cs1010_read_long: number '%s' out of range\n", buff);
    free(buff);
    return LONG_MAX;
  }
  if (end_ptr == buff) {
    fprintf(stderr, "cs1010_read_long: '%s' is not a valid numeric input\n", buff);
    free(buff);
    return LONG_MAX;
  }
  if ('\n' != *end_ptr && '\0' != *end_ptr) {
    fprintf(stderr, "cs1010_read_long: reach the end without null/newline. '%s' remains\n", end_ptr);
    free(buff);
    return LONG_MAX;
  }
  free(buff);
  return number;
}

/**
 * @brief Print a long to standard output with format %.4f.
 */
void cs1010_print_long(long d)
{
  printf("%ld", d);
}

/**
 * @brief Print a long to standard output with format %.4f, followed by a newline.
 */
void cs1010_println_long(long d)
{
  cs1010_print_long(d);
  printf("\n");
}

/**
 * @brief Print a string to standard output.
 */
void cs1010_print_string(char *s)
{
  printf("%s", s);
}

/**
 * @brief Print a string to standard output, followed by a newline.
 */
void cs1010_println_string(char *s)
{
  printf("%s\n", s);
}

#define LEN 26
#define RIGHT "right"
#define WRONG "wrong"

int main()
{
  long penalty[LEN] = { 0 };
  long time_sum = 0;
  long solved = 0;
  while (true)
  {
    long time = cs1010_read_long();
    if (time == -1)
    {
      break;
    }
    char question = getchar();
    char *status = cs1010_read_word();
    if (strcmp(status, RIGHT) == 0)
    {
      solved += 1;
      time_sum += time + penalty[question - 'A'];
    }
    else if (strcmp(status, WRONG) == 0)
    {
      penalty[question - 'A'] += 20;
    }
  }
  cs1010_print_long(solved);
  cs1010_print_string(" ");
  cs1010_println_long(time_sum);
}

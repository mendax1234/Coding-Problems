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
 * @brief Read and return a string from standard input (until
 * we reach the new line.)
 *
 * @return the string read if successful.  The caller is
 * responsible for freeing the memory allocated to the string.
 * Return NULL if an error is encountered when reading.
 *
 * @note See FIO20-C. Avoid unintentional truncation when using fgets() or fgetws()
 * https://wiki.sei.cmu.edu/
 */
char* cs1010_read_line()
{
  char* buf = NULL;
  size_t dummy = 0;
  if (getline(&buf, &dummy, stdin) == -1) {
    fprintf(stderr, "cs1010_read_line: unable to read line into buffer\n");
    return NULL;
  }
  return buf;
}

/**
 * @brief Read and return a double from standard input.
 *
 * @return the value read if successful.  Return DOUBLE_MAX
 * with an error message printed if an error occured.
 */
double cs1010_read_double()
{
  char *buff;
  char *end_ptr;
  double number;

  buff = cs1010_read_word();
  if (buff == NULL) {
    fprintf(stderr, "cs1010_read_double: EOF or read error\n");
    return DBL_MAX;
  }
  errno = 0;

  number = strtod(buff, &end_ptr);

  if (ERANGE == errno) {
    free(buff);
    fprintf(stderr, "cs1010_read_double: number '%s' out of range\n", buff);
    return DBL_MAX;
  }
  if (end_ptr == buff) {
    free(buff);
    fprintf(stderr, "cs1010_read_double: '%s' is not a valid numeric input\n", buff);
    return DBL_MAX;
  }
  if ('\n' != *end_ptr && '\0' != *end_ptr) {
    free(buff);
    fprintf(stderr, "cs1010_read_double: reach the end without null/newline. '%s' remains\n", buff);
    return DBL_MAX;
  }
  free(buff);
  return number;
}

/**
 * @brief Read and return multiple long int from standard
 * input into an array.
 *
 * @return The array read if successful.  The caller is responsible
 * for freeing the array.  Return NULL if an error occured.
 */

long* cs1010_read_long_array(size_t how_many)
{
  long *buffer = calloc(how_many, sizeof(long));
  if (buffer == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < how_many; i = i + 1) {
    buffer[i] = cs1010_read_long();
  }

  return buffer;
}

/**
 * @brief Read and return multiple double from standard
 * input into an array.
 *
 * @return The array read if successful.  The caller is responsible
 * for freeing the array.  Return NULL if an error occured.
 */
double* cs1010_read_double_array(size_t how_many)
{
  double *buffer = calloc(how_many, sizeof(double));
  if (buffer == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < how_many; i = i + 1) {
    buffer[i] = cs1010_read_double();
  }

  return buffer;
}

/**
 * @brief Read and return multiple lines from standard
 * input into an array.
 *
 * @return The array read if successful.  The caller is responsible
 * for freeing the array and each string in the array.  Return NULL
 * if an error occured.
 */
char** cs1010_read_line_array(size_t how_many)
{
  char **buffer = calloc(how_many, sizeof(char*));
  if (buffer == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < how_many; i = i + 1) {
    buffer[i] = cs1010_read_line();
    if (buffer[i] == NULL) {
      for (size_t j = 0; j < i; j = j + 1) {
        free(buffer[j]);
      }
      free(buffer);
      return NULL;
    }
  }

  return buffer;
}

/**
 * @brief Read and return multiple space-delimited words
 * from standard input into an array.
 *
 * @return The array read if successful.  The caller is
 * responsible for freeing the array and each string in
 * the array.  Return NULL if an error occured.
 */
char** cs1010_read_word_array(size_t how_many)
{
  char **buffer = calloc(how_many, sizeof(char*));
  if (buffer == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < how_many; i = i + 1) {
    buffer[i] = cs1010_read_word();
    if (buffer[i] == NULL) {
      for (size_t j = 0; j < i; j = j + 1) {
        free(buffer[j]);
      }
      free(buffer);
      return NULL;
    }
  }

  return buffer;
}

/**
 * @brief Read a size_t value from the standard input.  
 * Reporting an error and return 0 instead of the value 
 * is less than 0..
 */
size_t cs1010_read_size_t() {
  char *buff;
  char *end_ptr;
  unsigned long number;

  buff = cs1010_read_word();
  if (buff == NULL) {
    fprintf(stderr, "cs1010_read_size_t: EOF or read error\n");
    return SIZE_MAX;
  }
  errno = 0;

  number = strtoul(buff, &end_ptr, 10);

  if (ERANGE == errno) {
    fprintf(stderr, "cs1010_read_size_t: number '%s' out of range of unsigned long\n", buff);
    free(buff);
    return SIZE_MAX;
  }
  if (end_ptr == buff) {
    fprintf(stderr, "cs1010_read_size_t: '%s' is not a valid numeric input\n", buff);
    free(buff);
    return SIZE_MAX;
  }
  if ('\n' != *end_ptr && '\0' != *end_ptr) {
    fprintf(stderr, "cs1010_read_size_t: reach the end without null/newline. '%s' remains\n", end_ptr);
    free(buff);
    return SIZE_MAX;
  }
  if (number > SIZE_MAX) {
    fprintf(stderr, "cs1010_read_size_t: number '%s' out of range of size_t\n", buff);
    free(buff);
    return SIZE_MAX;
  }
  free(buff);
  return number;
}
  
/**
 * @brief Print a double to standard output with format %.4f.
 */
void cs1010_print_double(double d)
{
  printf("%.4f", d);
}

/**
 * @brief Print a long to standard output with format %.4f.
 */
void cs1010_print_long(long d)
{
  printf("%ld", d);
}

/**
 * @brief Print a double to standard output with format %.4f,
 * followed by a newline.
 */
void cs1010_println_double(double d)
{
  cs1010_print_double(d);
  printf("\n");
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

/**
 * @brief Print a pointer to standard output.
 */
void cs1010_print_pointer(void *ptr)
{
  cs1010_print_long((long)ptr);
}

/**
 * @brief Print a pointer to standard output, followed by a newline.
 */
void cs1010_println_pointer(void *ptr)
{
  cs1010_println_long((long)ptr);
}

/**
 * @brief Print a size_t to standard output with format %zu.
 */
void cs1010_print_size_t(size_t d)
{
  printf("%zu", d);
}

/**
 * @brief Print a size_t to standard output with format %zu.
 */
void cs1010_println_size_t(size_t d)
{
  printf("%zu\n", d);
}

/**
 * @brief Print a bool to standard output with format %zu.
 */
void cs1010_print_bool(bool b)
{
  if (b) {
    printf("true");
  } else {
    printf("false");
  }
}

/**
 * @brief Print a bool to standard output with format %zu.
 */
void cs1010_println_bool(bool b)
{
  if (b) {
    printf("true\n");
  } else {
    printf("false\n");
  }
}

/**
 * @brief Clear the screen.
 */
void cs1010_clear_screen()
{
  printf("[2J[;H");
}

typedef struct athelete {
  char *name;
  double first;
  double second;
} athelete;

typedef struct team {
  double total;
  char *runner1;
  char *runner2;
  char *runner3;
  char *runner4;
} team;

void swap(athelete *runners, size_t s1, size_t s2)
{
  athelete temp = runners[s1];
  runners[s1] = runners[s2];
  runners[s2] = temp;
}

void bubble_pass(size_t last, athelete *runners)
{
  for (size_t i = 0; i < last; i += 1)
  {
    if (runners[i].second > runners[i+1].second)
    {
      swap(runners, i, i+1);
    }
  }
}

void bubble_sort_second_based(size_t n, athelete *runners)
{
  for (size_t last = n - 1; last > 0; last -= 1)
  {
    bubble_pass(last, runners);
  }
}

void finalize_team(team *final_team, size_t cur_index, athelete *runners, size_t n)
{
  long count = 1;
  for (size_t i = 0; i < n && count < 4; i += 1)
  {
    if (i != cur_index && count == 1)
    {
      final_team->runner2 = runners[i].name;
      final_team->total += runners[i].second;
      count += 1;
    }
    else if (i != cur_index && count == 2)
    {
      final_team->runner3 = runners[i].name;
      final_team->total += runners[i].second;
      count += 1;
    }
    else if (i != cur_index && count == 3)
    {
      final_team->runner4 = runners[i].name;
      final_team->total += runners[i].second;
      count += 1;
    }
  }
}

void print_final_team(team final_team)
{
  printf("%.9lf\n", final_team.total);
  cs1010_println_string(final_team.runner1);
  cs1010_println_string(final_team.runner2);
  cs1010_println_string(final_team.runner3);
  cs1010_println_string(final_team.runner4);
}  

int main()
{
  size_t n = cs1010_read_size_t();
  athelete *runners = calloc(n, sizeof(athelete));
  
  // input the struct array
  for (size_t i = 0; i < n; i += 1)
  {
    runners[i].name = cs1010_read_word();
    runners[i].first = cs1010_read_double();
    runners[i].second = cs1010_read_double();
  }

  // sort based on second time
  bubble_sort_second_based(n, runners);
 
  // find the best team
  team cur_team;
  team final_team;
  cur_team.total = 0;
  double min_time = DBL_MAX;
  for (size_t i = 0; i < n; i += 1)
  {
    cur_team.total = 0;
    // Add first runner
    cur_team.total += runners[i].first;
    cur_team.runner1 = runners[i].name;
    // Add the rest
    finalize_team(&cur_team, i, runners, n);
    if (cur_team.total < min_time)
    {
      min_time = cur_team.total;
      final_team = cur_team;
    }
  }
  
  print_final_team(final_team);
  
  for (size_t i = 0; i < n; i += 1)
  {
    free(runners[i].name);
  }
  free(runners);
}

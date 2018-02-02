/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include <stdio.h>
 #include <math.h>
 #include "deletable_primes.h"

unsigned long remove_digit(int index, unsigned long n)
{
  long ret = n;
  int d = pow(10, index+1);
  int m = pow(10, index);
  ret = n / d;
  ret *= m;
  ret += n % m;
  return ret;
}

bool is_prime(long number)
{
  if (number == 2) {
    return true;
  }
  if (number % 2 == 0) {
    return false;
  }
  for (long i = 3; i <= (number/2); i++) {
    if (number % i == 0) {
      return false;
    }
    i++;
  }
  return true;
}

int get_ways(unsigned long p)
{
  int ways = 0;
  if (!is_prime(p))
  {
    return 0;
  }
  if (p < 10)
  {
    if (is_prime(p))
    {
      return 1;
    }
    return 0;
  }
  int count = 0;
  int length = get_length(p);
  while (count < length)
  {
    long n = remove_digit(count, p);
    if (is_prime(n))
    {
      int aa = get_ways(n);
      ways += aa;
    }
    count++;
  }
  return ways;
}

int get_length(long num)
{
  int i = 0;
  int j = 0;
  do {
    i++;
    j = num / pow(10, i);
  } while(j != 0);
  return i;
}

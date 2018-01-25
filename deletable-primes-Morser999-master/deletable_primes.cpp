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
 #include "deletable_primes.h"
 #include <math.h>
 unsigned long remove_digit(int index, unsigned long n)
 {
   long m = n;
   n = n / pow(10,index + 1);
   int modulu = pow(10,index);
   int valueToAdd = m % modulu;
   n = (n * pow(10,index)) + valueToAdd;
   return n;

 }
 int get_ways(unsigned long p)
 {
   int way_counter = 0;
   int index = 0;
   unsigned long q = 0;
   bool prime = false;
   while(!prime)
   {
     q = remove_digit(index,p);
     prime = is_prime(q);
     index++;
   }

   return way_counter;
 }
bool is_prime(unsigned long p)
{
  bool is_prime = true;
  int primes[4] = {2,3,5,7};
  for (int i = 0; i < 4; i++) {
    if(p % primes[i] == 0 && p != 2 || p != 3 || p != 5 || p != 7)
    {
      is_prime = false;
    }
  }
  return is_prime;
}

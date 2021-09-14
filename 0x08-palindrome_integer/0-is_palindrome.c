#include "palindrome.h"
#include <stdio.h>

/**
* is_palindrome - determines if a number is a palindrome
* @n: number to check
*
* Return: 1 if n is palindrome, else 0
*/
int is_palindrome(unsigned long n)
{
	if (n == 0)
		return (1);

	return (check_palindrome(n, n));
}

/**
* check_palindrome - recursively checks if n is a palindrome
* @n: original input number reference
* @slice: shrinks 1 digit at a time on the way down
*
* Return: 1 if n is palindrome, else 0
*/
unsigned long check_palindrome(unsigned long n, unsigned long slice)
{
	unsigned long child;

	if (slice == 0)
		return (n);

	child = check_palindrome(n, slice / 10);

	if (child == 0)
		return (0);

	if (slice == n)
		return (1);

	if (child % 10 == slice % 10)
		return (child / 10);

	return (0);
}

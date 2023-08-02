#include "main.h"

/**
 * is_prime_number_helper - Helper function to check if a number is prime
 * @n: The number to check
 * @i: The divisor to check from 2 to sqrt(n)
 *
 * Return: 1 if the number is prime, otherwise return 0
 */
int is_prime_number_helper(int n, int i)
{
	if (n < 2 || n % i == 0)
		return (0);

	if (i * i > n)
		return (1);

	return (is_prime_number_helper(n, i + 1));
}

/**
 * is_prime_number - Returns 1 if the input integer is a prime number,
 *                   otherwise return 0
 * @n: The number to check
 *
 * Return: 1 if the number is prime, otherwise return 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_prime_number_helper(n, 2));
}

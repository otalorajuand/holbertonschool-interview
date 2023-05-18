#include <stdlib.h>
#include <stdio.h>


#include "palindrome.h"

int reverse_number(unsigned long n)
{
    int reversed_number = 0, remainder;

    while(n != 0) {
        remainder = n % 10;
        reversed_number = reversed_number * 10 + remainder;
        n /= 10;
    }

    return(reversed_number);
}

int power(int first, int second)
{
    int i, res = 1;
    for (i = 0; i<second; i++)
    {
        res *= first;
    }

    return(res);
}

int is_palindrome(unsigned long n)
{
    int count = 0, den;
    unsigned long aux = n, first, last;

    while (aux != 0)
    {
        count++;
        aux = aux / 10;
    }

    den = power(10, count/2);

    first = count%2 == 0 ? n/den : n/(den * 10);

    first = reverse_number(first);
    last = n%den;

    if (first == last)
        return (1);

    return(0);
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int GetPrime ( int **primeSet, int upperLimit );
bool isPrime = 0;

int main ( void )
{
    long upper;
    cin >> upper;
	 getPrime(upper);   
    return 0;

}// End Function

void getPrime(long upperLimit )
{
    // A list use to determine whether the subscript is a prime number
    // And it holds odd numbers only, for example, isPrime[1] means whether 3 is a prime number,
    // isPrime[2] means whether 5 is a prime number
    for ( int i = 0; i <= (upperLimit >> 1); i++ )		// Does not count 0, 1, 2
    {
        isPrime[i] = true;

    }// End For

    // Then we filter out all numbers that is not a prime number
    // When doing this, never takes even numbers into account
    // And there is no need analyze the numbers which are greater than sqrt ( upperLimit )
    // Because those are repeating work
    int end = (int)sqrtf ( upperLimit );
    for ( int i = 3; i <= end; i += 2 )
    {
        if ( isPrime[i >> 1] )
        {
            // When a number is a combination of two or more prime number must
            // Be a composite number
            for ( int composite = 3; i*composite <= upperLimit; composite += 2 )
            {
                isPrime[(i*composite) >> 1] = false;

            }// End For ( Each predictable composite )

        }// End If ( Can be used for fitlering )

    }// End For

	\
    // Store back the result in term of a set
    int i, j;
    for ( i = 1, j = 1; j < (upperLimit >> 1); j++ )
    {
        if ( isPrime[j] )
        {
            _primeSet[i] = (j << 1) + 1;
            i++;

        }// End If ( if it is a prime number )

    }// End For

    // Can not forget that 1 + 1 question ^_^
    _primeSet[0] = 2;

    return i;

}// End Function

#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
long long int GreatestCommonDivisor(long long int a, long long int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if (a < b)
        return GreatestCommonDivisor(a, b % a);
    else
        return GreatestCommonDivisor(b, a % b);
}
int* decimalToFraction(long double number)
{
    // Fetch integral value of the decimal
    double initialValue = floor(number);
 
    // Fetch fractional part of the decimal
    double finalValue = number - initialValue;
 
    // Consider precision value to
    // convert fractional part to
    // integral equivalent
    const long precisionValue = 1000000000;
 
    // Calculate GCD of integral
    // equivalent of fractional
    // part and precision value
    long long gcdValue
        = GreatestCommonDivisor(round(finalValue * precisionValue), precisionValue);
 
    // Calculate num and deno
    long long numerator
        = round(finalValue * precisionValue) / gcdValue;
    long long denominator = precisionValue / gcdValue;
 
    // Print the fraction
    int *returningArray = new int[2];
    returningArray[0] = numerator;
    returningArray[1] = denominator;
    return returningArray;
}
long double nthRoot(long double A, int N)
{
    // initially guessing a random number between
    // 0 and 9
    long double xPre = rand() % 10;
 
    //  smaller eps, denotes more accuracy
    long double eps = (long double)1e-19;
 
    // initializing difference between two
    // roots by INT_MAX
    long double delX = INT_MAX;
 
    //  xK denotes current value of x
    long double xK;
 
    //  loop until we reach desired accuracy
    while (delX > eps)
    {
        //  calculating current value from previous
        // value by newton's method
        xK = ((N - 1.0) * xPre +
              (long double)A/pow(xPre, N-1)) / (long double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }
    return xK;
}
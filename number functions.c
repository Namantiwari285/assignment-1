#include "naman.h"
#include <stdio.h>
#include <math.h>

int reverseDigits(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int d = n % 10;
        rev = rev * 10 + d;
        n /= 10;
    }
    return rev;
}

int isArmstrong(int num)
{
    int temp = num, sum = 0, count = 0;
    while (temp > 0)
    {
        count++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0)
    {
        int d = temp % 10;
        sum += pow(d, count);
        temp /= 10;
    }
    return (sum == num);
}

int isAdams(int num)
{
    int sq = num * num;
    int revSq = reverseDigits(sq);
    int revNum = reverseDigits(num);
    return (revSq == revNum * revNum);
}

int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int isPrimePalindrome(int n)
{
    return (isPrime(n) && n == reverseDigits(n));
}

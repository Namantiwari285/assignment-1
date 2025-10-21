#include <stdio.h>
#include <math.h>

void printList(int *list, int len) {
    printf("[");
    
    
    for (int k = 0; k < len; ++k) {
        printf("%d", list[k]);
        if (k < len - 1) printf(", ");
    }
    printf("]\n");
}

int maxPosition(int *list, int len) {
    int pos = 0;
    for (int i = 1; i < len; ++i)
        if (list[i] > list[pos]) pos = i;
    return pos;
}

int minPosition(int *list, int len) {
    int pos = 0;
    for (int i = 1; i < len; ++i)
        if (list[i] < list[pos]) pos = i;
    return pos;
}

float calcMean(int *list, int len) {
    int total = 0;
    for (int j = 0; j < len; ++j) total += list[j];
    return (float)total / len;
}

void flipArray(int *list, int len) {
    for (int a = 0; a < len / 2; ++a) {
        int tmp = list[a];
        list[a] = list[len - 1 - a];
        list[len - 1 - a] = tmp;
    }
}

int locateValue(int *list, int len, int key) {
    for (int i = 0; i < len; ++i)
        if (list[i] == key) return i;
    return -1;
}



int isArmstrong(int n) {
    int original = n, sum = 0, digits = 0, temp = n;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp > 0) {
        int d = temp % 10;
        sum += (int)pow(d, digits);
        temp /= 10;
    }
    return sum == original;
}

int reverseNum(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int isAdams(int x) {
    int sq = x * x;
    int revX = reverseNum(x);
    int revSq = revX * revX;
    return reverseNum(sq) == revSq;
}

int isPrime(int val) {
    if (val < 2) return 0;
    for (int i = 2; i * i <= val; ++i)
        if (val % i == 0) return 0;
    return 1;
}

int isPalindrome(int val) {
    return val == reverseNum(val);
}

int isPrimePalin(int x) {
    return isPrime(x) && isPalindrome(x);
}



int main() {
    int testNum = 12;
    int values[] = {3, 1, 4, 1, 5};
    int count = sizeof(values)/sizeof(values[0]);

    printf("Number Checks:\n");
    printf("%d is Armstrong? %s\n", testNum, isArmstrong(testNum) ? "Yes" : "No");
    printf("%d is Adams? %s\n", testNum, isAdams(testNum) ? "Yes" : "No");
    printf("%d is Prime Palindrome? %s\n", testNum, isPrimePalin(testNum) ? "Yes" : "No");

    printf("\nArray Operations:\n");
    printList(values, count);
    printf("Max at: %d\n", maxPosition(values, count));
    printf("Min at: %d\n", minPosition(values, count));
    printf("Mean: %.2f\n", calcMean(values, count));
    
    flipArray(values, count);
    printList(values, count);
    
    printf("Position of 4: %d\n", locateValue(values, count, 4));

    return 0;
}

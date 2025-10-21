
//    Name : Naman Tiwari
  //  Class Roll No : 39
   // University Roll No : 12515001000
   // Subject : C Programming
   // Subject Code : BCSG 0802

  //  Assignment – Functions and Header Files in C


#include <stdio.h>
#include <math.h>

// Function to reverse the digits of a number
int reverseNumber(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return rev;
}

// Function to check if number is Armstrong
int isArmstrong(int n) {
    int temp = n, count = 0, sum = 0;

    while (temp > 0) {
        count++;
        temp /= 10;
    }

    temp = n;
    while (temp > 0) {
        int d = temp % 10;
        sum += pow(d, count);
        temp /= 10;
    }

    return (sum == n);
}

// Function to check Adam number
int isAdam(int n) {
    int sq = n * n;
    int rev = reverseNumber(n);
    int revSq = reverseNumber(sq);
    return (revSq == rev * rev);
}

// Function to check prime
int isPrime(int n) {
    if (n <= 1) 
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to check prime palindrome
int isPrimePalindrome(int n) {
    return (isPrime(n) && n == reverseNumber(n));
}

// Main function
int main() {
    int choice, number;

    do {
        printf("\n========= MENU =========\n");
        printf("1. Check Armstrong Number\n");
        printf("2. Check Adam Number\n");
        printf("3. Check Prime Palindrome Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting Program... Thank you!\n");
            break;
        }

        printf("Enter a number: ");
        scanf("%d", &number);

        switch (choice) {
            case 1:
                if (isArmstrong(number))
                    printf("%d is an Armstrong number.\n", number);
                else
                    printf("%d is not an Armstrong number.\n", number);
                break;

            case 2:
                if (isAdam(number))
                    printf("%d is an Adam number.\n", number);
                else
                    printf("%d is not an Adam number.\n", number);
                break;

            case 3:
                if (isPrimePalindrome(number))
                    printf("%d is a Prime Palindrome number.\n", number);
                else
                    printf("%d is not a Prime Palindrome number.\n", number);
                break;

            default:
                printf("Invalid Input! Please choose between 1–4.\n");
        }

    } while (choice != 4);

    return 0;
}

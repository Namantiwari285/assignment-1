#include <stdio.h>
#include <math.h>

int reverseDigits(int n){
    int rev=0;
    while(n>0){
        rev = rev*10 + n%10;
        n/=10;
    }
    return rev;
}


int isArmstrong(int num){
    int sum=0, temp=num, digits=0;
    temp=num;
    while(temp>0){ temp/=10; digits++; }

    temp=num;
    while(temp>0){
        int d=temp%10;
        sum += pow(d,digits);
        temp/=10;
    }
    return sum==num;
}


int isAdams(int num){
    int rev=reverseDigits(num);
    int sum = num + rev;
    return isArmstrong(sum);
}


int isPrime(int num){
    if(num<2) return 0;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return 0;
    }
    return 1;
}

int isPrimePalindrome(int num){
    if(!isPrime(num)) return 0;
    return num == reverseDigits(num);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);

    printf("\nReversed Number: %d\n", reverseDigits(n));
    printf("Is Armstrong? %s\n", isArmstrong(n)?"Yes":"No");
    printf("Is Adams? %s\n", isAdams(n)?"Yes":"No");
    printf("Is Prime? %s\n", isPrime(n)?"Yes":"No");
    printf("Is Prime Palindrome? %s\n", isPrimePalindrome(n)?"Yes":"No");

    return 0;
}

#include "naman.h"
#include <stdio.h>
#include <math.h>

void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size-1) printf(", ");
    }
    printf("]\n");
}

int findMaxIndex(int arr[], int size) {
    int idx = 0;
    for (int i=1; i<size; i++)
        if (arr[i] > arr[idx]) idx = i;
    return idx;
}

int findMinIndex(int arr[], int size) {
    int idx = 0;
    for (int i=1; i<size; i++)
        if (arr[i] < arr[idx]) idx = i;
    return idx;
}

void reverseArray(int arr[], int size) {
    for (int i=0; i<size/2; i++) {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}


float findAverage(int arr[], int size) {
    int sum = 0;
    for (int i=0; i<size; i++) sum += arr[i];
    return (float)sum/size;
}

int linearSearch(int arr[], int size, int value) {
    for (int i=0; i<size; i++)
        if (arr[i] == value) return i;
    return -1;
}
#include <stdio.h>
#include "naman.h"

int main() {
    int num = 12;

    // Number functions
    printf("Number functions:\n");
    printf("%d is Armstrong? %s\n", num, isArmstrong(num) ? "Yes" : "No");
    printf("%d is Adams? %s\n", num, isAdams(num) ? "Yes" : "No");
    printf("%d is Prime Palindrome? %s\n", num, isPrimePalindrome(num) ? "Yes" : "No");

    // Array functions
    int arr[] = {3,1,4,1,5};
    int n = 5;

    printf("\nArray functions:\n");
    displayArray(arr, n);
    printf("Max at index: %d\n", findMaxIndex(arr,n));
    printf("Min at index: %d\n", findMinIndex(arr,n));
    printf("Average: %.2f\n", findAverage(arr,n));
    reverseArray(arr,n);
    displayArray(arr,n);
    printf("Search 4: index %d\n", linearSearch(arr,n,4));

    return 0;
} 
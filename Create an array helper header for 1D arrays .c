
#ifndef ARRAYLIB_H
#define ARRAYLIB_H
int findMaxIndex(int arr[], int size); 
int findMinIndex(int arr[], int size); 
float findAverage(int arr[], int size); 
void displayArray(int arr[], int size); 
void reverseArray(int arr[], int size); 
void sortArray(int arr[], int size); 
int linearSearch(int arr[], int size, int value);

#endif /* ARRAYLIB_H */
 
#include <stdio.h>
#include "arraylib.h"

int findMaxIndex(int arr[], int size) {
    int idx = 0;
    for(int i=1; i<size; i++)
        if(arr[i] > arr[idx]) idx = i;
    return idx;
}

int findMinIndex(int arr[], int size) {
    int idx = 0;
    for(int i=1; i<size; i++)
        if(arr[i] < arr[idx]) idx = i;
    return idx;
}

float findAverage(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) sum += arr[i];
    return (float)sum / size;
}


void displayArray(int arr[], int size) {
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverseArray(int arr[], int size) {
    for(int i=0; i<size/2; i++) {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

void sortArray(int arr[], int size) {
    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

int linearSearch(int arr[], int size, int value) {
    for(int i=0; i<size; i++)
        if(arr[i] == value) return i;
    return -1;
}



COMPILE AND RUN—
gcc main.c arraylib.c -o prog
./prog
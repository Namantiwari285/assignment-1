#include <stdio.h>



int maxIndex(int arr[], int n) {
    int m = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[m]) m=i;
    }
    return m;
}


int minIndex(int arr[], int n) {
    int m = 0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[m]) m=i;
    }
    return m;
}


float avg(int arr[], int n) {
    int s=0;
    for(int i=0;i<n;i++) s+=arr[i];
    return (float)s/n;
}


void printArr(int arr[], int n) {
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
}


void revArr(int arr[], int n){
    for(int i=0;i<n/2;i++){
        int t=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=t;
    }
}


void sortArr(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}


int findVal(int arr[], int n, int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val) return i;
    }
    return -1; 
}


int main(){
    int arr[]={12,5,7,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArr(arr,n);

    printf("Index of max: %d\n", maxIndex(arr,n));
    printf("Index of min: %d\n", minIndex(arr,n));
    printf("Average: %.2f\n", avg(arr,n));

    printf("\nSorting...\n");
    sortArr(arr,n);
    printf("Sorted: ");
    printArr(arr,n);

    printf("\nReversing...\n");
    revArr(arr,n);
    printf("Reversed: ");
    printArr(arr,n);

    int v=7;
    int p=findVal(arr,n,v);
    if(p!=-1) printf("Value %d found at index %d\n",v,p);

    else printf("Value %d not found\n",v);

    return 0;
}

#include <stdio.h>
void insertionSort(int arr[], int n) 
{
int i, key, j;
for (i = 1; i < n; i++) 
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key) 
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;  
}
}
void printArray(int arr[], int size) 
{
int i;
for (i = 0; i < size; i++) 
{
printf("%d ", arr[i]);
}
printf("\n");
}
int main() 
{
int arr[] = {2, 13, 5, 18, 14};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: \n");
printArray(arr, n);
insertionSort(arr, n);
printf("Sorted array: \n");
printArray(arr, n);
return 0;
}
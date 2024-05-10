//SELECTION SORT

#include <stdio.h> 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 

        // Swap the found minimum element with the first element 
        if (min_idx != i) 
            swap(&arr[min_idx], &arr[i]); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
    FILE *fp;
    int arr[100000]; // Assuming the maximum number of elements in the file is 10000
    int n = 0; // Number of elements read from the file

    // Open the file
    fp = fopen("shuffled_list.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read numbers from the file into the array
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < 10000) {
        n++;
    }

    // Close the file
    fclose(fp);

    // Perform selection sort on the array
    selectionSort(arr, n); 

    // Print the sorted array 
    printf("Sorted array: \n"); 
    printArray(arr, n); 

    return 0; 
}

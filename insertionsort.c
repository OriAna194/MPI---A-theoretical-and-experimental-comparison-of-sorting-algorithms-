#include <stdio.h>

void insertionSort(int array[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i]; // take value
        j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key; // insert in right place
    }
}

int main() {
    FILE *fp;
    int n = 0; // number of elements read from the file

    // Open the file
    fp = fopen("shuffled_list.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read numbers from the file into the array
    int arr[100000]; // assuming a maximum of 10000 elements
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < 100000) {
        n++;
    }

    // Close the file
    fclose(fp);

    printf("Array before Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Sort the array using Insertion Sort
    insertionSort(arr, n);

    printf("Array after Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

#include <stdio.h>

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int swaps = 0; // flag to detect any swap is there or not
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) { // when the current item is bigger than next
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps = 1; // set swap flag
            }
        }
        if (!swaps)
            break; // No swap in this pass, so array is sorted
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

   /* printf("Array before Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
*/
    // Sort the array using Bubble Sort
    bubbleSort(arr, n);

    printf("Array after Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

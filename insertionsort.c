#include <stdio.h>

void insertionSort(int array[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i]; 
        j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key; 
    }
}

int main() {
    FILE *fp;
    int n = 0; 


    fp = fopen("shuffled_list.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }


    int arr[500000]; 
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < 500000) {
        n++;
    }


    fclose(fp);

    printf("Array before Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    insertionSort(arr, n);

    printf("Array after Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

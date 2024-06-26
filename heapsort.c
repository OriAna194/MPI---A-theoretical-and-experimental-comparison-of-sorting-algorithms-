#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    FILE *file = fopen("shuffled_list.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n = 0;
    int capacity = 10000; //modify the value with the size of the list that needs to be sorted
    int *arr = (int *)malloc(capacity * sizeof(int));

    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        if (n >= capacity) {
            capacity *= 2; 
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                perror("Memory reallocation failed");
                fclose(file);
                return 1;
            }
        }
        arr[n++] = num;
    }

    fclose(file);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);

    return 0;
}

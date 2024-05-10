#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_MERGE 32

int min(int x, int y) {
    return (x < y) ? x : y;
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int* left = (int*)malloc(len1 * sizeof(int));
    int* right = (int*)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < len2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];

    free(left);
    free(right);
}

void timSort(int arr[], int n) {
    for (int i = 0; i < n; i += MIN_MERGE)
        insertionSort(arr, i, min((i + 31), (n - 1)));

    for (int size = MIN_MERGE; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    FILE *file = fopen("shuffled_list.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int *arr = NULL;
    int n = 0;
    int capacity = 50000; // Initial capacity
    arr = (int *)malloc(capacity * sizeof(int));

    if (arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        if (n >= capacity) {
            capacity *= 2; // Double the capacity
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                perror("Memory reallocation failed");
                return 1;
            }
        }
        arr[n++] = num;
    }

    fclose(file);

    printf("Original array: ");
    printArray(arr, n);

    timSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);

    return 0;
}

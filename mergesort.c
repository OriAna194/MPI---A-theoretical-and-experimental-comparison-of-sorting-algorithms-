#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *left = malloc(n1 * sizeof(int));
    int *right = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        left[i] = a[p + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1)
        a[k++] = left[i++];
    while (j < n2)
        a[k++] = right[j++];

    free(left);
    free(right);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    FILE *fp = fopen("shuffled_list.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int *arr = malloc(500000 * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    int size = 0;
    while (fscanf(fp, "%d", &arr[size]) == 1 && size < 500000) {
        size++;
    }

    fclose(fp);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    free(arr);

    return 0;
}

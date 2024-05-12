#include <stdio.h>

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int swaps = 0; 
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) { 
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps = 1; 
            }
        }
        if (!swaps)
            break; 
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

    bubbleSort(arr, n);

    printf("Array after Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

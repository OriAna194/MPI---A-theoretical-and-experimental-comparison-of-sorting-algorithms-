#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 500000; // Number of elements in the array; modify the value as you wish 
    int arr[n];

   
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    
    FILE *file = fopen("shuffled_list.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

   
    fclose(file);

    return 0;
}

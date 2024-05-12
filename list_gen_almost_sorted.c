#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 500000; // Change this value to set the number of elements in the array
    int k = 2; // Change this value to set the number of elements that are not in their place
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = 0; i < k; i++) {
        int i_rand = rand() % n;
        int j_rand = rand() % n;
        int temp = arr[i_rand];
        arr[i_rand] = arr[j_rand];
        arr[j_rand] = temp;
    }
    FILE *fp = fopen("shuffled_list.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
    return 0;
}
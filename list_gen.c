//LIST GENERATOR

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void shuffle(int *array, size_t n) { 
    if (n > 1) { 
        size_t i; 
        for (i = 0; i < n - 1; i++) { 
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1); 
            int t = array[j]; 
            array[j] = array[i]; 
            array[i] = t; 
        } 
    } 
} 

int main() { 
    srand(time(NULL)); 
    int n = 500000; // generate a sequence of n random numbers; you can modify this value 
    int sequence[n]; 
    int i; 
    for (i = 0; i < n; i++) { 
        sequence[i] = i + 1; 
    } 
    shuffle(sequence, n); 
    
    
    FILE *file = fopen("shuffled_list.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    for (i = 0; i < n; i++) { 
        fprintf(file, "%d ", sequence[i]);
    }
    
    fclose(file);
    
    return 0; 
}
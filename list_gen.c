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
    srand(time(NULL)); // seed the random number generator 
    int n = 10000; // generate a sequence of 10 random numbers 
    int sequence[n]; 
    int i; 
    for (i = 0; i < n; i++) { 
        sequence[i] = i + 1; // initialize the sequence with values 1 through n 
    } 
    shuffle(sequence, n); // shuffle the elements of the sequence 
    
    // Open a file for writing
    FILE *file = fopen("shuffled_list.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    // Write the shuffled list to the file
    for (i = 0; i < n; i++) { 
        fprintf(file, "%d ", sequence[i]);
    }
    
    // Close the file
    fclose(file);
    
    return 0; 
}
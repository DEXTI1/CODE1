#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* dna;
    int inversions;
    int original_index;
} DNAString;

int count_inversions(const char* s, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                count++;
            }
        }
    }
    return count;
}

int compare_dna(const void* a, const void* b) {
    const DNAString* da = (const DNAString*)a;
    const DNAString* db = (const DNAString*)b;
    
    if (da->inversions != db->inversions) {
        return da->inversions - db->inversions;
    } else {
        return da->original_index - db->original_index;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Allocate memory for DNA strings
    DNAString* dna_strings = malloc(m * sizeof(DNAString));
    
    for (int i = 0; i < m; i++) {
        char* dna = malloc((n + 1) * sizeof(char));
        scanf("%s", dna);
        
        dna_strings[i].dna = dna;
        dna_strings[i].inversions = count_inversions(dna, n);
        dna_strings[i].original_index = i;
    }
    
    // Sort the DNA strings
    qsort(dna_strings, m, sizeof(DNAString), compare_dna);
    
    // Output the sorted strings
    for (int i = 0; i < m; i++) {
        printf("%s\n", dna_strings[i].dna);
        free(dna_strings[i].dna); // Free allocated memory
    }
    
    free(dna_strings); // Free the array
    
    return 0;
}

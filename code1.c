#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 3005

int N;
char last_col[MAXN];
char matrix[MAXN][MAXN];

// Comparison function for sorting strings
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf(" %c", &last_col[i]);

    // Step 1: Build N empty strings with just the last column
    for (int i = 0; i < N; ++i) {
        matrix[i][0] = last_col[i];
        matrix[i][1] = '\0';
    }

    // Step 2: Repeat N-1 times: prepend last_col[i] to each string and sort
    for (int step = 1; step < N; ++step) {
        for (int i = 0; i < N; ++i) {
            // Shift and prepend new column value
            for (int j = N - 1; j > 0; --j)
                matrix[i][j] = matrix[i][j - 1];
            matrix[i][0] = last_col[i];
            matrix[i][N] = '\0';
        }

        // Sort the matrix lexicographically
        qsort(matrix, N, sizeof(matrix[0]), compare);
    }

    // Print the first row of the sorted matrix
    for (int i = 0; i < N; ++i)
        printf("%c%c", matrix[0][i], i == N - 1 ? '\n' : ' ');

    return 0;
}

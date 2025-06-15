#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, S;
    scanf("%d %d", &N, &S);

    int *L = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    qsort(L, N, sizeof(int), compare);

    int count = 0;
    int left = 0;
    int right = N - 1;

    while (left < right) {
        if (L[left] + L[right] <= S) {
            count += right - left;
            left++;
        } else {
            right--;
        }
    }

    printf("%d\n", count);

    free(L);
    return 0;
}

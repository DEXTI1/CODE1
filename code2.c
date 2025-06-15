#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

typedef unsigned long long ull;

ull min(ull a, ull b) {
    return a < b ? a : b;
}

ull min3(ull a, ull b, ull c) {
    return min(a, min(b, c));
}

int main() {
    ull p1, p2, p3, n;
    scanf("%llu %llu %llu %llu", &p1, &p2, &p3, &n);

    ull hamming[MAX_SIZE];
    hamming[0] = 1;  // Start from 1 to generate multiples

    int i1 = 0, i2 = 0, i3 = 0;
    int count = 0;

    while (count < n) {
        ull next1 = hamming[i1] * p1;
        ull next2 = hamming[i2] * p2;
        ull next3 = hamming[i3] * p3;

        ull next = min3(next1, next2, next3);

        // Avoid duplicates
        if (next != hamming[count]) {
            hamming[++count] = next;
        }

        if (next == next1) i1++;
        if (next == next2) i2++;
        if (next == next3) i3++;
    }

    printf("%llu\n", hamming[n]);  // hamming[n], not hamming[n-1]

    return 0;
}


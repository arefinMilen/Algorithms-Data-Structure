#include <stdio.h>
int main() {
    int a,k;
    scanf("%d", &a);
    while (a--) {
        int b;
        scanf("%d", &b);
        int carry[b];
        for ( k = 0; k < b; k++) {
            scanf("%d", &carry[k]);
        }
        int swap = 0,i,j;
        for (i = 0; i < b - 1; i++) {
            for ( j = 0; j < b - i - 1; j++) {
                if (carry[j] > carry[j + 1]) {
                    int count = carry[j];
                    carry[j] = carry[j + 1];
                    carry[j + 1] = count;
                    swap++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swap);
    }
    return 0;
}

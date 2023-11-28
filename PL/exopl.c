#include <stdio.h>

void shiftLR(int a[], int b[], int size) {

    int tempa = a[size - 1];
    int tempb = b[0];
    for (int i = 0; i < size; i++) {
        if (size - 1 - i == 0) {
            a[0] = tempa;
            b[size - 1] = tempb;
        } else {
            a[size - 1 - i] = a[size - 1 - i - 1];
            b[i] = b[i + 1];
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d : %d\n", a[i], b[i]);
    }
}

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4};
    shiftLR(a, b, 4);

    return 0;
}

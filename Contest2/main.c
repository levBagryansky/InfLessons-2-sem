#include <stdio.h>

int main() {
    int a; int b;
    scanf("%i", &a);
    scanf("%i", &b);
    int ost = a % b;
    printf("%i \n", ost);
    return 0;
}

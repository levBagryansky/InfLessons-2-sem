#include <stdio.h>

int func(int a, int b, int c)
{
    int sum = a + b + c;
    return sum;
}

int main() {
    int P = func(1, 3, 19);
    printf("%i", P);
    return 0;
}

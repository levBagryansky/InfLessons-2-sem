#include <stdio.h>

int func()
{
    int a; int b; int c;
    a = 7;
    b = 8;
    c = a + b;
    return c;
}

int main() {
    printf("value of func(): %i\n", func());
    return 0;
}

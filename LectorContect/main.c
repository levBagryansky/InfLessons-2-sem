#include <stdio.h>

int function(int c)
{
    c *= 31;
    return c;
}

int main() {
    printf("Hello, World! %i\n", function(2));
    return 0;
}

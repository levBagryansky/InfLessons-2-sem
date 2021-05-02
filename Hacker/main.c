#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/mman.h>

void func1()
{
    printf("It's over, Anakin! I have the high ground!\n");
}

void func2()
{
    printf("You underestimate my power!\n");
}

void hacker_func()
{

}

int main() {
    //  void* p_func1 = &func1;
    //  void* p_func2 = &func2;
    //printf("%li", p_func2 - p_func1);
    //  printf("grrrrrrrr");

    func1();

    long long* pfunc1 = &func1;
    long long* pfunc2 = &func2;

    mprotect(&func1, 256, PROT_READ | PROT_WRITE);
    if (mprotect(&func1, 1024, PROT_READ | PROT_WRITE)) {
        perror("Couldn’t mprotect");
        exit(errno);
    }
    long long change = (pfunc2 - pfunc1 +5 )*16*16 + 0xEB;
    *(pfunc1) = change;
    printf("%x\n", change);
    func1();
    return 0;
}
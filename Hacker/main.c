#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

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
    long long pfunc1 = (long long) &func1;
    long long pfunc2 = (long long) &func2;
    //printf("difference: %i\n", pfunc2 - pfunc1);
    long long pageAdr = pfunc1;
    //printf("pageAdr %x\n", pageAdr);
    long long x = 0xfffffffffffff000;
    pageAdr = pageAdr & x;
    //pageAdr = (pageAdr >> 12) << 12;
    //printf("PageAddr %x\n", pageAdr);
    if (mprotect((long long*) pageAdr, (int) getpagesize (), PROT_READ | PROT_WRITE | PROT_EXEC)) {
        perror("Couldn’t mprotect");
        exit(errno);
    }
    //printf("mprotect worked\n");
    long long change = (pfunc2 - pfunc1 + 2)*16*16 + 0xEB;
    *(int*)(&func1) = change;



}

int main() {
    func1();

    hacker_func();
    func1();

    return 0;
}
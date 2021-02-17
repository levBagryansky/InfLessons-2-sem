#include <stdio.h>
#include <string.h>
#include <locale.h>

void mov(int* pa, int num);
void add(int* pa, int num);
void sub(int* pa, int num);
void all_inf(int* registers);
int find_num(char* str); // find number in the string
int last_arg(int registers[], char* str); // analiz last argument in the string and returnns it's value
void choose_func(char* str, int* registers);

int main()
{
    int registers[4] = {0};
    char str[20];
    printf("Write \"Finish\" to stop.\n");
    do {
        all_inf(registers); // show all information
        gets(str);
        choose_func(str, registers);
    } while (strcmp(str, "Finish") != 0);
}

void mov(int* pa, int num)
{
    *pa = num;
}

void add(int* pa, int num)
{
    *pa = *pa + num;
}

void sub(int* pa, int num)
{
    *pa = *pa - num;
}

void all_inf(int* registers)
{
    printf("Register values eax, ebx, ecx, edx: %i, %i, %i, %i.\n",
           *registers, *(registers + 1), *(registers + 2), *(registers + 3));
}

int find_num(char* str) // find number in the string
{
    int sum = 0;
    int next_c;
    if (str[9] == '-') {
        int i = 10;
        while (next_c = str[i])
        {
            i++;
            sum = sum * 10 + next_c - '0';
        }
        return (-sum);
    }
    else
    {
        int i = 9;
        while (next_c = str[i])
        {
            i++;
            sum = sum * 10 + next_c - '0';
        }
        return sum;
    }
}

int last_arg(int registers[], char* str) // analiz last argument in the string and returnns it's value
{
    if(str[9]=='e')
        return registers[str[10]-'a'];
    return find_num(str);
}

void choose_func(char* str, int* registers)
{
    if (str[0] == 'm') // mov
    {
        mov(&(registers[str[5] - 'a']), last_arg(registers, str));
    }
    else if (str[0] == 'a') // add
    {
        add(&(registers[str[5] - 'a']), last_arg(registers, str));
    }
    else if (str[0] == 's') // sub
    {
        sub(&(registers[str[5] - 'a']), last_arg(registers, str));
    }
    else
    {
        if (strcmp(str, "Finish") != 0)
        {
            printf("invalid command\n");
        }
    }
}
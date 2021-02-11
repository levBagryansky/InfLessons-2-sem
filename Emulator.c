#include <stdio.h>
#include <string.h>
#include <locale.h>


void mov(int* pa, int* pb);
void add(int* pa, int* pb);
void sub(int* pa, int* pb);
void all_inf(int* pa, int* pb, int* pc, int* pd);
int find_num(char* str); // find number in the string
void choose_func(char* str, int* pa, int* pb, int* pc, int* pd);

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    setlocale(LC_ALL, "Rus");
    char str[20];
    printf("Write \"Finish\" to stop.\n");
    do {
        all_inf(&a, &b, &c, &d); // show all information
        gets(str);
        choose_func(str, &a, &b, &c, &d);
    } while (strcmp(str, "Finish") != 0);

}

void mov(int* pa, int* pb)
{
    *pa = *pb;
}

void add(int* pa, int* pb)
{
    *pa = *pa + *pb;
}

void sub(int* pa, int* pb)
{
    *pa = *pa - *pb;
}

void all_inf(int* pa, int* pb, int* pc, int* pd)
{
    printf("Register values eax, ebx, ecx, edx: %i, %i, %i, %i.\n", *pa, *pb, *pc, *pd);
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

void choose_func(char* str, int* pa, int* pb, int* pc, int* pd)
{
    if (str[0] == 'm') // mov
    {
        if (str[5] == 'a')
        {
            if (str[10] == 'b')
            {
                mov(pa, pb);
            }
            else if (str[10] == 'c')
            {
                mov(pa, pc);
            }
            else if (str[10] == 'd')
            {
                mov(pa, pd);
            }
            else // there is number
            {
                *pa = find_num(str);
            }
        }
        else if (str[5] == 'b')
        {
            if (str[10] == 'a')
            {
                mov(pb, pa);
            }
            else if (str[10] == 'c')
            {
                mov(pb, pc);
            }
            else if (str[10] == 'd')
            {
                mov(pb, pd);
            }
            else // there is number
            {
                *pb = find_num(str);
            }
        }
        else if (str[5] == 'c')
        {
            if (str[10] == 'a')
            {
                mov(pc, pa);
            }
            else if (str[10] == 'b')
            {
                mov(pc, pb);
            }
            else if (str[10] == 'd')
            {
                mov(pc, pd);
            }
            else // there is number
            {
                *pc = find_num(str);
            }
        }
        else if (str[5] == 'd')
        {
            if (str[10] == 'a')
            {
                mov(pd, pa);
            }
            else if (str[10] == 'b')
            {
                mov(pd, pb);
            }
            else if (str[10] == 'c')
            {
                mov(pd, pc);
            }
            else // there is number
            {
                *pd = find_num(str);
            }
        }
    }
    else if (str[0] == 'a') // add
    {
        if (str[5] == 'a')
        {
            if (str[10] == 'b')
            {
                add(pa, pb);
            }
            else if (str[10] == 'c')
            {
                add(pa, pc);
            }
            else if (str[10] == 'd')
            {
                add(pa, pd);
            }
            else // there is number
            {
                *pa += find_num(str);
            }
        }
        else if (str[5] == 'b')
        {
            if (str[10] == 'a')
            {
                add(pb, pa);
            }
            else if (str[10] == 'c')
            {
                add(pb, pc);
            }
            else if (str[10] == 'd')
            {
                add(pb, pd);
            }
            else // there is number
            {
                *pb += find_num(str);
            }
        }
        else if (str[5] == 'c')
        {
            if (str[10] == 'a')
            {
                add(pc, pa);
            }
            else if (str[10] == 'b')
            {
                add(pc, pb);
            }
            else if (str[10] == 'd')
            {
                add(pc, pd);
            }
            else // there is number
            {
                *pc += find_num(str);
            }
        }
        else if (str[5] == 'd')
        {
            if (str[10] == 'a')
            {
                add(pd, pa);
            }
            else if (str[10] == 'b')
            {
                add(pd, pb);
            }
            else if (str[10] == 'c')
            {
                add(pd, pc);
            }
            else // there is number
            {
                *pd += find_num(str);
            }
        }

    }
    else if (str[0] == 's') // sub
    {
        if (str[5] == 'a')
        {
            if (str[10] == 'b')
            {
                sub(pa, pb);
            }
            else if (str[10] == 'c')
            {
                sub(pa, pc);
            }
            else if (str[10] == 'd')
            {
                sub(pa, pd);
            }
            else // there is number
            {
                *pa -= find_num(str);
            }
        }
        else if (str[5] == 'b')
        {
            if (str[10] == 'a')
            {
                sub(pb, pa);
            }
            else if (str[10] == 'c')
            {
                sub(pb, pc);
            }
            else if (str[10] == 'd')
            {
                sub(pb, pd);
            }
            else // there is number
            {
                *pb -= find_num(str);
            }
        }
        else if (str[5] == 'c')
        {
            if (str[10] == 'a')
            {
                sub(pc, pa);
            }
            else if (str[10] == 'b')
            {
                sub(pc, pb);
            }
            else if (str[10] == 'd')
            {
                sub(pc, pd);
            }
            else // there is number
            {
                *pc -= find_num(str);
            }
        }
        else if (str[5] == 'd')
        {
            if (str[10] == 'a')
            {
                sub(pd, pa);
            }
            else if (str[10] == 'b')
            {
                sub(pd, pb);
            }
            else if (str[10] == 'c')
            {
                sub(pd, pc);
            }
            else // there is number
            {
                *pd -= find_num(str);
            }
        }

    }
    else
    {
        if (strcmp(str, "Finish") != 0)
        {
            printf("invalid command\n");
        }
    }
}
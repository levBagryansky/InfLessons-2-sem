#include <stdio.h>
#include <io.h>
#include "stdlib.h"
#include "string.h"
#define name_file "ordinaryFile.txt"

FILE* openFile(char name[], int* lenP);
char* getString(FILE* fp, int len);
char* getString1(FILE* fp, int len);
int findString(char* str, int lenStr, char  part[]);
void changeStr(char* str, int* lenP, char* prevPart, char* newPart, int n);
void writeToFile(char* name, char* str);


void printstr(char* str, int len);

int main() {
    int len = 0;
    FILE* fp = openFile("1.txt", &len);
    //printf("Lenght of string: %i\n", len);

    char* str = getString(fp,  len);
    printstr(str, len);
   // printf("%The String:\n%s\nlen: %i\nlast symbol: %c\n", str, len, str[len-1]);

    int partNum = findString(str, len, "Hello World");
    //printf("%c\n", str[partNum]);

    printstr(str, len);
    changeStr(str, &len, "Hello World", "Ahahahahaha", partNum);
    //printstr(str, len);
    printstr(str, len);
    writeToFile("1.txt", str);
    return 0;
}

FILE* openFile(char name[], int* lenP)
{
    FILE* fp;
    if ((fp = fopen(name, "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    *lenP = ftell(fp) - 3;
    rewind(fp);
    return fp;
}
///
char* getString1(FILE* fp, int len)
{
    char* str = (char*) calloc(len, sizeof (char));
    fscanf(fp, "%s", str);
    printstr(str, len);
    return str;
}

char* getString(FILE* fp, int len)
{
    char* str = (char*)calloc(len, sizeof(char));
    int i;
    for (i = 0; i < len; i++) {
        str[i] = getc(fp);
        //printf("%c", str[i]);
    }
    return str;
}

int findString(char* str, int lenStr, char  part[])
{
    int lenPart = strlen(part);
    int i = lenStr-1;
    int j = lenPart-1;
    while (i > 0 && j > 0)
    {
        if(str[i] == part[j])
        {
            i--;
            j--;
            //printf("There is coincidence %c\n", str[i]);
        }
        else
        {
            j = lenPart-1;
            i--;
        }
    }
    //printf("j is %i\n", j);
    if (j == 0)
        return i;
    printf("There is no that part");
    exit(-1);
}

void changeStr(char* str, int* lenP, char* prevPart, char* newPart, int n)
{
    int lenPrevPart = strlen(prevPart);
    int lenNewPart = strlen(newPart);
    if (lenPrevPart == lenNewPart)
    {
        int i;
        for (i = n; i < n + lenNewPart; i++) {
            str[i] = newPart[i-n];
        }
    }
    else
    {
        printf("гnequal lenghts\n");
    }
}

void writeToFile(char* name, char* str)
{
    FILE* fp = fopen(name, "w");
    fprintf(fp, "%s", str);
}

void printstr(char* str, int len)
{
    printf("Str right now:\n");
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
    }
    printf("\n\n");
}

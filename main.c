#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#define name_file "ordinaryFile.txt"

FILE* openFile(char name[], int* lenP);
char* getString(FILE* fp, int* lenP);
int findString(char* str, int lenStr, char  part[]);
int changeStr(char* str, char* prevPart, char* newPart, int n);


int main() {
    int len = 0;
    FILE* fp = openFile("1.txt", &len);
    //printf("Lenght of string: %i\n", len);

    char* str = getString(fp, &len);

    int partNum = findString(str, len, "Hello World");

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
    *lenP = ftell(fp);
    rewind(fp);
    return fp;
}

char* getString(FILE* fp, int* lenP)
{
    char* str = (char*)calloc(*lenP, sizeof(char));
    int i;
    for (i = 0; i < *lenP; i++) {
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



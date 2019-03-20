#include<stdio.h>
#include<string.h>

int main()
{
    int i;
    char Pixar[3]={'s', 'o' , 's'};
    char *name[] = {"wm","wangmiao","complicatephenomenon","czfzdxx"}; //  指向字符数据型的指针数组构成的数组
    char *pta;
    char prompt[] = "Press Enter to explode:";
    char *ptrToString;
    ptrToString = prompt;

    /**
     * 不用指针，直接用数组储存多个字符串怎么就行不通？
     * char Name[] = {"wm","wangmiao","complicatephenomenon","czfzdxx"};
     **/


    pta = &Pixar[0];

    printf("%s\n",prompt);
    printf("%s\n", ptrToString);


    printf("We define 2 variable, an array called Pixar stored the string 'sos', a pointer pointing to Pixar.\nThe variable 'Pixar' actually resolves to the address of its first element ('&Pixar[0]),\n");

    for(i = 0; i < sizeof(Pixar); i++){
        printf("Pixar[%d] = %c, *(Pixar+%d) = %c, *(pta+%d)=%c \n",i,  Pixar[i], i, *(Pixar + i), i,  pta[i]);
        printf("&(Pixar[%d]) = %p, *(pta+%d)   = %p\n", i,  &(Pixar[i]), i,  pta+i);
    }

    for(int i = 0; i < sizeof(name)/sizeof(name[0]); i++){
    printf("name[%d]=%s, *name[%d]=%p\n",i,name[i], i, *name+i);
    }

    return 0;
}

#include <stdio.h>
#include<stdlib.h>

typedef struct id{
    char email[50];
    char branch[5];
    char id[13];
}student;

void idGenerator(student * stu)
{
    for(int i=0;i<4;i++)
    {
        (stu->id)[i] = (stu->email)[i+1];
    }

    stu->id[6]='P';
    stu->id[7]='S';
    stu->id[12]='H';

    for(int i=0;i<4;i++)
    {
        stu->id[i+8]=stu->email[i+5];
    }

    char cs[2]={'C','S'};
    int comp=0;
    char ece[3]={'E','C','E'};
    int elec=0;
    char eee[3]={'E','E','E'};
    int instr=0;

    for(int i=0;i<2;i++)
    {
        if(cs[i]==stu->branch[i])
        {
            comp=1;
        }
        else
        comp=0;
        if(ece[i]==stu->branch[i])
        {
            elec=1;
        }
        else
        elec=0;
        if(eee[i]==stu->branch[i])
        {
            instr=1;
        }
        else
        instr=0;
    }

    if(comp)
    {
        stu->id[4]='A';
        stu->id[5]='7';
    }

    if(elec)
    {
        stu->id[4]='A';
        stu->id[5]='A';
    }

    if(instr)
    {
        stu->id[4]='A';
        stu->id[5]='3';
    }

    for(int i=0;i<13;i++)
    {
        printf("%c",(stu->id)[i]);
    }
}
    
int main()
{
    student * stu=malloc(sizeof(student));
    
    scanf("%s", stu->email);
    scanf("%s", stu->branch);

    idGenerator(stu);
    return 0;
}
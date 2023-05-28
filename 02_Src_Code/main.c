#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    int ID;
    List l;
    Student_t S;
    createlist(&l);
    IntroMenu(&l,&S,ID);
    return 0;
}

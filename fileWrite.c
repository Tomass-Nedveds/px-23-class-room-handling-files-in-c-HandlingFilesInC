#include <stdio.h>
#include <string.h>

int main()
{
    char text[]={"lol kek cheburek!"};
    FILE *fp;
    fp = fopen("test.txt","a+"); //open or add tekst.txt
    fprintf(fp,"%s",text); //add text in tekst.txt
    fclose(fp); //close file

}

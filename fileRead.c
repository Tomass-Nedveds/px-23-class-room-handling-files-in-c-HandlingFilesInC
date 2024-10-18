#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[500];
    char line[5];
    FILE *fp; //faile in fp
    fp = fopen("test.txt","r"); //open fp
    while(fgets(line,5,fp)!=NULL) //while
    {
        printf("%s\n",line);
        strcat(buffer,line); //save line in buffer
    }
    fclose(fp); //close fp
    printf("%s",buffer); //print all symbols

return 0;
}
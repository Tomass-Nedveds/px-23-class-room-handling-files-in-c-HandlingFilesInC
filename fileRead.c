#include <stdio.h>
#include <string.h>
int main()
{
    char buffer[500];
    char line[5];
    FILE *fp;
    fp = fopen("test.txt","r");
    while(fgets(line,5,fp)!=NULL)
    {
        printf("%s\n",line);
        strcat(buffer,line);
    }
    fclose(fp);
    printf("%s",buffer);

return 0;
    
    
}
#include <stdio.h>
#include <string.h>

int main(){
    char buffer [500];
    char wordcount [500];
    char fileName [50];
    char line [100];

    printf("Enter file name: \n ========= ");
    scanf("%s", fileName);
    FILE *fp;
    fp = fopen(fileName, "r");

    int i;
    while(fgets(line,100,fp)!=NULL)
        strcat(buffer,line);
    

    fclose(fp);
    printf("%s \n",buffer);

    return 0;
}
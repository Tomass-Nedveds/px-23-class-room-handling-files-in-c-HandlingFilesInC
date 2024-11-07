#include <stdio.h>
#include <string.h>

int main(){
    char fileName[50];
    char buffer[100];
    char line[10];
    char text[100];

    printf("1.Reading file\n 2.Writing to file\n 3.Appending to file\n 4.Counting words, lines, and characters in a file\n");
    printf("Enter number: ");
    scnaf("");


    printf("Enter file name: ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");

    while(fgets(line,100,fp)!=NULL)
        strcat(buffer,line);
    fclose(fp);

    printf("==========\n");
    printf("%s \n", buffer);
    printf("==========\n");
    printf("Enter text: ");
    getchar();
    fgets(text, sizeof(text), stdin);
    

    

    
    fclose(fp);
    
    return 0;
}
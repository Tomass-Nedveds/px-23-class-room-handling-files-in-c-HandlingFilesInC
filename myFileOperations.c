#include <stdio.h>
#include <string.h>

int main(){
    char fileName[50];
    char buffer[100];
    char line[10];
    char text[100];
    int num;

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
    





/*    printf("1.Reading file\n2.Writing to file\n3.Appending to file\n4.Counting words, lines, and characters in a file\n");
    printf("Enter number: ");
    scanf("%d", &num);
*/        

    return 0;
}
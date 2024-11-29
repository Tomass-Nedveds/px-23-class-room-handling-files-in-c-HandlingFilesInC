#include <stdio.h>
#include <string.h>

int main(){
    char fileName[50];
    char buffer[999];
    char line[999];
    char text[100];
    int num;
    int sum = 0;
    int lineCount = 0;
    int end;

    printf("1.Reading file\n2.Writing to file\n3.Appending to file\n4.Counting words, lines, and characters in a file\n");
    printf("------------------\n");
    printf("Enter number: ");
    scanf("%d", &num);
    getchar();
    printf("Enter file name: ");
    scanf("%s", fileName);
    getchar();
    FILE *fp = fopen(fileName, "r");

    while(fgets(line,999,fp)!=NULL)
            strcat(buffer,line);
    
    printf("==================\n");
    printf("%s", buffer);
    printf("\n==================\n");
    fclose(fp);

    if(num == 1){
        printf("%s \n", buffer);
    }

    if(num == 2){
        printf("Enter text: ");
        fgets(text, sizeof(text), stdin);
        FILE *fp = fopen(fileName, "w");
        fprintf(fp, "%s", text);
        fclose(fp);
    }

    if(num == 3){
        printf("Enter text: ");
        fgets(text, sizeof(text), stdin);
        FILE *fp = fopen(fileName, "a");
        fprintf(fp, "%s", text);
        fclose(fp);
        }
    
    if(num == 4){
        FILE *fp = fopen(fileName, "r");
        int i = 0;
        while(buffer[i] != '\0'){
            if(buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i] >= 'a' && buffer[i] <= 'z'){
                if(buffer[i+1] == ' ' || buffer[i+1] == '\n' || buffer[i+1] == '!'){
                    sum++;
                }
            }
        i++;
        }

        while ((end = fgetc(fp)) != EOF) {
            if (end == '\n') {
                lineCount++;
         }   
    }
    
        printf("Sum of line: %d\n", lineCount);
        printf("Sum of words: %d\n", sum);
        fclose(fp);
    }
    
    return 0;
}
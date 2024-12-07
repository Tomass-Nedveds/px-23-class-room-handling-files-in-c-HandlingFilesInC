#include <stdio.h>

int main(){
    char buffer [500];
    char wordcount [500];
    char fileName [50];
    char line [100];
    char verb [1];
    int sum = 0;

    printf("Enter file name: ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");

    if (!fp){
        printf("error\n");
        return 1;
    }

    while(fgets(line,100,fp)!=NULL)
        strcat(buffer,line);
    
    int i = 0;
    while(buffer[i] != '\0'){
        if(buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i] >= 'a' && buffer[i] <= 'z'){
            if(buffer[i+1] == ' ' || buffer[i+1] == '\n' || buffer[i+1] == '!'){
                sum++;
            }
        }
    i++;
    }
    
    if (sum == 0){
        printf("error\n");
        return 0;
    }

    fclose(fp);
    printf("%s \n",buffer);
    printf("Sum of all word: %d \n", sum);
    return 0;
}
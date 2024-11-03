#include <stdio.h>
#include <string.h>

int main(){
    char text[42];
    char fileName[20];
    char name;

    printf("Input file nme: ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");
    
    if(!fp){
        printf("error\n");
        return 1;
    }

    fclose(fp);
    printf("Enter text: ");
    getchar();
    fgets(text, sizeof(text), stdin);
    printf("w or a:  ");
    scanf("%c", &name);

    if(name == 'a'){
        FILE *fp = fopen(fileName, "a");
        fprintf(fp, "%s", text);
        fclose(fp);
    }

    else if(name == 'w'){
        FILE *fp = fopen(fileName, "w");
        fprintf(fp, "%s", text);
        fclose(fp);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char text[42];
    char fileName[20];
    char mode;

    printf("Input file name: ");
    scanf("%s", fileName); 
    getchar();

    printf("w or a: ");
    scanf("%c", &mode);
    getchar();

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    FILE *fp = NULL;
    if (mode == 'w') {
        fp = fopen(fileName, "w");
    } 
    else if (mode == 'a') {
        fp = fopen(fileName, "a");
    } 

    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "%s", text);
    fclose(fp);
    return 0;
}

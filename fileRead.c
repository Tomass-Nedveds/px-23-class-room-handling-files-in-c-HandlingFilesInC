#include <stdio.h>

int main()
{
    int len;
    FILE *fp;
    fp = fopen("test.yuri","r");
    fread(&len,sizeof(int),1,fp);
    int* arr = malloc(sizeof(int)*len);
    fread(arr,sizeof(int),len,fp);
    fclose(fp);
    int i;
    for(i = 0; i<len; i++)
    {
        printf("%d\n",arr[i]);
        }
    return 0;

}
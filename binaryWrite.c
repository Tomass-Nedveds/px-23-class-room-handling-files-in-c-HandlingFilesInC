#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len = 12;
    int arr[] = {1,2,0,4,0,6,7,0,9,10,11,12};
    FILE *fp;
    fp = fopen("test.yuri","w+");
    fwrite(&len,sizeof(int),1,fp);
    fwrite(arr,sizeof(int),len,fp);
    fclose(fp);
    return 0;

}
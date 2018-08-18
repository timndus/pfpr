#include <stdio.h>
 
#define MAXCHAR 1000
int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "data";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    fgets(str, MAXCHAR, fp);
    printf("%s", str);
    fclose(fp);
    return 0;
}

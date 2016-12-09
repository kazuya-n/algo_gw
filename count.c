#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i=0;
    int diff=0;
    char a[500000];
    char b[500000];
    FILE *fp1;
    FILE *fp2;
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("file 1 open error!!\n");
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        printf("file 2 open error!!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp1,"%s\n",a);
    fscanf(fp2,"%s\n",b);
    for(i=0;i<500000;i++){
        if(a[i]==b[i]) diff++;
    }
    printf("%.3f",((double)diff/500000));
    return 0;
}

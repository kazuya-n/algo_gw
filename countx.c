#include <stdio.h>

int main(void){
    char T[500010];
    int xsum[1000];
    int i;
    int xcount=0;
    int xnum=0;
    scanf("%s",T);
    for(i=0;i<1000;i++){
        xsum[i]=0;
    }
    for(i=0;i<500000;i++){
        if(T[i]=='x') xcount++;
        if(T[i]!='x'&&xcount!=0){
            xsum[xcount]++;
            xcount=0;
            xnum++;
        }
    }
    printf("total x group is%d\n",xnum);
    printf("x's length group is here\n");
    printf("x's length,num\n");
    for(i=0;i<50;i++){
        printf("%d,%d\n",i,xsum[i]);
    }
    return 0;
}

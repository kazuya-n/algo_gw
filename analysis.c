#include <stdio.h>
#include <string.h>
int main(void){
    int i = 0;
    char T[600000];
    char S[600000];
    int count[500000];
    int total = 0;
    for(i=0;i<500000;i++){
        count[i]=0;
    }
    scanf("%s",T);
    printf("length of T is %d\n",(int)strlen(T));
    for(i=0;i<500000;i++){
        if(scanf("%s",S)==EOF)break;
        count[strlen(S)]++;
        total++;
    }
    printf("total count is %d\n",total);
    for(i=0;i<500000;i++){
        if(count[i]==0)continue;
        printf("S[ %d ] 's count is %d\n",i,count[i]);
    }
    return 0;
}

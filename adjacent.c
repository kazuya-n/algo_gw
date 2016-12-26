#include <stdio.h> 
int main(void){
    char T[500010];
    scanf("%s",T);
    int i=0;
    int j=0;
    int count[4][4];
    int pair=0;
    for(i=0;i<500000-1;i++){
        count[T[i]-'a'][T[i+1]-'a']++;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c,%c,%d\n",'a'+i,'a'+j,count[i][j]);
        }
    }
    //printf("%d,%d\n",count,pair);
    return 0;
}

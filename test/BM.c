#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//とりあえずTの最大文字数は100
#define MAX_T 500000
//とりあえずSiの最大文字数は10
#define MAX_S 150
//とりあえずSiの個数は10個
#define MAX_S_N 60000

char T [MAX_T];
char S [MAX_S];
//Tの長さ
int T_len;

//BM法で探索する関数
int BM (void);
//BM法におけるずらし幅を決める関数
void BMinit(int *table,int  len);

int main(void){
    int i;
    int index=0;
    //Tを読み込み
    scanf("%s",T);
    T_len = strlen(T);
    //Sを回数分読み込み
    //検索し結果を出力
    for(i=0;i<MAX_S_N;i++){
        scanf("%s",S);
        index = BM();
        if(index != -1){
            printf("%s is found at input string on %d\n",S,index);
        }else{
            printf("%s is not found\n",S);
        }
    }
    return 0;
}

void BMinit(int *table,int  len){
    int i;
    //ずらし幅を決める
    //検索クエリの右側から見ていき、対応する文字が
    //左端から何番目にあるか検討する。
    //Sの全ての文字がTに含まれるので、これだけで十分。
    for(i=0;i<len;i++){
        table[(int)S[i]]=len-1-i;
    }
    //デバッグ出力
    for(int i=0;i<len;i++){
        printf("%c's slide count is %d\n",S[i],table[(int)S[i]]);
    }
    return;
}

int BM(void){
    int S_len = strlen(S);
    int BM_table[MAX_S];
    //iはTの何文字目かを指し示し、jはSの何文字目かを指し示す。
    int i,j;
    //ループ防止用変数
    int remain;
    BMinit(BM_table,S_len);
    //比較スタート
    //パターンSの末尾に検索位置を合わせる。
    i=j=S_len-1;
    while((i<T_len)&&(j>=0)){
       //デバッグ
       //printf("checking T - %c: S - %c \n",T[i],S[j]);
       //同じかどうか
       if(T[i]!=S[j]&&T[i]!='x'){
           //まずループ防止チェック
           //基本的にはずらし幅に対応する文字をテーブルから探す。
           remain = S_len - j;
           if(BM_table[(int)T[i]]>remain){
               i += BM_table[(int)T[i]];
           } else {
               i += remain;
           }
           j = S_len-1;
       } else {
           i--;
           j--;
       }
    }
    //見つかったらテキストの場所を返す。
    if(j<0) return i+1;
    //見つからなかったら-1を返す。
    return -1;
}

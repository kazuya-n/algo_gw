#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

/*usage
 example:grpwk < data1_in >data1_out
*/

//とりあえずTの最大文字数は100
#define MAX_T 500000
//とりあえずSiの最大文字数は10
#define MAX_S 150
//とりあえずSiの個数は10個
#define MAX_S_N 60000
//元の文字列
char T [MAX_T];
//部分文字列
char S [MAX_S];
//部分文字列の入力を取る
char S_inp[MAX_S_N][MAX_S];
//Tの長さ
int T_len;
//BM法で探索する関数
int BM (void);
//BM法におけるずらし幅を決める関数
void BMinit(int *table,int  len);
//クイックソート用1
int compare_s(const void *a, const void *b);


int main_prg(int, char**);

int main(int argc, char** argv){

  struct rusage u;
  struct timeval start, end;
  
  getrusage(RUSAGE_SELF, &u);
  start = u.ru_utime;
  
  main_prg(argc, argv);
  
  getrusage(RUSAGE_SELF, &u );
  end = u.ru_utime;
  
  fprintf(stderr, "%lf\n", (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)*1.0E-6);
    
  return(0);
}

int main_prg(int argc, char** argv){
    int i,j,k;
    int index=0;
    //Tを読み込み
    scanf("%s",T);
    T_len = strlen(T);
    //Sを回数分読み込み
    //検索し結果を出力
    while(scanf("%s",S_inp[k++])!=EOF);
    qsort(S_inp, k, sizeof(S_inp[0]), compare_s);
    for(i=0;i<k;i++){
        //scanf("%s",S);
        strcpy(S,S_inp[i]);
        index = BM();
        if(index != -1){
            //printf("%s is found at input string on %d\n",S,index);
            for(j=0;j<strlen(S);j++){
                T[index+j]=S[j];
            }
        }else{
            //printf("%s is not found\n",S);
        }
    }
    //xが残ってたらaで消す
    for(i=0;i<MAX_T;i++){
        if(T[i]=='x') T[i] = 'a';
    }
    printf("%s\n",T);
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
    /*
     for(int i=0;i<len;i++){
     printf("%c's slide count is %d\n",S[i],table[(int)S[i]]);
     }
     */
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
        //1文字ずつ比較するところ
        //xだったら無視して同じだった扱いにする。
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


int compare_s(const void *a, const void *b)
{
    char *aa=(char*)a;
    char *bb=(char*)b;
    return strlen(bb)-strlen(aa);
}

#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#define MAX 500000
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
  char input[MAX];
  char phrase[MAX];
  int map[MAX];
  //部分文字列の長さ
  int len=0;
  //インプットの長さ
  int count=0;
  //現在見ている位置
  int current=0;
  int i,j,k;
  scanf("%s",input);
  //input phrase
  count=strlen(input);
  while(scanf("%s",phrase)!=EOF){
    printf("aaaa");
    printf("%s",phrase);
    len=strlen(phrase);
    //if(len<2) continue;
    //ずらし表を作る
    for(i=0;i<len-1;i++){
        map[i]=len-i-1;
    }
    current=0;
    //検索
    while((current+len)<count-1){
        //末尾から1文字ずつ比較
        for(j=len-1;j>=0;j--){
            //inpの比較する末尾を見た結果文字数オーバーしてたらおしまい
            if(j+current>count-1) break;
            //入力文字列がxだったら比較できないので飛ばす
            if(input[j+current]=='x') continue;
            //一致したら次のループへ
            if(input[j+current]==phrase[j]){
                continue;
            //一致しなかったら飛ばし表に従い次の文字へ
            }else{
                current+=map[j];
                j=-1;
                break;
            }
        }
        //ループを全部回ってここにきたら全ての文字列が一致したことになるので書き換え
        if(j==0){
            for(j=0;j<len-1;j++){
                input[current+j]=phrase[j];
            }
            break;
        }
    }
  }
  printf("%s",input);
  return (0);
}


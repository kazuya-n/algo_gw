#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
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
  srand((unsigned int)time(NULL));
  scanf("%s\n",input);
  int i;
  int ran;
  for(i=0;i<MAX;i++){
      if(input[i]=='x'){
          ran=rand()%3;
          switch (ran){
              case 0:
                input[i]='a';
                break;
              case 1:
                input[i]='b';
                break;
              case 2:
                input[i]='c';
                break;
        }
      }
      putchar(input[i]);
  }
  return (0);
}


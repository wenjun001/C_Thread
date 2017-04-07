#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>



typedef struct shareData{

char * functionName;
long  during;
} SHAREDDATA;

SHAREDDATA share[40] = {};

void *myThreadFun(void *vargp) {

SHAREDDATA * internal = (SHAREDDATA *)vargp;


while(1) {
    for (int i = 0; i < 10; i++) {

        sleep(1);
        if (internal[i].during > 0) {
            printf("get Value internal[i].functionName  %s\n", internal[i].functionName);
            printf("get Value internal[i].during  %d\n", internal[i].during);
            internal[i].during = 0;
        } else {
            printf("data is not ready!!!\n");
        }

    }
}





printf("Printing GeeksQuiz from Thread \n");
return NULL;
}

int main() {

pthread_t tid;
pthread_create(&tid, NULL, myThreadFun, share);

while(1) {
    for (int i = 0; i < 10; i++) {
        char name[30] = "function";
        char index[4];
        sprintf(index, "%d", i);
        char * finalName=strcat(name,index);
        //printf("%s\n",finalName);
        share[i].functionName = finalName;
        share[i].during = i;
        sleep(1);
    }
}



pthread_join(tid, NULL);


printf("After Thread\n");

int seconds;

seconds = time((time_t*)NULL);
printf("current Time stamp %d \n",seconds);

struct timeval tv;

unsigned long long seconds2;

gettimeofday(&tv,NULL);

seconds2 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
printf("current Time stamp %d \n",seconds2);

exit(0);
}

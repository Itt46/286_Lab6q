#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum;
int num;
void *runner(void *param);

int main(int argc, char *argv[]){
    int msum = 0;
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    scanf("%d",&num);
    pthread_create(&tid, &attr, runner, argv[1]);

    for(int i = 1; i <= num; i++){
        msum += i;
    }
    pthread_join(tid,NULL);
    printf("csum - msum: %d\n",csum-msum);
    return 0;
}
void *runner(void *param){;
    csum = 0;
    for(int i = 1; i <= num*2; i++){
        csum += i;
    }
    pthread_exit(0);
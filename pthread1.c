#include<stdio.h>
#include<pthread.h>


void * add(void *a){
	int *b;
	b=(int *)a;
	int sum;
	sum=b[0]+b[1];
	printf("in function\n");
	return (void *)sum;
}
int main(){

	int c;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	int a[2]={3,5};
	pthread_create(&tid,NULL,&add,a);
	pthread_attr_destroy(&attr);
	pthread_join(tid,(void *)&c);
	printf("%d\n",(int *)c);
	return 0;
}


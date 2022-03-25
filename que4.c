#include<pthread.h>;
#include<stdio.h>;

pthread_t tid;

void* thread1(void *arg)
{
pid_t pid;
pthread_t tid;
pid=getpid(); //process id
tid=pthread_self(); //thread id

printf(&quot;pid %u and thread id %u\n&quot;,(unsigned int)pid,(unsigned int)tid);
return 0;
}

int main(void)
{
int ret = pthread_create(&amp;tid,NULL,thread1,NULL);

if(ret)
{
printf(&quot;thread is not created\n&quot;);
}
else

{
printf(&quot;thread is created\n&quot;);
}

//while(1);
//exit(0);
sleep(2);
//pthread_join(tid,NULL); //make parent to wait to execute
return 0;
}

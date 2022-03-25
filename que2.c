#include<pthread.h>;

pthread_t tid;

void* thread1(void *arg)
{
printf(&quot;newly created thread executing\n&quot;);
while(1);
}

int main(void)
{
int ret = pthread_create(&amp;tid,NULL,thread1,NULL);
int t=0;

printf(&quot;Thread id: %u\n&quot;,tid);
sleep(6);

t=pthread_cancel(tid);

if(t==0)
printf(&quot;cancel thread\n&quot;);

printf(&quot;Thread id: %u\n&quot;,tid);

// sleep(2);
//pthread_join(tid,NULL); //make parent to wait to execute
return 0;
}

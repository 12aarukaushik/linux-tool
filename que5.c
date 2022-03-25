#include<stdio.h>;
#include<pthread.h>;
#include<stdlib.h>;

int sharedVar = 5; //shared variable protected variable
pthread_mutex_t my_mutex;

void *thread_inc(void *arg)
{
pthread_mutex_lock(&amp;my_mutex);
sharedVar++;

printf(&quot;after increament %d\n&quot;, sharedVar);
pthread_mutex_unlock(&amp;my_mutex);
}

void *thread_dec(void *arg)

{
pthread_mutex_lock(&amp;my_mutex);
sharedVar--;

printf(&quot;after decrement %d\n&quot;, sharedVar);
pthread_mutex_unlock(&amp;my_mutex);
}

int main()
{
pthread_t t1,t2;

pthread_mutex_init(&amp;my_mutex,NULL);

pthread_create(&amp;t1,NULL,thread_inc,NULL);
pthread_create(&amp;t2,NULL,thread_dec,NULL);

pthread_join(t1,NULL);
pthread_join(t2,NULL);

printf(&quot;shared variable %d\n&quot;, sharedVar);

return 0;
}

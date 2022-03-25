#include<stdio.h>;
#include<pthread.h>;
#include<stdlib.h>;

int i = 5; //global variable

void *threadIncrementFive(void *arg) //increment shared variable function
{
i=i+5;

printf(&quot;After increament by 5: %d\n&quot;, i);
}

void *threadDecrementTwo(void *arg) //decrement shared variable function
{
i=i-2;

printf(&quot;After decrement by 2: %d\n&quot;, i);
}

int main()
{
pthread_t t1,t2;

pthread_create(&amp;t1,NULL,threadIncrementFive,NULL); //create thread1
pthread_create(&amp;t2,NULL,threadDecrementTwo,NULL); //create thread2

pthread_join(t1,NULL);
pthread_join(t2,NULL);

printf(&quot;Shared variable value: %d\n&quot;, i);

return 0;
}

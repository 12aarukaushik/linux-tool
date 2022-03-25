#include<pthread.h>;
#include<stdio.h>;
#include<unistd.h>;
#include<stdlib.h>;
#include<sys/mman.h>;

void *Proc(void *param)
{
sleep(2);
return 0;
}

int main()
{

pthread_attr_t Attr;
pthread_t id;
void *stk;
size_t size;
int err;

size_t my_stksize = 0x3000000;
void *my_stack;

pthread_attr_init(&amp;Attr);

pthread_attr_getstacksize(&amp;Attr,&amp;size);
pthread_attr_getstackaddr(&amp;Attr,&amp;stk);

printf(&quot;Default: Addr=%08x default Size: %d\n&quot;,stk,size);

my_stack=(void*)malloc(my_stksize);

//printf(&quot;Default: Addr=%08x default Size: %d\n&quot;,my_stack,my_stksize);

pthread_attr_setstack(&amp;Attr,my_stack,my_stksize);

pthread_create(&amp;id,&amp;Attr,Proc,NULL);

pthread_attr_getstack(&amp;Attr,&amp;stk,&amp;size);

printf(&quot;new: Addr=%08x new Size: %d\n&quot;,stk,size);

sleep(3);

}

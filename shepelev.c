#include <stdio.h>
#include <pthread.h>

int turn = 0;
main()
{
	pthread_t f2_thread, f1_thread;
	void *f2(), *f1();
	pthread_create(&f1_thread, NULL, f1, NULL);
	pthread_create(&f2_thread, NULL, f2, NULL);
	pthread_join(f1_thread, NULL);
	pthread_join(f2_thread, NULL);
}
void *f1()
{
	while(1)
	{
		while (turn!=0);
		sleep(2);
		printf("Shepelev f1: critical_region\n");
		turn=1;
		printf("Shepelev f1: noncritical_region\n");
	}
}
void *f2()
{
	while(1)
	{
		sleep(1);
		while (turn==0);
		printf("Shepelev f2: critical_region\n");
		sleep(3);
		turn=0;
		printf("Shepelev f2: noncritical_region\n");
	}
}

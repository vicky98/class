#include <stdio.h>
#include <pthread.h>
#include <math.h>

void* hello(void* arg){
	int id = (int)arg;
	int i;
	float result = 0;
	printf("Hello from thread %d\n", id);

	for(i = 0; i < 10000; i++){
		result += sin(id);
	}

	return (void*)result;
}

int main(){
	pthread_t threads[5];

	int i;
	for(i = 0; i < 5; i++){
		pthread_create(&threads[i], NULL, hello, (void*) i);
	}

	for(i = 0; i < 10; i++){
		void* tmp;
		int result;
		pthread_join(threads[i], &tmp);
		result = (int)tmp; //in case if OS is 64 bit
		printf("result from thread %d: %d\n", i, result);
	}

	return 0;
}
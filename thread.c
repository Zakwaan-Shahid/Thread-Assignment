#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int arr[1000];

void * add(void * arg)
{
	int sum=0;
	int start =(int)arg;//from where to start
	int loopsize =start+100;//where to end
	int i;
	for(i=start;i<loopsize;i++)
	{
		sum=sum + arr[i];//specific element is added to the sum
	}
	return (void*)sum;// sum converted to generic type and returned
}


void main()
{
	int j,k,l;

	for(j=0;j<1000;j++)
		arr[j]=j;//initializing array
	
	pthread_t thread[10];// 10 threads

	void *returned[10];//pointer array

	int sum=0;//total summ

	for(k=0;k<10;k++)
		pthread_create(&thread[k],NULL,add,(void *)(k*100));//threads created. Every thread will call the function with starting of that part of array they want to sum

	pthread_join(thread[0],&returned[0]);
	pthread_join(thread[1],&returned[1]);
	pthread_join(thread[2],&returned[2]);
	pthread_join(thread[3],&returned[3]);
	pthread_join(thread[4],&returned[4]);
	pthread_join(thread[5],&returned[5]);
	pthread_join(thread[6],&returned[6]);
	pthread_join(thread[7],&returned[7]);
	pthread_join(thread[8],&returned[8]);
	pthread_join(thread[9],&returned[9]);//waiting for every thread to return sum of their part

	for(l=0;l<10;l++)
		sum=sum + (int)returned[l];// converting from generic type to the int type for addition

	printf("\nsum : %i\n",sum);// printing sum as (sum : 499500)

}


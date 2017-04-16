
#include <stdio.h>






int arr[10];
int ans[10];
void swap(int i , int j)
{
	int tmp =  arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}


int partition(int p, int q)
{

	int base = arr[q];	
	int i = p-1, j;
	for( j = p; j<q ;j++){
		if ( arr[j] < base){
			++i;
			swap(i, j);
		}
	}
	i++;
	swap(i, q);

	return i;



}



void qsort(int p, int q)
{
	if( p<q){
		int t = partition(p, q);
		qsort(t+1, q);
		qsort(p, t-1);
	}

}

int sel[10];


int func(int pos, int cnt, int sum)
{
	int i;
	if( cnt ==7){
//		printf("1111\n");
		if( sum ==100){
//			printf("222\n");
			for( int i=0;i<9 ;i++)
				if( sel[i] != 0) ans[i] = 1;
			
			return 1;
		}
		else return 0;
	}
	

	for( i = 0 ; i< 9;i++){
		if( sel[i]==0){
			sel[i] =1;
			if( func( i+1, cnt+1, sum+arr[i]) == 1 ) return 1;
			sel[i] = 0;
		}


	}
	return -1;
}

int main(void)
{
	for( int i = 0 ; i<9 ;i++)
		scanf("%d", &arr[i]);


	qsort(0, 8);
	

	func(0, 0,0);
	for( int i=0;i<9 ;i++)
		if( ans[i] != 0) printf("%d\n",arr[i]);



	return 0;
}

#include <stdio.h>



int arr[500010];
int n, m;



void swap(int i, int j)
{
	int tmp  =arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;

}


int partition(int p, int q)
{
	int base = arr[q];
	int i = p-1 , j;


	for( j = p ; j<= q ;j++)
	{
		if( arr[j] < base){
			++i;
			swap(i,j);
		}
	}

	++i;

	swap(i, q);


	return i;
}

void q_sort(int p, int q)
{
	if( p<q){
		int t = partition(p, q);
		q_sort(t+1, q);
		q_sort(p, t-1);
	}
}

int binary(int p , int q, int find)
{
	int m = (p+q)>>1;

	if( arr[m] == find)
		return 1;
	if( p>=q) return 0;


	if( arr[m] < find)
		return binary(m+1, q, find);
	else
		return binary( p, m-1,find);


	return -1;
}

int main(void)
{
	int tmp;
	scanf("%d", &n);
	for( int i = 0 ; i< n ; i++)
		scanf("%d", &arr[i]);


	q_sort(0, n-1);
	scanf("%d", &m);

	for( int i = 0 ; i < n ; i ++)
		printf(" [%d] ", arr[i]);

	for( int i = 0 ; i < m; i++)
	{
		scanf("%d", &tmp);
		printf("%d ", binary(0, n-1,tmp ) );
	}
	return 0;
}


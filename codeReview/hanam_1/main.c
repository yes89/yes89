#include <stdio.h>

int n;
int a[10001];
int b[10001];
int m;

void swap(int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int partition(int p, int q)
{
	int base = a[q];
	int i = p-1, j;
	for( j = p ; j<=q;j++)
	{
		if ( a[j] < base)
		{
			++i;
			swap(i, j);
		}
	}
	++i;
	swap(i, q);

	return i;
}

void qsort(int p, int q)
{
	if( p<q)
	{
		int t = partition(p, q);
		qsort(t+1, q);
		qsort(p, t-1);
	}
}


int bb(int p, int q, int find)
{
	
	int mid = (p + q)>>1;

	if( p<q){
		if( find > a[mid] )
		{
			return bb(mid+1, q, find);

		}
		else if( find < a[mid])
		{
			return bb(p, mid-1, find);
		}

		else
			return mid;
	}

	return p;



}

int binary(int p, int q)
{
	int i;
	int sum=0;
	int mid = (p+q)>>1;
	int index;
	
	if( p == mid && q == mid)
	{
		mid = p-1;
		q = p = mid;
	}

	index = bb(0, n-1, mid);
	if( index != 0)
		sum = b[index-1] + (n-index)*(mid);
	else
		sum = (n-index)*(mid);

	
	if (sum > m)
		binary(p,  mid);
	else if( sum < m)
	{
		if( p +1== q ||  p==q)
			return mid;
		binary(mid,  q);
	}
	else 
		return mid;
}


int main(void)
{
	int i;
	
	int sum=0;
	scanf("%d", &n);

	for ( i=0 ;i < n; i++)
	{
		scanf("%d", &a[i]);
	//	sum += a[i];
	//	b[i] = sum;
	}
	scanf("%d", &m);

	qsort(0, n-1);
	
	for ( i=0 ;i < n; i++)
	{
		sum += a[i];
		b[i] = sum;
	}

	if( sum <= m)
	{
		printf("%d", a[n-1]);
		return 0;
	}

	printf("%d", binary(a[0],a[n-1]));

	return 0;
}




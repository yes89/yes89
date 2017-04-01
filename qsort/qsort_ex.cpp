





int partition(int p, int q)
{
	int base = arr[q];
	int i = p-1 , j;
	for( j = q; j<q ;j++){
		if( arr[j] < base)
		{
			++i;
			swap(i, j);

		}
	}
	++i;
	swap(i, q);

	return i;
}








void qsort(int p , int q)
{
	if( p < q)
	{
		int t = partiton(p, q);
		qsort(p, t-1);
		qsort(t+1, q);
	}




}

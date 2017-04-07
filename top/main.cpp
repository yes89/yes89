#include <stdio.h>

int a,b,v;


int day( int aa, int bb)
{
	
	if(  (v - bb)%aa == 0)
		return (v-bb)/aa;
	
	return 0x0fffffff;

}

int night(int aa, int bb)
{
	if(  (v - bb)%aa == 0)
		return (v-bb)/aa;
	
	return 0x0fffffff;
}
int main(void)
{

	int diff;
	scanf("%d %d %d",&a,&b,&v);
	diff = a-b;
	
	int d = day (diff, a- diff);
	int n = night(diff, b-diff);
	
	if( d>n) printf("%d\n", n);
	else printf("%d\n", d);

	

	return 0;
}

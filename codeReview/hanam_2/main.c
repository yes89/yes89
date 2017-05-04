#include <stdio.h>

#define MAX_QUEUE 10000000

int n;
int a[101][101];
int check_island[101*101+1];

int visit[101][101];
int visit2[101][101];
int ans = 0x0fffffff;
int s, e;
int island_cnt ;

typedef struct POS{
	int x, y;
	int cnt;
}pos;

pos q[MAX_QUEUE];

int enq(pos in)
{
	if( e == MAX_QUEUE -1)
		return -1;

	q[e++] = in;

	return 1;
}

int deq(pos *out)
{
	if( s==e )
		return -1;

	*out = q[s++];

	return 1;
}

void init_q(void)
{
	s  = e = 0;
}


int dx[] = { 0 ,0 , 1, -1};
int dy[] = { 1 ,-1 , 0, 0};

void print_arr(void)
{
	int i,j;
	printf("\n");
	for(  i=0;i< n ;i++){
		for(  j=0; j< n ;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void find_island(int y, int x)
{
	int i;
	pos in, out;

	a[y][x] = island_cnt;
	
	in.x =  x;
	in.y =  y;

	enq(in);
	visit2[y][x] = 1;
		

	while( deq(&out) == 1){

		a[out.y][out.x] = island_cnt;

		for(  i = 0;i<4;i++)
		{
			in.x = dx[i] + out.x;
			in.y = dy[i] + out.y;

			if( in.x < 0 || in.x >= n ) continue;
			if( in.y < 0 || in.y >= n ) continue;
			if( a[in.y][in.x] == 0) continue;
				
			if( visit2[in.y][in.x] ==1 ) continue;

			enq(in);
			visit2[in.y][in.x] =1;
		} 

	}
}



void find_load(int y, int x, int ori)
{
	int check[101][101] = { 0,};
	int i;
	pos in, out;

	in.x =  x;
	in.y =  y;
	in.cnt = 0;
	enq(in);
		
	while( deq(&out) == 1){

		for(  i = 0;i<4;i++)
		{
			in.x = dx[i] + out.x;
			in.y = dy[i] + out.y;
			in.cnt = out.cnt+1;

			if( in.x < 0 || in.x >= n ) continue;
			if( in.y < 0 || in.y >= n ) continue;
			if( check[in.y][in.x] == 1 ) continue;

			if( a[in.y][in.x] != ori && a[in.y][in.x] != 0) //기존 섬이 아닌 다른 섬을 만난 경우
			{
				if( in.cnt < ans )
					ans = in.cnt;
			}
			check[in.y][in.x] = 1;
			enq(in);
		} 
	}
}


int isPossible(int y, int x)
{
	int i;
	int posible = 0 ;
	int n_x, n_y;
	if( a[y][x] == 0) return 0;

	for( i = 0 ; i < 4; i++){
		n_x = dx[i] + x;
		n_y = dy[i] + y;

		if( n_x < 0 || n_x >= n ) continue;
		if( n_y < 0 || n_y >= n ) continue;
		if( a[n_y][n_x] == 0 ) posible = 1;
	}

	if( posible == 1)
		return 1;
	return 0;
}

int main(void)
{
	int i, j;
	scanf("%d", &n);



	for(  i=0;i< n ;i++){
		for(  j=0; j< n ;j++){
			int t;
			scanf("%d", &t);
			if( t != 0)
				a[i][j] = -1;
		}
	}

	for(  i=0;i< n ;i++){
		for(  j=0; j< n ;j++){
            //  check_islkand[-1]  경우가 있다
            
			if( a[i][j] != 0 && check_island[a[i][j]] == 0) {
				init_q();
				check_island[island_cnt+1] = 1;
				island_cnt++;
				find_island(i,j);
			}
		}
	}

	for(  i=0;i< n ;i++){
		for(  j=0; j< n ;j++){
			if( isPossible(i,j) == 1)
				find_load(i,j, a[i][j] );
		}
	}

	//print_arr();
	if ( ans == 0x0fffffff)
		printf("%d\n", 0);
	else
		printf("%d\n", ans-1);



	return 0;
}
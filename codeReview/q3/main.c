
#include <stdio.h>

#define YS 1

int n;

typedef struct POS{
    int x, y;
}pos;
pos home;
pos depart[101];
pos rock;


int main(void)
{
    
    int test_case;
    int i, j;
    scanf("%d", &test_case);
    
#if YS
    printf("test_case : %d ", test_case);
#endif
    
    for( i = 0 ; i <test_case ; i++)
    {
        scanf("%d", &n );
        scanf("%d %d", &home.x, &home.y);
        home.x += 32768;
        home.y += 32768;
        
        for( j=0;j<n;j++){
            scanf("%d %d", &depart[j].x, &depart[j].y);
            depart[j].x += 32768;
            depart[j].y += 32768;
        }
        scanf("%d %d", &rock.x, &rock.y);
        rock.y += 32768;
        rock.x += 32768;
    }
    
    
    
    
    return 0;
    
}
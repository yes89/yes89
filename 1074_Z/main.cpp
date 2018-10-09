
//1074 Z

#include <iostream>
#include <math.h>

using namespace std;

int N, r, c;

int findWhichSide(int size)
{
    if (size == 2) return -1;

    int half = size/2;

    if( r < half && c < half) return 0;
    else if( r < half && c >= half) return half*half;
    else if( r >= half && c < half) return size*half;
        
    return half*half + half*size;
}

int whereIs()
{
    if( r%2 ==0 && c%2 == 0) return 0;
    else if( r%2 ==0 && c%2 == 1) return 1;
    else if( r%2 ==1 && c%2 == 0) return 2;

    return 3;   
    
}

int main(void)
{
    //cin>>N>>r>>c;
    int starting = 0;
    int arrSize;// = pow(2,N);
    int tmp;

    while(cin >> N >> r >> c)
    {
        arrSize = pow(2,N);
        starting = 0;


        if( N == 1)
        {
            // arr size가 2인 경우 처리할 것   
            cout<< whereIs() <<endl;
            
        }
        else 
        { 
            while(1)
            {
                tmp = findWhichSide(arrSize);
                starting = tmp + starting;
                arrSize /= 2;
                //cout<<"which : "<<starting<<endl;
                if( arrSize == 2)
                {
                    tmp = whereIs();
                    starting = tmp + starting;
                    cout<< starting <<endl;
                    break;
                }
            }
        }
    }

    return 0;
}
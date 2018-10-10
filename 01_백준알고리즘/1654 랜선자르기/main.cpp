
//1654 랜선자르기


#include <iostream>
#include <vector>

using namespace std;

long long k,n, Min = 0xffffff, Max = 0;
vector<long long> v;


long long getCnt(long long m)
{
    long long ret=0, tmp;

    for( int i=0;i<k;i++)
    {
        tmp = v[i]/m;
        ret += tmp;
    }

    return ret;
}
long long ans;
void bserch(long long s, long long e)
{
    //cout<<getCnt(e)<<endl;
    long long tmp, m = (s+e)/2;
    tmp = getCnt(m);

    cout<<"s:"<<s<< "   m:"<<m<<"  e:"<<e<<"   cnt:"<<tmp<<endl;
    if( tmp >= n) // >= 이게 핵심
        ans = m;
    if( s>=e)
        return ;

    if( tmp < n)
     bserch(s, m);
    else 
     bserch(m+1, e);

}

int main(void)
{
    long long tmp;
    cin>>k>>n;
    //scanf("%lld %lld")

    for( int i = 0 ; i<k;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
        if( tmp > Max)
            Max = tmp;
    }
   
    bserch(1,Max);

    cout<<ans<<endl;
    
}
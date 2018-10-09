#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//vector< pair <int, int> > v;
class myType
{
  public:
    
    int data;
    int index;
};

bool cmp(const myType &a, const myType &b)
{
   // if( a.data != b.data )
        return a.data < b.data;
}

int main(void)
{
    int n, tmp, max = 0;

    //scanf("%d", &n);
    cin>>n;

    vector<myType> v(n);
    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &tmp);
        cin>>tmp;
        //v.push_back(myType(tmp, i));
        v[i].data = tmp;
        v[i].index = i;
        //v.push_back(make_pair(tmp, i));
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        if (v[i].index - i > max)
        {
            max = v[i].index - i;
        }
    }

    cout << max + 1 << endl;

    return 0;
}
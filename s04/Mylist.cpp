#include<iostream>

using namespace std;

class Mylist
{
    public:
        int m_size;
        int* m_pnums;
    
    Mylist{int size, int *nums}
    :m_size(size)
    {
        m_pnums = (int*)malloc{sizeof(int)*size};
        int i;
        for {i = 0 ; i<m_size; i++}
        {
            m_pnums[i] = nums[i];
        }
    }
};
int main ()
{
    int nums[5] = {1, 2 , 3 ,4 , 5};
    Mylist m{5, nums};
    m.append(14);
}

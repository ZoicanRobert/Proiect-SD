#include <vector>

namespace quicksort
{
    void sortare(std::vector<int> &v, int st, int dr)
    {
        int pivot = v[(st + dr) / 2];
        int x = 0;

        int i = st, j = dr;
        while(i <= j)
        {
            while(v[i] < pivot)
                ++i;
            while(v[j] > pivot)
                --j;
            if(i <= j)
            {
                x = v[i];
                v[i] = v[j];
                v[j] = x;
                ++i;
                --j;
            }
        }
        if(st < j)
            sortare(v, st, j);
        if(i < dr)
            sortare(v, i, dr);
    }
    void Sort(std::vector<int> &v)
    {
        sortare(v, 0, v.size() - 1);
    }
}

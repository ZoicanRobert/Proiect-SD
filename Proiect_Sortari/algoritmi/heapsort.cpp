#include <vector>

namespace heapsort
{
    void Comb_Heap(std::vector<int> &v, int ind, int sz)
    {
        int st;
        int dr;
        int urmatorul;
        while(2 * ind < sz)
        {
            st = 2 * ind;
            dr = st + 1;
            if(dr >= sz || v[st] > v[dr])
                urmatorul = st;
            else
                urmatorul = dr;
            if(v[ind] < v[urmatorul])
                std::swap(v[ind], v[urmatorul]), std::swap(ind, urmatorul);
            else
                break;
        }
    }

    void Make_Heap(std::vector<int> &v)
    {
        for(int i = v.size() / 2; i >= 0; --i)
            Comb_Heap(v, i, v.size());
    }

    inline void StergeMax(std::vector<int> &v, int sz)
    {
        std::swap(v[0], v[sz-1]);
        Comb_Heap(v, 0, sz - 1);
    }

    void Sort(std::vector<int> &v)
    {
        Make_Heap(v);
        int mx;
        for(int i = v.size()-1; i > 0; --i)
        {
            mx = v[0];
            StergeMax(v, i);
            v[i] = mx;
        }
    }
}

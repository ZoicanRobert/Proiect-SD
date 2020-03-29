#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <chrono>

#include "algoritmi/stlsort.cpp"
#include "algoritmi/quicksort.cpp"
#include "algoritmi/mergesort.cpp"
#include "algoritmi/heapsort.cpp"
#include "algoritmi/radixsort.cpp"

using namespace std;

void test_function(function<void(vector<int>&)> f, vector<int> v)
{
    auto start = chrono::high_resolution_clock::now();
    f(v);
    auto stop = chrono::high_resolution_clock::now();
    assert(is_sorted(v.begin(), v.end()));

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "a durat: " << duration.count() << " milisecunde\n";
}

int main()
{
    ifstream in("data.in");
    int teste;
    in >> teste;
    while(teste--)
    {
        string type;
        int n, val_max;
        in >> n >> val_max >> type;
        cout << "Numere: " << n << "\n";
        cout << "Valoare maxima: " << val_max << "\n";
        cout << "Tipul vectorului: " << type << "\n";

        vector<int> v(n);
        for(int &x:v)
            in >> x;

        cout << "STL_sort: ";
        test_function(stlsort::Sort, v);
        cout << "Quick_sort: ";
        test_function(quicksort::Sort, v);
        cout << "Merge_sort: ";
        test_function(mergesort::Sort, v);
        cout << "Heap_sort: ";
        test_function(heapsort::Sort, v);
        cout << "Radix_sort: ";
        test_function(radixsort::Sort, v);

    }
    return 0;
}

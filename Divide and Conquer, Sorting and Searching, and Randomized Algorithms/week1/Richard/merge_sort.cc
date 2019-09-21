#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include <vector>

template <typename T>
bool if_sorted(const std::vector<T> input)
{
    if(input.size()==1)
    {
        return true;
    }
    for(int i=0; i<input.size()-1; i++)
    {
        if(input[i]>input[i+1])
            return false;
    }   
    return true;
}

template <typename T>
std::vector<T> merge(std::vector<T> a, std::vector<T> b)
{
    int i=0;
    int j=0;
    int n = a.size() + b.size();
    std::vector<T> c(n,0);
    for (int k=0; k<n; k++)
    {
        if(a[i]<b[j] && (i<a.size() && j<b.size()))
        {
            c[k] = a[i];
            i++;
        } 
        else if (a[i]>=b[j] && (i<a.size() && j<b.size()))
        {
            c[k] = b[j];
            j++;
        } 
        else if (i==a.size())
        { 
            c[k] = b[j];
            j++;
        } 
        else if (j==b.size())
        {
            c[k] = a[i];
            i++;
        }
    }
    return c;
}

template <typename T>
std::vector<T> merge_sort(std::vector<T> input)
{
    int n = input.size();
    std::vector<T> c(n,0);
    std::vector<T> a;
    std::vector<T> b;

    // return if sorted ----> base case
    if (if_sorted(input))
    {
        return input;
    }

    // split input into 2 arrays
    for (int m=0; m<n/2; m++)
    {
        a.push_back(input[m]);
    }
    for (int m=n/2; m<n; m++)
    {
        b.push_back(input[m]);
    }
    
    // if not sorted, call itself
    if (!if_sorted(a))
    {
        a = merge_sort(a);
    }
    if (!if_sorted(b))
    {
        b = merge_sort(b);
    }

    // merge 2 sorted array 
    c = merge(a,b);  

    return c;
}

int main()
{
    std::vector<double> v(1000);
    // generate random numbers
    std::generate(v.begin(), v.end(), std::rand);
    for (auto &i:v)
    {
        i=i/100000;
    }
    std::vector<double> input = {3.2,1,4,50,9.9,9.8,6,5};
    std::vector<double> output = merge_sort<double>(v);
    for(auto i:output)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // std::vector<int> test={2,6,3};
    // std::cout << if_sorted(test) << std::endl;
}

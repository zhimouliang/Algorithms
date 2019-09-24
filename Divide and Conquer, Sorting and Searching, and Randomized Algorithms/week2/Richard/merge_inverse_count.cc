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
std::vector<T> merge_count_inverse(std::vector<T> a, std::vector<T> b, int &invert_count)
{
    int i=0;
    int j=0;
    int n = a.size() + b.size();
    std::vector<T> c(n,0);
    for (int k=0; k<n; k++)
    {
        if(a[i]<b[j] && (i<a.size() && j<b.size())) // put element in a into c
        {
            c[k] = a[i];
            i++;
        } 
        else if (a[i]>=b[j] && (i<a.size() && j<b.size())) // put element in b into c
        {
            c[k] = b[j];
            invert_count = invert_count + (a.size()-i);
            j++;
        } 
        else if (i==a.size()) // if there's nothing left in a, put b into c
        { 
            c[k] = b[j];
            j++;
        } 
        else if (j==b.size()) // if there's nothing left in a, put a into c
        {
            c[k] = a[i];
            i++;
        }
    }
    return c;
}

template <typename T>
std::vector<T> merge_sort_invert_count(std::vector<T> input, int & invert_count)
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
        a = merge_sort_invert_count(a, invert_count);
    }
    if (!if_sorted(b))
    {
        b = merge_sort_invert_count(b, invert_count);
    }

    // merge_count_inverse 2 sorted array 
    c = merge_count_inverse(a, b, invert_count);  

    return c;
}

int main()
{
    std::vector<double> v(1000);
    int invert_count = 0;
    // generate random numbers
    std::generate(v.begin(), v.end(), std::rand);
    for (auto &i:v)
    {
        i=i/100000;
    }
    std::vector<double> input1 = {3.2,1,4,50,9.9,9.8,6,5};
    std::vector<double> input2 = {1,3,5,2,4,6};
    std::vector<double> output = merge_sort_invert_count<double>(input1, invert_count);
    for(auto i:output)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "invert count: " << invert_count << std::endl;
    // std::vector<int> test={2,6,3};
    // std::cout << if_sorted(test) << std::endl;
}

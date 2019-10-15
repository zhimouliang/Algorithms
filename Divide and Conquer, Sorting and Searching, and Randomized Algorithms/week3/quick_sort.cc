#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unistd.h>
#include <algorithm>

int choose_pivot(const int l_index, const int r_index)
{
  if (r_index<l_index)
  {
    std::cout << "wrong input of choose_pivot" << std::endl;
  }
  return l_index + rand()%(r_index-l_index+1);
}

template <typename T>
std::vector<T> swap(std::vector<T> array, int a_index, int b_index)
{
  T temp = array[a_index];
  array[a_index] = array[b_index];
  array[b_index] = temp;
  // std::cout << "swap operation" << std::endl;
  return array;
}

template <typename T>
std::vector<T> partition(std::vector<T> array, int l_index, int r_index, int &pivot_index)
{
  // std::cout << "partition operation" << std::endl;
  array = swap<T>(array, l_index, pivot_index);
  int i = l_index + 1;
  int j = 0;

  for (j=l_index+1; j<=r_index; j++)
  {
    if(array[j]<array[l_index])
    {
      array = swap<T>(array, j, i);
      i++;
    }
  }
  array = swap<T>(array, l_index, i-1);
  pivot_index = i-1;
  return array;
}

template <typename T>
std::vector<T> quick_sort(std::vector<T> array, int l_index, int r_index)
{
  int len = r_index-l_index; // lenght of this sub-array
  // base case --- return if there is only one element in the subarray
  if (len==0)
  {
    std::cout << "base case -- return" << std::endl;
    return array;
  }

  int pivot_index = choose_pivot(l_index, r_index);
  array = partition<T>(array, l_index, r_index, pivot_index);

  // call quick_sort subroutine when there is at least one element in the array
  if (l_index < pivot_index-1)
  {
    array = quick_sort(array, l_index, pivot_index-1);
  }
  if (pivot_index+1 < r_index)
  {
    array = quick_sort(array, pivot_index+1, r_index);
  }
  return array; // implicitly state that return when there is only one element --- base case
}

int main()
{
  srand(time(0));

  std::vector<double> v(1000);
    // generate random numbers
  std::generate(v.begin(), v.end(), std::rand);
  for (auto &i:v)
  {
      i=i/100000;
  }

  // for (int i=1; i<10; i++)
  // {
  //   std::cout << choose_pivot(2,5) << std::endl;
  // }
  std::vector<double> input = {8,2,4,2,3,1,2,4,12};
  // int pivot_temp=1;
  // std::vector<double> output = partition(input,0,7,pivot_temp);

  // for (int i=1; i<50; i++)
  // {
    std::vector<double> output = quick_sort(v,0,v.size()-1);
    std::cout << "result: ";
    for (auto i:output)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  // }

  // std::cout << "pivot: " << pivot_temp << std::endl;
  return 0;
}

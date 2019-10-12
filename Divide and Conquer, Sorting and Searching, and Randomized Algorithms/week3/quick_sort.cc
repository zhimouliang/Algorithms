#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unistd.h>

int choose_pivot(const int range)
{
  return rand()%range;
}

template <typename T>
std::vector<T> swap(std::vector<T> array, int a_index, int b_index)
{
  T temp = array[a_index];
  array[a_index] = array[b_index];
  array[b_index] = temp;
  return array;
}

template <typename T>
std::vector<T> partition(std::vector<T> array, int l_index, int r_index, int &pivot_index)
{
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
  int len = r_index-l_index;
  usleep(100000);
  // std::cout << "length of array is " << len << std::endl;
  std::cout << "l_index: " << l_index << "\tr_index: " << r_index << std::endl;
  // base case
  if (r_index==l_index)
  {
    return array;
  }

  int pivot_index = choose_pivot(len);
  array = partition<T>(array, l_index, r_index, pivot_index);

  for (auto i:array)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "pivot: " << pivot_index << std::endl;
  if (l_index<=pivot_index-1)
  {
    array = quick_sort(array, l_index, pivot_index-1);
  }
  if (pivot_index+1<=r_index)
  {
    array = quick_sort(array, pivot_index+1, r_index);
  }

}

int main()
{
  srand(time(0));
  // for (int i=1; i<10; i++)
  // {
  //   std::cout << choose_pivot(10) << std::endl;
  // }
  std::vector<double> input = {1,7,8,2,4,5,6,3};
  int pivot_temp=1;
  // std::vector<double> output = partition(input,0,7,pivot_temp);

  std::vector<double> output = quick_sort(input,0,7);
  for (auto i:output)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "pivot: " << pivot_temp << std::endl;
  return 0;
}

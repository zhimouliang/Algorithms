#include <iostream>
#include <vector>
#include<cmath>

unsigned long long int num_of_digit(unsigned long long int digit)
{
    unsigned long long int num = 0;
    if(digit < 0)
    {
        digit = digit * -1;
    }
    else if(digit == 0)
    {
        digit = 1;
    }
    while(digit > 0)
    {
        digit = digit/10;
        num++;
    }
    return num;
}

// assume we multiply two numbers with same and even num of digits 
unsigned long long int kara_mult(unsigned long long int num1, unsigned long long int num2)
{
    int n = num_of_digit(num1);
    // return if both are only one digit --> base case 
    if (n==1) 
    {
        return num1*num2;
    } 

    // split both number to half
    unsigned long long int a = num1/(std::pow(10, 0.5*n)); // left half of num1
    unsigned long long int b = num1 - a*(std::pow(10, 0.5*n)); // right halt of num1
    unsigned long long int c = num2/(std::pow(10, 0.5*n));
    unsigned long long int d = num2 - c*(std::pow(10, 0.5*n));

    unsigned long long int ac = kara_mult(a, c);
    unsigned long long int bd = kara_mult(b, d);
    unsigned long long int add_term = kara_mult((a+b), (c+d)) - ac - bd; // this is ad+bc
    
    // unsigned long long int mult = std::pow(10, n)*ac + std::pow(10, n/2)*add_term + bd;

    return std::pow(10, n)*ac + std::pow(10, n/2)*add_term + bd;
}

int main()
{
    unsigned long long int a = 25;
    unsigned long long int b = 25;
    unsigned long long int result = kara_mult(a,b);
    std::cout << result << std::endl;
}
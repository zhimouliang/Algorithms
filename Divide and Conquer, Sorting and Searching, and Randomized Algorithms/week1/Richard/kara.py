from pylab import *

def num_of_digit(digit):
    num = 0
    if digit < 0:
        digit = -1 * digit
    elif digit == 0: 
        num = 1
    while digit > 0:
        digit = digit/10
        num = num + 1
    return num

def kara_mult(num1, num2):
    n = num_of_digit(int(num1))
    # return if both are only one digit --> base case
    if n==1: 
        return num1*num2

    # split both number to half
    a = int(floor(num1/(10**(0.5*n)))) # left half of num1
    b = int(floor(num1 - a*(10**(0.5*n)))) # right halt of num1
    c = int(floor(num2/(10**(0.5*n))))
    d = int(floor(num2 - c*(10**(0.5*n))))

    # print "a:", a
    # print "b:", b
    # print "c:", c
    # print "d:", d

    # print "(10**0.5*n): ", (10**(0.5*n))
    # print "n: ", n

    ac = kara_mult(a, c)
    bd = kara_mult(b, d)
    add_term = kara_mult((a+b), (c+d)) - ac - bd # this is ad+bc

    # print "ac: ", ac
    # print "bd: ", bd
    # print "add_term: ", add_term

    mult = (10**n)*ac + (10**(n/2))*add_term + bd

    return mult

print kara_mult(3141592653589793238462643383279502884197169399375105820974944592,
2718281828459045235360287471352662497757247093699959574966967627)
# print kara_mult(1234,5678)



    

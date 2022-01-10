"""This program searches and prints out the perfect numbers
between 1 and 'n', where 'n' is user-specified."""

import math


def getPerfectNumbers(low, high):
    """Takes in a low and high value and finds out perfect numbers in that range"""
    if low <= 1:
        low = 2
    if high <= 0 or high <= low:
        print("Invalid range. Exiting...")
        exit()
    list = []
    for number in range(low, high + 1, 1):
        if isPerfect(number):
            list.append(number)
    return list


def isPerfect(number):
    """Takes in a number and checks if it is perfect number or not"""
    factors = []
    for factor in range(1, math.floor(math.sqrt(number)) + 1, 1):
        if number % factor == 0:
            factors.append(factor)
            factors.append(number / factor)
    if 2 * number == sum(factors):
        return True
    return False


def main():
    n = int(input("Enter the upper range for perfect numbers: "))
    perfectNumbers = getPerfectNumbers(1, n)
    print(f"The Perfect numbers in the given range are: {perfectNumbers}")


if __name__ == '__main__':
    main()

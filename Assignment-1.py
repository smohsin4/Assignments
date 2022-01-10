"""This program counts the number of digits in user-entered integer"""


def getDigitCount(number):
    """Takes in a number and returns the number of digits in that number"""
    count = 0
    while number != 0:
        number = int(number / 10)
        count += 1
    return count


def main():
    n = int(input("Enter an integer: "))
    if n < 0:
        n *= -1
    print(getDigitCount(n))


if __name__ == '__main__':
    main()

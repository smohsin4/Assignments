"""This program calculates the occurences of digits from 0 to 9 and prints them"""


def getOccurrences(number):
    """Takes in a number and returns a dictionary with occurrences of digits 0-9"""
    dict = {}
    for i in range(0, 10):
        dict[str(i)] = 0
    numberString = str(number)
    for digit in numberString:
        if not digit.isnumeric():
            continue
        val = dict.get(digit) + 1
        dict[digit] = val
    return dict


def main():
    number = str(input("Enter a string: "))
    frequency = getOccurrences(number)

    for i in range(0, 10, 1):
        print(f"Occurrence({i}): {frequency[str(i)]}")


if __name__ == '__main__':
    main()

"""This program converts user-entered integer value to its appropriate wordings, in US styling."""


powersOfThousand = ['', 'thousand', 'million', 'billion', 'trillion', 'quadrillion', 'quintillion', 'hextillion',
                    'septillion', 'octillion', 'nonillion', 'decillion', 'undecillion', 'duodecillion', 'tredecillion',
                    'quattuordecillion', 'quindecillion', 'hexdecillion', 'septendecillion', 'octodecillion',
                    'novemdecillion', 'vigintillion', 'unvigintillion', 'duovigintillion', 'trevigintillion',
                    'quattourvigintillion', 'quinvigintillion', 'hexvigintillion', 'septenvigintillion',
                    'octovigintillion', 'novemvigintillion', 'trigintillion', 'untrigintillion', 'duotrigintillion']

dictNumbers = {
    "0": "zero",
    "1": "one",
    "2": "two",
    "3": "three",
    "4": "four",
    "5": "five",
    "6": "six",
    "7": "seven",
    "8": "eight",
    "9": "nine",
    "10": "ten",
    "11": "eleven",
    "12": "twelve",
    "13": "thirteen",
    "14": "fourteen",
    "15": "fifteen",
    "16": "sixteen",
    "17": "seventeen",
    "18": "eighteen",
    "19": "ninteen",
    "20": "twenty",
    "30": "thirty",
    "40": "forty",
    "50": "fifty",
    "60": "sixty",
    "70": "seventy",
    "80": "eighty",
    "90": "ninty",
    "100": "hundred"
}


def getWord(num):
    """Takes in a number less than 1000 and converts it into words"""
    word = ""
    hundred = int(num / 100)
    tens = int((num / 10) % 10)
    units = int(num % 10)
    if hundred != 0:
        word += str(dictNumbers[str(hundred)])
        word += " hundred "

    if tens == 1:
        num = tens * 10 + units
        word += str(dictNumbers[str(num)]) + " "
        #print(word)
        return word

    if tens != 0:
        word += str(dictNumbers[str(tens * 10)]) + " "

    if units != 0:
        word += str(dictNumbers[str(units)]) + " "
    #print(word)

    return word


def numberToWord(num):
    """Takes in a number and converts it into words"""
    word = ""
    if num < 0:
        word += "Minus "
        num *= -1
    numString = str(num)
    list = []
    length = len(numString)
    if length % 3 != 0:
        list.append(int(numString[0: length % 3]))
    for i in range(length % 3, length, 3):
        list.append(int(numString[i: i + 3]))
    #print(list)

    for i in range(0, len(list), 1):
        word += getWord(list[i])
        word += powersOfThousand[len(list) - i - 1] + " "
    return word


def main():
    number = int(input("Enter a number: "))
    if len(str(number)) > 99:
        print("Number out of bounds")
        exit(1)
    wording = numberToWord(number)
    wording = wording.capitalize()
    print(wording)


if __name__ == '__main__':
    main()

"""Program to calculate frequency of a given word in a string"""


def getFrequency(str, word):
    """Takes in a string and a word and returns the frequency of that word in string"""
    symbols = ['!', '(', ')', ',', '.']
    for symbol in symbols:
        str = str.replace(symbol, '')

    dict = {
        word: 0
    }

    str_split = str.split(" ")

    for s in str_split:
        if s == word:
            value = dict[word]
            dict[word] = value + 1

    return dict[word]


def main():
    str = input("Enter a string: ")
    word = input("Enter word to search: ")
    frequency = getFrequency(str, word)
    print(frequency)


if __name__ == '__main__':
    main()

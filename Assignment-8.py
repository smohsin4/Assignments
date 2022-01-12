"""Program to calculate frequency of a given word in a string"""


def getFrequency(str):
    """Takes in a string and a word and returns the frequency of that word in string"""
    symbols = ['!', '(', ')', ',', '.']
    for symbol in symbols:
        str = str.replace(symbol, '')

    str_split = str.split(" ")
    str_set = set(str_split)

    for s in str_set:
        dict = {
            s: 0
        }

    for s in str_set:
        count = 0
        for word in str_split:
            if (s == word):
                count = count + 1
        dict[s] = count

    return dict


def main():
    str = input("Enter a string: ")
    while True:
        word = input("Enter word to search(quit() to quit): ")
        if(word == "quit"):
            print("Exiting...")
            exit(1)
        str_dict = getFrequency(str)
        print(f"Frequency of {word} is : {str_dict[word]}")


if __name__ == '__main__':
    main()

# TODO

def main():
    text = input('Text: ')
    letters, words, sentences = analyze(text)
    L = letters / words
    S = sentences / words

    index = 0.0588 * L * 100 - 0.296 * S * 100 - 15.8

    if index < 1:
        print('Before Grade 1')
    elif index > 16:
        print('Grade 16+')
    else:
        print(f'{index}')
        print(f'Grade {round(index)}')


def analyze(text):
    letters_count = 0
    words_count = 0
    sentences_count = 0

    for i in range(len(text)):
        if text[i].isalpha():
            letters_count += 1
        elif text[i] == ' ':
            words_count += 1
        elif text[i] == '.' or text[i] == '?' or text[i] == '!':
            sentences_count += 1

    return letters_count, words_count, sentences_count

if __name__ == '__main__':
        main()
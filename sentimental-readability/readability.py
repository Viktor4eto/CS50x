# TODO

def main():
    text = input('Text: ')
    letters, words, sentences = analyze(text)
    L = letters / words
    S = sentences / words


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


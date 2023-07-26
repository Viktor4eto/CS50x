

def main():
    card = int(input('Number: '))

    if legit(card):
        if card / 10 ** 13 == 34 or card / 10 ** 13 == 37:
            print('AMEX')
        else if card / 10 ** 14
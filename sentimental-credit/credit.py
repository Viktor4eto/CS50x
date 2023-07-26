import math

def legit(card):
    


def main():
    card = int(input('Number: '))


    if legit(card):
        if card // 10**13 in (34, 37):
            print('AMEX')
        elif card // 10**14 in (51, 52, 53, 54, 55):
            print('MASTERCARD')
        elif card // 10**12 == 4 or card // 10**15 == 4:
            print('VISA)
        else:
            print('INVALID')
    else:
        print('INVALID')
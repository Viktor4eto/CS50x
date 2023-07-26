import math

def main():
    card = int(input('Number: '))


    if legit(card):
        testVals = []
        testVals[0] = math.floor(card / 10**13)
        testVals[1] = math.floor(card / 10**14)
        testVals[2] = math.floor(card / 10**12)
        testVals[3] = math.floor(card / 10**15)

        if set([34, 37]).intersection(testVals):
            print('AMEX')
        elif set([51, 52, 53, 54, 55]).intersection(testVals):
            print('MASTERCARD')
        elif 4 in testVals:
            print('VISA)
        else:
            print('INVALID')
    else:
        print('INVALID')
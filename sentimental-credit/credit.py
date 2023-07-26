import math

def main():
    card = int(input('Number: '))


    if legit(card):
        testVals = []
        testVals[0] = math.floor(card / 10**13)
        testVals[1] = math.floor(card / 10**14)
        testVals[2] = math.floor(card / 10**12)
        testVals[3] = math.floor(card / 10**15)

        if 34 in testVals or 37 in testVals:
            print('AMEX')
        else if 51 in testVals or 
import math

# Finds the length of the card number
def len(card):
    count = 1
    while card > 10:
        count += 1
        card //= 10
    return count


def legit(card):
    check = False
    sum = 0

    while card > 0:
        if not check:
            sum += card % 10
            check = True
            card //= 10
        else:
            digit = (card % 10)

            if digit >= 5:
                double_digit  = digit * 2
                sum += double_digit % 10 + double_digit // 10
            else:
                sum += digit*2

            card //= 10
            check = False

        print(f'{sum} and {card} and {check}')

    return sum % 10 == 0


def main():
    card = int(input('Number: '))


    if legit(card):
        if card // 10**13 in (34, 37):
            print('AMEX')
        elif card // 10**14 in (51, 52, 53, 54, 55):
            print('MASTERCARD')
        elif card // 10**12 == 4 or card // 10**15 == 4:
            print('VISA')
        else:
            print('Legit works')
            print('INVALID')
    else:
        print('Here')
        print('INVALID')


#if __name__ == '__name__':
main()
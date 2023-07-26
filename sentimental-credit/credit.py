import math

# Finds if the card is real


def legit(card):
    check = False
    sum = 0

    # While-Loop for the length of the card number that gives the sum of the digits
    while card > 0:
        # Uses chekc to determine which operation to add to sum
        if not check:
            sum += card % 10
            check = True

        else:
            digit = (card % 10)

            if digit >= 5:
                double_digit = digit * 2
                sum += double_digit % 10 + double_digit // 10
            else:
                sum += digit*2

            check = False

        # Decrements card
        card //= 10
        # print(f'{sum} and {card} and {check}')

    return sum % 10 == 0


def main():
    card = int(input('Number: '))

    # If the car is real. it checks the possible combinations
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


if __name__ == '__main__':
    main()
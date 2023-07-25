from cs50 import get_int

while True:
    h = get_int("Height: ")

    if h < 9 and h > 0:
        break


for i in range(h+1):
    print(' ' * (h - i) + '#' * i + '  ' + '#' * i + ' ' * (h -i))


from cs50 import get_int

# Handles user input
while True:
    h = get_int("Height: ")

    if h < 9 and h > 0:
        break

# Prints out the pyramids
for i in range(1, h+1):
    print(' ' * (h - i) + '#' * i + '  ' + '#' * i)


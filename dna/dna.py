import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print('Usage: python dna.py data.csv sequence.txt')
        sys.exit()

    data_file = sys.argv[1]
    sequence_file = sys.argv[2]

    # TODO: Read database file into a variable

    database = []
    with open(data_file) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # print(database)

    for i in database:
        for name in i:
            try:
                i[name] = int(i[name])
            except ValueError:
                pass

    # TODO: Read DNA sequence file into a variable

    with open(sequence_file) as file:
        sequence = file.read()

    # print(sequence)
    longest = {}
    # print(len(database[0]))
    # TODO: Find longest match of each STR in DNA sequence
    for i in database[0]:
        longest[i] = longest_match(sequence, i)

    # print(longest)
    # print()
    # for i in range(1, database[0]):
        # longest_of_each[name] = longest_match(sequence, database[0])

    # TODO: Check database for matching profiles
    for dictionary in database:
        longest['name'] = dictionary['name']
        # print(longest)
        # print(dictionary)
        # print(dictionary == longest)
        if dictionary == longest:
            person = longest['name']

    try:
        print(person)
    except UnboundLocalError:
        print('No Match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv)!=3:
        print("Missing command line arguments")

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as f_dna:
            dna = list(csv.reader(f_dna))


    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as f_person:
            seq = f_person.read()

    # TODO: Find longest match of each STR in DNA sequence
    database = dict()

    col = len(dna[0])
    row = len(dna)
    for i in range(1,col):
         database[dna[0][i]]=longest_match(seq,dna[0][i])

    # TODO: Check database for matching profiles
    for i in range(1,row):
         for j in range(1,col):
              if int(dna[i][j]) != database[dna[0][j]]:
                    break
         else:
              return dna[i][0]
    return "No match found"


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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


result=main()
print(result)

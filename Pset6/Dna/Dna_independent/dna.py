import csv
import sys


def main():

     if len(sys.argv) != 3:
           print("Missing command line arguments")
           sys.exit(1)



     try:
             with open(sys.argv[1]) as f_dna:
                     read =list(csv.reader(f_dna))

             with open(sys.argv[2]) as f_person:
                     data = f_person.read()
     except FileNotFoundError:
             print("File does not exist")
             sys.exit(1)



     dna = dict()

     for person in read:
                for seq in person:
                      if check(seq):
                              dna[seq] = count(data,seq)
                break
     length_row = len(read[0])

     for person in range(1,len(read)):
            for seq in range(1,length_row):
                            if int(read[person][seq]) != dna[read[0][seq]]:
                                     break
            else:
                      print(read[person][0])
                      sys.exit(0)
     print("No match found")
     sys.exit(1)

def count(data,sequence):
      value = 0
      short_tandem_repeats = []
      continous = False
      length_data = len(data)
      length_seq = len(sequence)
      i=0
      while i<len(data):
              sub = ""
              for j in range(length_seq):
                         if (i+j)<length_data:
                                sub+=data[i+j]
              if sub == sequence:
                                  value+=1
                                  i+=length_seq

              else:
                     if value > 0:
                            short_tandem_repeats.append(value)

                     value = 0
                     i+=1

      if len(short_tandem_repeats)==0:
              return 0

      return max(short_tandem_repeats)



def check(sequence):
      for i in sequence:
            if i not in 'ATGC':
                  return False
      return True


main()

























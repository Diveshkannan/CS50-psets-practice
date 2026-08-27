from sys import exit


def main():

        text = input("Text: ")
        length = len(text)
        if length == 0:
              print("We need text to grade !!!")
              exit(1)

        letters = 0
        words = 0
        sentences = 0

        for i in range(length):
               if text[i].isalpha():
                   letters += 1
               if (i > 0) and (text[i] == " " and text[i-1].isalpha()):
                   words += 1
               if (i > 0) and ((text[i] == "." or text[i] == "?" or text[i] == "!") and text[i-1].isalpha()):
                   sentences += 1
                   words += 1
        index = coleman(letters,words,sentences)
        if index >=16 :
             print("Grade 16+")
        elif index < 1:
             print("Grade less than 1")
        else:
             print("Grade ",index)



def coleman(l, w, s):
    L = (l/w)*100
    S = (s/w)*100
    index = round( 0.0588 * L - 0.296 * S - 15.8)
    return index

main()
exit(0)

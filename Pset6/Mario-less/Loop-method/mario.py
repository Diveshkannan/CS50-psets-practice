while True:
    try:
           height = int(input("Height: "))

    except ValueError:
        print("Only integers.")

    else:
        if  1<height<8 :
            print("Height: ",height)
            break
for i in range(height):
     for j in range (height-i-1):
          print(" ",end="")
     for l in range(i+1):
          print("#",end="")
     print()









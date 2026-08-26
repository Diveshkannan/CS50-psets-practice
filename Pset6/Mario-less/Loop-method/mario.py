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
     print(" "*(height-i-1),end="")
     print("#"*(i+1))



import sys

number=None
while True:
      number = input("Number: ")
      if len(number)==0:
            print("Number must be entered!")
            continue

      if number.isnumeric():
            break
card = int(number)
add = 0
product = 0
count = 1
valid = False
while (card > 0):
      if count%2 == 0:
            temp = 2*(card % 10)
            while (temp > 0):
                  product+=temp%10
                  temp=temp//10
      else:
            add+=card%10
      count+=1
      card=card//10
sum=add+product
if sum%10==0:
     valid = True

if not valid:
      print("INVALID")
      sys.exit(1)
#count already done the work of the length
length=count-1
if ((length == 15) and ((int(number[0]+number[1])==34) or ((int(number[0]+number[1])==37)))):
      print("AMEX")
elif ((length==13 or length==16) and (int(number[0])==4)):
      print("VISA")
elif ((length==16) and (51<=int((number[0]+number[1]))<=55)):
      print("MASTERCARD")
else:
      print("No card matched")
      sys.exit(1)
sys.exit(0)







dollars = 0
cents = 0
coins = 0
while True:
    try:
        dollars = float(input("Change owed: "))
    except ValueError:
        print("Only floats.")

    else:
        cents = int(dollars*100)
        if cents >=0:
            break

quarters = cents//25
coins+=quarters
cents-=(25*quarters)

dimes = cents//10
coins+=dimes
cents-=(10*dimes)

nickels = cents//5
coins+=nickels
cents-=(5*nickels)

pennies = cents//1
coins+=pennies
cents-=(1*pennies)

print(coins)








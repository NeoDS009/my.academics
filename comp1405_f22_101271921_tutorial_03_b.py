# Deneo Shi 101271921

# Creating a variable that stores a new line
new_line = '_' * 100

## Welcome notes and asking which profession the user wants to be (storing it in a variable)
print("Welcome, dear traveler! The trail welcomes you with its open arms! Listed below are the professions you could choose to be: \n  1. Banker \n  2. Carpenter \n  3. Farmer")
profession = int(input("What is the designated number of the profession you would like to choose? "))

## Setting a total balance for each profession
if profession == 1:
    total = 3000
elif profession == 2:
    total = 2000
elif profession == 3:
    total = 1000
    

## Visiting the store and giving 4 item choices (storing the item into a variable)
print(new_line)
print("\nBefore going out to the trail, it is mandatory that you at least visit the store...")
print("Welcome to the store! Your current balance is", total, "Here are what you can buy with it: \n  1. Food ($50 per kilogram) \n  2. Clothing ($100 per piece) \n  3. Ammunition ($10 per box) \n  4. Treasure maps ($500 per map)")
item_num = int(input("Which item number would you like to purchase? "))

## Asking how much of the item 1 the user wants (storing it in a variable)
if item_num == 1:
    print(new_line)
    food = int(input("\nHow much kilogram of food would you like to purchase? "))

    #calculating the balance
    balance = total - (50 * food)

    #storing the item in a variable for use later (in the final statement)
    #   including a case for either one or many items purchased
    if food > 1:
        choice = "enjoy your meals!"
    else:
        choice = "enjoy your food!"


## Asking how much of the item 2 the user wants (storing it in a variable)
elif item_num == 2:
    print(new_line)
    clothing = int(input("\nHow many pieces of clothings would you like to purchase? "))

    #calculating the balance after purchasing item 2
    balance = total - (100 * clothing)

    #storing the item in a variable for use later (in the final statement)
    #   including a case for either one or many items purchased
    if clothing > 1:
        choice = "enjoy the weather with your new clothes!"
    else:
        choice = "enjoy the weather with your new clothing!"


## Asking how much of the item 3 the user wants (storing it in a variable)
elif item_num == 3:
    print(new_line)
    ammunition = int(input("\nHow many boxes of ammunition would you like to purchase? "))

    #calculating the balance after purchasing item 3
    balance = total - (10 * ammunition)

    #storing the item in a variable for use later (in the final statement)
    choice = "hope you enjoy depleting your ammuntions!"


## Asking how much of the item 4 the user wants (storing it in a variable)
elif item_num == 4:
    print(new_line)
    maps = int(input("\nHow many teasure maps would you like to purchase? "))

    #calculating the balance after purchasing item 4
    balance = total - (500 * maps)

    #storing the item in a variable for use later (in the final statement)
    #   including a case for either one or many items purchased
    if maps > 1:
        choice = "hope you find loads of treasure with your maps!"
    else:
        choice = "hope you find a treasure with your map!"


## Including a case if the inputed item number does not exist
else:
    print(new_line)
    print("The store does not currently sell the item associated with your given item number. Have a nice day!")

    #creating a variable for use later (in the final statement)
    balance = "have fun!"



## Two final outcomes and their statements: either in debt or enjoy their trip (with their item)
print(new_line)
if balance < 0:
    print("\nOh nooo! You are now in debt, and mercenaries were sent to recollect it from you... Better luck next time!")
elif balance >= 0:
    print("\nYour balance is now", str(balance) + "! Please be careful on your trip and", choice)
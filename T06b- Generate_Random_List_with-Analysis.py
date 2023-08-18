
# creating a 'string-counting' function
def string_count(list_spec:list, str_spec:str):
    my_list = list_spec 
    appearance = 0

    # looking through all items inside the list
    for i in range(0, len(my_list), 1):
        if my_list[i] == str_spec:
            appearance += 1 #counting that item's appearance

    return print(f"The string '{str_spec}' appears {appearance} times in the list.") #returning how many times the specific string has appeared in the list



# creating a main function (where most of the code is)
def main():

    import random #need random for random generation

    flag = True
    while flag:
        #setting up the main variables/list
        my_list = [] # creating an empty list to alter later
        list_length = input("How many items would you like your list to contain: ") # prompting the user for the lenght of the list

        #if the user has entered an integer
        if list_length.isdigit():
            list_length = abs(int(list_length)) #changing the type of input
            flag = False

        # if the user has not entered an integer
        else:
            print("Please only enter an integer.")
            continue


    while True:
        # creating the integers that will be included inside the list
        range_min = input("What is the 1st value of the range of your list? ") #the minimum limit of the list
        range_max = input("What is the 2nd value of the range of your list? ") #the maximum limit of the list

        # verify and secure that the ranges are integers
        if range_min.isdigit() and range_max.isdigit():
            range_min = int(range_min)
            range_max = int(range_max)
            break

        else: #include a case for if the range are not integers
            print("Please only enter integers.")
            continue

    if range_max < range_min: #switching the range of values if the limits are inversed
        temp = range_max
        range_max = range_min
        range_min = temp
    
    if list_length > 0:
        for i in range(0, list_length, 1): #for every item in the list (size specified by the user)
            my_list.append(random.randint(range_min, range_max)) #was not specified which integers should be contained within the list: arbitrarily contain random ints between [1, 20]

        print(f"Your list: {my_list}") #print the list for the user

    #counter inside event to see replace all instances of an integer to string
    while True:
        print("\nDo you wish to replace an integer-item from the list to a string? (yes/no) ")
        int_replace = input()

        if int_replace == 'yes'.lower(): #if the user wishes to replace an int to str

            # creating a loop using a BOOL-flag to verify that the input is an int
            run = True
            while run:
                #asking the user what they want to change, and to what
                user_rep = input("Which integer would you like to replace: ")

                if user_rep.isdigit(): #if the user input is an int
                    user_rep = int(user_rep)
                    run = False

                else: #continue asking the integer to replace, if it was not an integer
                    print("Please only enter an integer.")
                    continue

            user_rep_2 = input("With what string: ")

            #skimming through the list
            for i in range(0, list_length, 1):
                if my_list[i] == user_rep: #if the item in the list is the integer specified by the user
                    my_list[i] = user_rep_2 #change it to the str the user wanted

                else: #if the item (int) was not the one specified by the user, simply continue to the next item in the list
                    continue
                i += 1

            print(f"Your list: {my_list}") #printing the list after the change


        elif int_replace == 'no'.lower(): #if user does not wish to replace, then break the loop and get out

            print(f"Your list: {my_list}") #printing the most current version of the list
            break

        else: #if the user entered a non-valid input

            print("Invalid response. Please enter either 'yes' or 'no'.")
            continue

    #intitiation a loop
    while True:
        #part to ask if they wish to identify the number of times a string has appeared
        print("\nDo you wish to count the number of times a particular 'string' has appeared in your list? (yes/no) ")
        num_times = input()

        #if the user wants to count a specific string
        if num_times == 'yes'.lower(): 
            str_spec = input("What string would you count its appearance: ")
            string_count(my_list, str_spec) #calling the previously created function

        # if the user does not want to count a string's appearance
        elif num_times == 'no'.lower():
            print("\nYou have now exited the program.")
            break

        # if the user entered something invalid
        else:
            print("Please only enter 'yes' or 'no'.")
            continue

#calling the main function to begin executing the code
main()
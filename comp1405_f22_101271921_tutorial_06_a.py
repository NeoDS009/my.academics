# Deneo Shi 101271921

# creating one function main
def main():

    #creating an empty list
    my_list = []

    # creating a loop
    flag = True
    while flag:

        # asking the user if they wish to add add/remove/exit the program
        print("\nWould you like to add (type 'add') or remove (type 'remove') an item from your list, or exit for you are satisfied with the list (type 'exit') ")
        user_choice = input()
        if user_choice == 'exit'.lower():
            flag = False

        # if the user wants to "add" an item to the list
        elif user_choice == 'add'.lower():
            user_op = input("What item would you like to insert into the list: ") #asking what do they want to add
            my_list.append(user_op) #appending the list with the user's input

        # if the user wnats to remove an item from the list
        elif user_choice == 'remove'.lower():

            #making sure if they want to remove the last item from the list
            user_op = input("Are you sure you if want to remove the last item of your list (type 'yes' or 'no'): ")

            # a valid "yes"
            if user_op == 'yes'.lower():

                # verifiying if it is possible to remove an item from the list
                if len(my_list) > 0:
                    my_list.pop(-1) # remove it (the last item from the list)
                    print("You have removed the last item of your list.")

                else: # if the list is empty
                    print("Your list is currently empty: cannot remove unexisting item from the list.")
            
            # a valid "no"
            elif user_op == 'no'.lower():
                print("You have not removed the last item of your list") #don't remove it

            # an invalid answer
            else:
                print("What you have entered is not a valid choice. Please re-type your answer")
                continue

        # an invalid answer    
        else:
            print("That is not a choice of alter to your list. Please typer wheter 'add', 'remove', or 'exit'.")
            continue

    # printing their list, and its length    
    print(f"\nYour list contains {len(my_list)} items, which is {my_list}")

# calling this function
main()
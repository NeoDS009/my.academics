
# creating the 'testing prime number' function
def primeness(tut_integer):

    # importing needed third-party modules
    import sys

    # for the following computations to be executed, the input value needs to be in the string type
    tut_integer = str(tut_integer)

    # condition to finish the program
    if tut_integer.lower() == '': 
        sys.exit()

    # if the game is not over
    else:
        # prove if it is an integer
        if tut_integer.isdigit(): # if the input is an integer
            tut_integer = int(tut_integer)

            if tut_integer > 1: # prime numbers can only be greater than 0
                for num in range(2, tut_integer):

                    if (tut_integer % num) == 0: # if there is no remainder (not a prime number)
                        print(f"{tut_integer} is not a prime number. \n")
                        break

                    else: # if there is always a remainder (a prime number)
                        print(f"{tut_integer} is a prime number \n")
                        break

            else: # if the input value is negative or 0
                print(f"{tut_integer} is not a prime number \n")

        # if user has not entered a prime number
        else:
            print(f"{tut_integer} cannot a prime number, please input a positive integer next time... \n")


# writing a program to continuously call the function (until condition is met --> entering '')
while True:

    # calling the function with an input
    primeness(input("For what integer would you evaluate for its primeness (enter nothing to stop): "))


# defining a "matrix" function that takes into 1 argument and verify if it is a "valid matrix"
def matrix(argument):
    
    # verify that the given argument is a list
    if isinstance(argument, list):

        # verify if the it is a list of lists
        for a in argument:
            if isinstance(a, list): #ititerate through all entries, if if everything is a list, then it is a list of lists
                boolean = isinstance(a, list)
            else:
                boolean = isinstance(a, list)
        
        # only continue if it is a list of lists
        if boolean == True:

            # verify that the list of lists is rectangular
            lenght = len(argument[0]) #first entry/list of the lists/reference
            false_test = 0 # setting a variable to alter later

            for b in argument: #skim through the list

                curr_lenght = len(argument[argument.index(b)]) #if the lenght of the list within the list
                if curr_lenght == lenght: #is equal to that of the first list
                    continue 
                else:   #if not, then the false_test results in positive
                    false_test += 1

            # checking if the false_test yields a change (if yes, then it is not rectangular)
            if false_test > 0:
                boolean_2 = False
            else:
                boolean_2 = True
            
            # verify if all elements from the list within the list is an int:
            false_test_2 = 0 #setting a false_test variable again

            # iterate through all rows
            for row in argument:
                # iterate through all columns of all rows (all entries of a matrix)
                for column in argument[argument.index(row)]:

                    # if every single entry is an int
                    if isinstance(column, int):
                        continue

                    # if one entrie is not an int, then change the false_test_2
                    else:
                        false_test_2 += 1

            # if the false_test_2 has changed (i.e. at least one entrie is not an integer)
            if false_test_2 > 0:
                boolean_3 = False
            else:
                boolean_3 = True

            # setting a final variable to see if all are True
            total_boolean = bool(boolean and boolean_2 and boolean_3)
        
        # if it is not a list of lists
        else:
            total_boolean = False

    #if the argument is not a list of list
    else:
        total_boolean = False

    # printing the final variable... no need to show the user, I guess?
    #print(total_boolean)

    return total_boolean
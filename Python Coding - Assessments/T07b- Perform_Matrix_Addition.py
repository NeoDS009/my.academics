
'''
This program/source code contains 2 parts. 
Part 1 will verify that both of the input matrices (as arguments) into the function are 'valid' matrices. 
Part 2 will evaluate the result from Part 1, and determine if it is possible to output a sum or not, and 
    proceed as such.
'''

#____________________________________________________________________________________________________________________________
#                                                               Part 1:
# - verifying if both arguments taken into the function are lists, list of lists, rectangular, and contain integer entries


# defining a "matrix" function that takes into 2 matrices and verify if it is and perform the sum
def matrix_sum(matrix_1, matrix_2):

    # verifying that both are matrices (rectangularity (isn't this just the equal size of columns?))

# verifying that matrix_1 is a matrix
    
    # verify that the given matrix_1 is a list
    if isinstance(matrix_1, list):

        # verify if the it is a list of lists
        for a in matrix_1:
            if isinstance(a, list): #ititerate through all entries, if if everything is a list, then it is a list of lists
                boolean = isinstance(a, list)
            else:
                boolean = isinstance(a, list)
        
        # only continue if it is a list of lists
        if boolean == True:

            # verify that the list of lists is rectangular
            lenght = len(matrix_1[0]) #first entry/list of the lists/reference
            false_test = 0 # setting a variable to alter later

            for b in matrix_1: #skim through the list

                curr_lenght = len(matrix_1[matrix_1.index(b)]) #if the lenght of the list within the list
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
            for row in matrix_1:
                # iterate through all columns of all rows (all entries of a matrix)
                for column in matrix_1[matrix_1.index(row)]:

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
            total_boolean_1 = bool(boolean and boolean_2 and boolean_3)
        
        # if it is not a list of lists
        else:
            total_boolean_1 = False

    #if the matrix_1 is not a list of list
    else:
        total_boolean_1 = False



# verifying that matrix_2 is a matrix

    # verify that the given matrix_2 is a list
    if isinstance(matrix_2, list):

        # verify if the it is a list of lists
        for a in matrix_2:
            if isinstance(a, list): #ititerate through all entries, if if everything is a list, then it is a list of lists
                boolean_a = isinstance(a, list)
            else:
                boolean_a = isinstance(a, list)
        
        # only continue if it is a list of lists
        if boolean_a == True:

            # verify that the list of lists is rectangular
            lenght = len(matrix_2[0]) #first entry/list of the lists/reference
            false_test = 0 # setting a variable to alter later

            for b in matrix_2: #skim through the list

                curr_lenght = len(matrix_2[matrix_2.index(b)]) #if the lenght of the list within the list
                if curr_lenght == lenght: #is equal to that of the first list
                    continue 
                else:   #if not, then the false_test results in positive
                    false_test += 1

            # checking if the false_test yields a change (if yes, then it is not rectangular)
            if false_test > 0:
                boolean_b = False
            else:
                boolean_b = True
            
            # verify if all elements from the list within the list is an int:
            false_test_2 = 0 #setting a false_test variable again

            # iterate through all rows
            for row in matrix_2:
                # iterate through all columns of all rows (all entries of a matrix)
                for column in matrix_2[matrix_2.index(row)]:

                    # if every single entry is an int
                    if isinstance(column, int):
                        continue

                    # if one entrie is not an int, then change the false_test_2
                    else:
                        false_test_2 += 1

            # if the false_test_2 has changed (i.e. at least one entrie is not an integer)
            if false_test_2 > 0:
                boolean_c = False
            else:
                boolean_c = True

            # setting a final variable to see if all are True
            total_boolean_2 = bool(boolean_a and boolean_b and boolean_c)
        
        # if it is not a list of lists
        else:
            total_boolean_2 = False

    #if the matrix_2 is not a list of list
    else:
        total_boolean_2 = False

    # printing the final variable... no need to show the user, I guess?
    # print(total_boolean)

    total_boolean = bool(total_boolean_1 and total_boolean_2)
    end_sum = []


#____________________________________________________________________________________________________________________

    #                                                       Part 2:
    # Evaluate the data received from "part 1" to identify if the sum of the two matrices is possible, and return as needed


# performing matrix addition if and only if both are matrices
    if total_boolean == True:

        # verifying that both matrices are of the same size
        #initializing variables for rows and columns
        rows_1 = 0
        columns_1 = 0
        
        #checking all entries of a matrix (iterating after rows after the columns reaches the end): adding the counts of rows and columns to their corresponding variables
        for rows_m1 in matrix_1:
            rows_1 += 1
            if rows_1 == 1:
                for columns_m1 in matrix_1[matrix_1.index(rows_m1)]:
                    columns_1 += 1


        #same algorithm for the second matrix            
        rows_2 = 0
        columns_2 = 0

        for rows_m2 in matrix_2:
            rows_2 += 1
            if rows_2 == 1:
                for columns_m2 in matrix_2[matrix_2.index(rows_m2)]:
                    columns_2 += 1
        
        # if both matrices have the same size
        if rows_1 == rows_2 and columns_1 == columns_2:
            end_sum = [] #an empty matrix to store the rows

            #iterate through all rows 
            for row in range(0, rows_1, 1):
                end_sum_row = [] #an empty list for storing the rows' data
                
                #iterate through all columns
                for column in range(0, columns_1, 1):

                    # adding the entris of each column of the row
                    the_sum = matrix_1[row][column] + matrix_2[row][column]

                    # append the sum of each column into the row
                    end_sum_row.append(the_sum)
                
                # append the row into the matrix
                end_sum.append(end_sum_row)


            #print and return the sum of the two matrices (included print statemnts, but commented out just in case)
            #print(end_sum)
            return end_sum
            

        else: 
            #print(end_sum) 
            return end_sum  #both matrices are valid, but their size do not match
    
    else:
        #print(end_sum)  
        return end_sum  #if at least one of the matrices are not matrices
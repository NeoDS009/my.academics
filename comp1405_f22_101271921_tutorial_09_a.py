# Deneo Shi  101271921


# Importing needed third-party modules
import random


# defining the first function
def Bogosort(list_argument):

    # run a loop until told otherwise 
    boolean_val = False #initalize a boolean value
    limit = 0 # going to limit at a maxiumum of 50000 tries, (around 5-10 seconds (if it were to print each try))
    run = True
    
    while run:

        for i in range(1, len(list_argument), 1): # scout through the entire list
            j = i

            if (list_argument[j-1] > list_argument[j]) and (j > 0):

                # create a pool of valid random values to pick from
                valid_random_val = []
                for elt in range(len(list_argument)):
                    valid_random_val.append(elt)
                

                #switching all values
                for haha in range(0, len(list_argument)-1): # scout through the entire list

                    random_val = random.randint(0, (len(valid_random_val)-1)) # get a random value from the valid random list
                    valid_random_val.pop(random_val) # remove that value
                    the_random_val = valid_random_val[random_val-1] # securing the random value into a variable

                    # switching the value
                    temp = list_argument[haha]
                    list_argument[haha] = list_argument[the_random_val]
                    list_argument[the_random_val] = temp

                #print(list_argument) #print the new altered/shuffled list (to keep track) (for testing purposes)
                limit += 1 #increment limit by 1, 1 time to go through
            
            if limit > 50000: #check if the number of tries has surpassed the limit
                run = False


            # Verify if the list has been sorted
            verify_list = [] # creating an empty list
            for i in range(1, len(list_argument), 1): #scout throguh the list
                
                if (list_argument[i-1] <= list_argument[i]): #if the next element is smaller or equal than the previous element
                    verify_list.append(1) #append 1 element to the empty list
                    i+=1
                if len(verify_list) == len(list_argument): #if all values are smaller than the next, then stop the loop
                    boolean_val = True
                    run = False



    # return and print necessary results       
    return boolean_val
                    

# defining the second function
def Bozosort(list_argument):

    boolean_val = False
    limit = 0 # going to set a limit to the number of tries to 50000 (around 5-10 seconds: when printing the sorting process (each line))
    # a loop to always run, until told otherwise
    run = True
    while run:

        # scout through the list
        for i in range(1, len(list_argument), 1):
            j = i
            if (list_argument[j-1] > list_argument[j]) and (j > 0): #if there is one instance of non-sorted

                random_val_1 = random.randint(0, len(list_argument)-1) #initialize random values
                random_val_2 = random.randint(0, len(list_argument)-1)

                temp_val = list_argument[random_val_1] #switch these two random values
                list_argument[random_val_1] = list_argument[random_val_2]
                list_argument[random_val_2] = temp_val

                #print(list_argument) #print the switched list to keep track (for testing purposes)
                limit += 1 #increment limit by 1, one less trie to go through

            if limit > 50000: #check if the number of tries has surpassed the limit
                run = False
            
            verify_list = [] # creating an empty list
            for i in range(1, len(list_argument), 1): #scout throguh the list
                
                if (list_argument[i-1] <= list_argument[i]): #if the next element is smaller or equal than the previous element
                    verify_list.append(1) #append 1 element to the empty list
                    i+=1
                if len(verify_list) == len(list_argument): #if all values are smaller than the next, then stop the loop
                    boolean_val = True
                    # print(f"The function 2 ran a limit of {limit}")
                    run = False
                    

    return boolean_val

            
# for testing purposes: creating a main function
def main():

    num_elts = random.randint(2, 15) #how many elements does the list have
    print(f"Number of elements to sort in the random list: {num_elts}")


    unsorted_list = [] #an unsorted list --> a random list
    for elts in range(num_elts): #create a random list
        random_elt = random.randint(0,100)
        unsorted_list.append(random_elt)        

    # initializing variables to carry the return values of the functions
    bogosort = Bogosort(unsorted_list)
    bozosort = Bozosort(unsorted_list)

    # printing a final boolean result
    print(f"Bogosort: {bogosort}")
    print(f"Bozosort: {bozosort}")

main()
# Deneo Shi 101271921



# importing required third-party module
import random

# Getting the width of the map
def the_width():
    while True:

        #fail-safe plan
        try:
            width_beta = int(input("\nWhat is the width of the map you wish to create: "))
            break

        except:
            print("Please only input an integer for the width of the map.")

    return width_beta

# Getting the height of the map
def the_height():
    while True:

        #fail-safe plan
        try:
            height_beta = int(input("\nWhat is the height of the map you wish to create: "))
            break

        except:
            print("Please only input an integer for the height of the map.")

    return height_beta


# getting the correct tile set
def tile_set():
    while True:

        tile_set = input("\nWhich tile set do you want to use (forest or desert): ")
        tile_name = tile_set.lower()
        if "desert" in tile_name:
            the_tile_name = "desert"
            break
        elif "forest" in tile_name:
            the_tile_name = "forest"
            break
        else:
            print("The tile set that you have inputed is not a valid tile set. Please input a valid one (desert or forest)")
    
    return the_tile_name



def main():

    # Prompting and asking for the user for inputs until valid
    while True:

        # fail-safe plan for the file name
        try:

            # setting the input file's name into a list, and check if it ends with .txt (last element of the list), after separation
            file_name = input('\nWhat is name of the file you want to write in (remember to add the suffixe ".txt"): ')
            file_list = file_name.split('.')
            if file_list[-1] == "txt":
                file_alter = open(file_name, "w")
                break
            else:
                print('You forgot to input the ".txt" at the end of your file name. Please type the ".txt" at the end.')
                continue
            
        except:
            print("That is not a valid text-file format. PLease try again.")

    #setting up the needed variables
    width = the_width()

    height = the_height()

    tile_set_name = tile_set()


    # writing what needs to be written
    file_alter.write(f"Tiles: {tile_set_name}\n\n") #writing the tile set

    # covering all the needed values for the input height and width
    for w in range(height): 
        for h in range(width):

            #generating a new random value each time
            random_val = random.randint(0,4)
            writing = str(random_val)

            file_alter.write(writing)
            file_alter.write(",")
        file_alter.write("\n")

    file_alter.close() #close that file


    #print a validation message
    print(f"\nYou have successfully created a file named: {file_name}")

# calling the main function to set things in motion
main()
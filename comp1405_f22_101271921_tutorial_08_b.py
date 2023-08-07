# Deneo Shi 101271921



# Importing needed third-party modules
import pygame
import sys

# read the file
def read_file():
    while True:
        
        #re-prompt the user for a file name if the previous was not valid
        try:
            my_file = open(input("\nName of file you want to open: "), 'r') #read-access only
            break

        except:
            print("Could not open the file with this name. Please try again with a valid file name.")

    # return the file    
    return my_file #has the wanted file


# transform the file into a matrix
def edit():

    # calling the previous function
    x = read_file()
    my_list = x.readlines() # reading all the lines into a list

    # creating a list without 'spaces'
    the_list = []
    for i in range(len(my_list)):
        magic = my_list[i].strip()
        the_list.append(magic)
    
    # editing the list to turn it into a matrix
    wow_list = []
    for i in range(len(the_list)):
        magic = the_list[i].split(",")
        wow_list.append(magic)

    return wow_list #is now in a matrix


# edit the matrix into the wanted form and draw a pygame window that represents it
def main():

    # calling the previous function
    my_list = edit()

    # get the matrix with only the values (not the tile's type nor the space)
    the_list = []
    for i in range(2, len(my_list), 1):
        magic = my_list[i]
        the_list.append(magic)

    # get the matrix without the unecessary ""
    magic_list = []
    for i in range(len(the_list)):
        magic = len(the_list[i]) - 1
        wow = []
        for o in range(magic):
            wow.append(the_list[i][o])
        magic_list.append(wow)

    # getting the number of rows and columns
    num_rows = len(magic_list)
    num_columns = 0
    for rows in range(len(magic_list)):
        for columns in range(len(magic_list[rows])):
            num_columns += 1
        break

    #Drawing with Pygame
    print("Construction of a Pygame Window titled 'My Tile Map' from your input file is successful!")
    my_display = pygame.display.set_mode(((num_columns*64), (num_rows*64))) # creating a correct pygame window of the correct size
    pygame.display.set_caption("My Tile Map") # naming that pygame window

    # visit every element/random value from the matrix
    for x in range(len(magic_list)):
        for y in range(len(magic_list[x])):

            # forest alternative
            if "Tiles: forest" in my_list[0]: #initializing the forest tile images
                the_zero = pygame.image.load("tutorial_file_forest_0.gif")
                the_one = pygame.image.load("tutorial_file_forest_1.gif")
                the_two = pygame.image.load("tutorial_file_forest_2.gif")
                the_three = pygame.image.load("tutorial_file_forest_3.gif")
                the_four = pygame.image.load("tutorial_file_forest_4.gif")

                #blitting the correct matches onto the pygame window
                if magic_list[x][y] == '0':
                    my_display.blit(the_zero, (y*64,x*64))
                elif magic_list[x][y] == '1':
                    my_display.blit(the_one, (y*64,x*64))
                elif magic_list[x][y] == '2':
                    my_display.blit(the_two, (y*64,x*64))
                elif magic_list[x][y] == '3':
                    my_display.blit(the_three, (y*64,x*64))
                elif magic_list[x][y] == '4':
                    my_display.blit(the_four, (y*64,x*64))
                else:
                    print("The file has specified a tile image that does not exist.")
                    sys.exit() #end the program

            # desert alternative
            elif "Tiles: desert" in my_list[0]: #initializing the desert tile images
                the_zero = pygame.image.load("tutorial_file_desert_0.gif")
                the_one = pygame.image.load("tutorial_file_desert_1.gif")
                the_two = pygame.image.load("tutorial_file_desert_2.gif")
                the_three = pygame.image.load("tutorial_file_desert_3.gif")
                the_four = pygame.image.load("tutorial_file_desert_4.gif")

                #blitting onto the pygame window (conditions)
                if magic_list[x][y] == '0':
                    my_display.blit(the_zero, (y*64,x*64))
                elif magic_list[x][y] == '1':
                    my_display.blit(the_one, (y*64,x*64))
                elif magic_list[x][y] == '2':
                    my_display.blit(the_two, (y*64,x*64))
                elif magic_list[x][y] == '3':
                    my_display.blit(the_three, (y*64,x*64))
                elif magic_list[x][y] == '4':
                    my_display.blit(the_four, (y*64,x*64))
                else:
                    print("The file has specified a tile image that does not exist.")
                    sys.exit() #end the program

            else:
                print("Sorry, but it seems that your input file does not meet the requirement:")
                print("It does not specify whether it is using desert tiles or forest tiles")
                print("Please try again with a file that fits that requirement.")
                print("Goodbye...")
                sys.exit()
            
    # allow user to close the pygame window
    while True:
        for event in pygame.event.get():
            pygame.display.update()
            if event.type == pygame.QUIT:
                print("Goodbye...")
                exit()	

# Calling the main function of this code
main()

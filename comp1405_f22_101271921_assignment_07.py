''' INSTRUCTIONS! INSTRUCTIONS! INSTRUCTIONS!

Instructions: Import any image file type as a system command line argument, and after doing so, answer how big of an area dimension
you would like to invert color per click (simply click on the LEFT MOUSE BUTTON to apply an inverted color feature over your area size
(below right of the click)!!

Note: Don't forget to open the Pygame window after entering your dimension!

'''

# Importing needed third-party modules
import pygame
import sys


# Printing the instructions (in case the user did not read the source code)
print("\nINSTRCUTIONS below! \nImport any image file type as a system command line argument, and after doing so, answer how big of an area dimension \nyou would like to invert color per click (simply click on the LEFT MOUSE BUTTON to apply an inverted color feature over your entered area size!) \nNote: Don't forget to open the Pygame window after entering your dimension!\n\n")


# Only continue in the source code, if and only if the input value for the size of the inverting square is an integer
while True:
  try: # try if the input is only integers
    area_size = int(input("How big of an area (side of the square) would you like to be able to invert color by each click? "))
    break
  except ValueError: # if input is not all intergers, retry
      print("Please only input integers...\n")  
      continue


# Initializing Pygame's functions
pygame.init()

# Prompting the user for their image file
user_image = pygame.image.load(sys.argv[1])

# Getting the size of the user's image
(w, h) = user_image.get_size()

# Creating a Pygame window screen of the same size as the user's image
pic = pygame.display.set_mode((w, h))

# Blitting/copy-pasting the user's image onto the drawing screen of Pygame
pic.blit(user_image, (0, 0))

# Setting up the name of the Pygame Window
pygame.display.set_caption("Inverted Color Feature (by clicking left mouse)")


# A loop to continously run, until the user closes the Pygame window
exit_flag = False 
while not exit_flag:

    

    # IF MOUSE IS CLICKED
    for event in pygame.event.get(): 
        
        # Continuously get the position of the mouse cursor
        (mouse_x, mouse_y) = pygame.mouse.get_pos()

        # If any mouse is clicked
        if event.type == pygame.MOUSEBUTTONDOWN:

            # Only apply inverting color feature when left mouse is clicked
            if event.button == 1:

                # setting constant variables after the mouse is clicked
                static_x = mouse_x + area_size
                static_y = mouse_y + area_size
                pos_x = mouse_x
                pos_y = mouse_y
                
                # if x is too close to the border
                if static_x > w and static_y < h: 
                    magic_value = w - pos_x# limiting the border
                    static_x = pos_x + magic_value # only extending until the previously given border
                    

                # if only y is too close to the border
                elif static_y > h and static_x < w: 

                    magic_value = h - pos_y # limiting the border

                    static_y = pos_y + magic_value # only extending until the previously given border


                # if both x and y are too close to the border
                elif (static_x, static_y) > (w, h): 
                    magic_val_x = w - pos_x #limiting the borders
                    magic_val_y = h - pos_y
                    static_x = pos_x + magic_val_x #only extending until the previously given border
                    static_y = pos_y + magic_val_y
                    
                # Drawing the inverted colors' area    
                for y in range(pos_y, static_y, 1): # drawing on each row

                    for x in range(pos_x, static_x, 1): # drawing for each column of each row

                        (R, G, B, _) = pic.get_at((x, y)) # getting the (red, green, blue) color values for each pixels

                        pic.set_at((x, y), (255-R, 255-G, 255-B)) # setting/inverting the color of each pixels

                        #pygame.display.update()
                        
                        if y > h and x > w:
                            break
            
            
            # If any other mouse button is clicked (not left mouse button)
            else:
                print("Please click the left mouse to initiate the color inverting feature!")

        # continuously update the screen's display            
        pygame.display.update()

        # if the user clicks on the 'X', then the program ceases to run
        if event.type == pygame.QUIT:
            exit_flag = True

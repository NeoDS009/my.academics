import pygame
import sys
import random

pygame.init()

# Get the picture's name from a command-line argument and loading the picture (initializing into a variable)
# picture
run = True
while run:
    try:
        picture = pygame.image.load(sys.argv[1])
        run = False
    except:
        IndexError

picture = pygame.image.load(sys.argv[1])



#password = Y0w@1m0

#Get the size of the picture
(width, height) = picture.get_size()

# magnifiying the original picture (set up into a new variable)
image = pygame.display.set_mode((width*5, height*5))

# Setting the image's top left corner
#image.blit(picture, (0, 0)) #prints the picture on the screen: not good

# drawing coloured circles for every pixel
for y in range(0, height):
    for x in range(0, width):
        #get the color values at each pixel (getting each color: red, green, and blue values (setting them up as variables))
        (r, g, b, _) = picture.get_at((x, y))

        # get the number of r,g,b circles
        num_red = int(r / 5)
        num_green = int(g / 5)
        num_blue = int(b / 5)

        # initializing the colours
        blue_colour = (0, 0, 255)
        green_colour = (0, 255, 0)
        red_colour = (255, 0, 0)
        black_colour = (0, 0, 0)

        # checking if circles need to be drawn (colours present), and if needed, draw them in a specific range which will be randomized
        while num_red > 0:
            pygame.draw.circle(image, red_colour, (random.randint((x*5)-15, (x*5)), random.randint((y*5)-15, (y*5))), 1)  # why -15, why not -x, check assignment instructions to know the boundaries
            num_red = num_red - 1
        while num_green > 0:
            pygame.draw.circle(image, green_colour, (random.randint((x*5)-15, (x*5)), random.randint((y*5)-15, (y*5))), 1)
            num_green = num_green - 1
        while num_blue > 0:
            pygame.draw.circle(image, blue_colour, (random.randint((x*5)-15, (x*5)), random.randint((y*5)-15, (y*5))), 1)
            num_blue = num_blue - 1
        while num_red and num_blue and num_red == 0:
            if (r, g, b) == black_colour:
                pygame.draw.circle(image, black_colour, (random.randint((x*5)), random.randint((y*5))), 1)


# Update the screen
pygame.display.update()

# close the window on user's command
while True:
	# pygame.event.get(): a list of everything that the user do (mouse movement, typing, clicking, etc.) since the program has run
    for event in pygame.event.get():
		# if the user clicks "X"
        if event.type == pygame.QUIT:
			# ending the program
            exit()	
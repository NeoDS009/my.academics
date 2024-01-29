# Importing all needed third-party modules
import random
import pygame

# Initialize all the functions of Pygame
pygame.init()

# Setting the two players' colors up
blue_color = (0,0,255)
brown_color = (102,51,0)

# initial position of two players
pos_p1_x = 25
pos_p1_y = 12 
pos_p2_x = 25
pos_p2_y = 37

# Initializing the player's move's turn
play_turn = 1


print("The dice determining of the players' move:")




# making the two players move:
while (pos_p1_x + pos_p1_y) <= (275 + 350) and (pos_p2_x + pos_p2_y) <= (275 + 350):

    # Naming the current player
    if play_turn == 1:
        current_player = "Player 1 (Blue)"
    else:
        current_player = "Player 2 (Orange)"

    # the dice program
    dice_1 = [1, 2]
    dice_num_1 = random.randint(0,1)
    dice_roll_1 = dice_1[int(dice_num_1)]
    print(f"Dice #1 rolls: {dice_roll_1}")

    dice_2 = [1, 2]
    dice_num_2 = random.randint(0,1)
    dice_roll_2 = dice_2[int(dice_num_2)]
    print(f"Dice #2 rolls: {dice_roll_2}")

    the_dice_roll = dice_roll_1 + dice_roll_2
    print(f"The {current_player} moves by {the_dice_roll}", end="\n\n")

    # initializing the variables for the checkerboard
    w_by_square = 6
    h_by_square = 7
    square_side_lenght = 50
    black_color = (0, 0, 0)
    white_color = (255, 255, 255)
    orange_color = (255, 165, 0)
    current_color = white_color
    tile_num = 0

    # setting up the drawing screen
    drawing_screen = pygame.display.set_mode((square_side_lenght*w_by_square, square_side_lenght*h_by_square))
    drawing_screen.fill(white_color)
    pygame.display.set_caption("Snakes and Ladders")

    # drawing the checkerboard
    for y in range(0, h_by_square):
        for x in range(0, w_by_square):
            pygame.draw.rect(drawing_screen, current_color, (x*square_side_lenght, y*square_side_lenght, square_side_lenght, square_side_lenght))

            #calculate the number of each tile
            if tile_num <=42:
                tile_num += 1

            # printing number of each tile
            position_num_font = pygame.font.SysFont("Arial", 25) #choosing a font and size to write with
            position_num_displayed = position_num_font.render(str(tile_num), True, black_color) #what to write
            drawing_screen.blit(position_num_displayed, (x*50,y*50)) #printing the tile number on the screen (where)

            if current_color == white_color: # switching tiles' color
                current_color = orange_color
            else:
                current_color = white_color
        if current_color == white_color:
            current_color = orange_color
        else:
            current_color = white_color


    # Draw the snakes and ladders
    # The snakes
    pygame.draw.line(drawing_screen, (255, 0, 0), ((3)*50-25, (1)*50-25), ((5)*50-25, (6)*50-25), 5)
    pygame.draw.line(drawing_screen, (255, 0, 0), ((2)*50-25, (3)*50-25), ((3)*50-25, (6)*50-25), 5)
    # The Ladders
    pygame.draw.line(drawing_screen, (0, 255, 0), (((1)*50-(50*1/3)), (2)*50-(50*1/3)), ((3)*50-(50*1/3), (3)*50-(50*1/3)), 5)
    pygame.draw.line(drawing_screen, (0, 255, 0), ((1)*50-(50*2/3), (2)*50-(50*2/3)), ((3)*50-(50*2/3), (3)*50-(50*2/3)), 5)

    pygame.draw.line(drawing_screen, (0, 255, 0), ((3)*50-(50*1/3), (4)*50-(50*1/3)), ((5)*50-(50*1/3), (7)*50-(50*1/3)), 5)
    pygame.draw.line(drawing_screen, (0, 255, 0), ((3)*50-(50*2/3), (4)*50-(50*2/3)), ((5)*50-(50*2/3), (7)*50-(50*2/3)), 5)



    # initialize the beginner positions of the two players
    pygame.draw.circle(drawing_screen, blue_color, (pos_p1_x, pos_p1_y), 10)
    pygame.draw.circle(drawing_screen, brown_color, (pos_p2_x, pos_p2_y),  10)


    # Player's move, according to the dice roll (draws on top of the board game)
    # First player's move
    if play_turn == 1:
        pos_x = pos_p1_x + (50 * the_dice_roll) #to delete
        while pos_p1_x <  pos_x: # to delete
            pos_p1_x += 50 # to delete
        #pos_p1_x = pos_p1_x + (50 * the_dice_roll)
        if pos_p1_x > 300-25 and pos_p1_y < 350-38: # if player 1 reaches border, go down
            pos_p1_y += 50
            pos_p1_x -= 50*6
        play_turn = 2

    # Second player's move
    else:
        pos_2 = pos_p2_x + (50 * the_dice_roll)
        while pos_p2_x < pos_2:
            pos_p2_x += 50
            #pos_p2_x = pos_p2_x + (50 * the_dice_roll)
        if pos_p2_x > 300-25 and pos_p2_y < 350-13: # if player 2 reaches border, do down
            pos_p2_y += 50
            pos_p2_x -= 50*6
        play_turn = 1

    # Snakes and ladder
    if pos_p1_x == 25+(50*0) and pos_p1_y == 12+(50*1): #first ladder (blue)
        # (pos_p1_x, pos_p1_y) = ((25+(50*0)), (12+(50*1)))
        # pygame.time.delay(1000)
        (pos_p1_x, pos_p1_y) = (25+(50*2), 12+(50*2))
    if pos_p2_x == 25+(50*0) and pos_p2_y == 37+(50*1): #first ladder (brown)
        (pos_p2_x, pos_p2_y) = (25+(50*2), 37+(50*2))

    if pos_p1_x == 25+(50*2) and pos_p1_y == 12+(50*3) : #second ladder (blue)
        (pos_p1_x, pos_p1_y) = (25+(50*4), 12+(50*6))
    if pos_p2_x == 25+(50*2) and pos_p2_y == 37+(50*3): #second ladder (brown)
        (pos_p2_x, pos_p2_y) = (25+(50*4), 37+(50*6))

    if pos_p1_x == 25+(50*4) and pos_p1_y == 12+(50*5): #first snake (blue)
        (pos_p1_x, pos_p1_y) = (25+(50*2), 12+(50*0))
    if pos_p2_x == 25+(50*4) and pos_p2_y == 37+(50*5): #first snake (brown)
        (pos_p2_x, pos_p2_y) = (25+(50*2), 37+(50*0))

    if pos_p1_x == 25+(50*2) and pos_p1_y == 12+(50*5): #second snake (blue)
        (pos_p1_x, pos_p1_y) = (25+(50*1), 12+(50*2))
    if pos_p2_x == 25+(50*2) and pos_p2_y == 37+(50*5): #second snake (brown)
        (pos_p2_x, pos_p2_y) = (25+(50*1), 37+(50*2))

    # Drawing the winner on the screen
    # if player 1 (blue) wins
    if pos_p1_x >= 25+(50*5) and pos_p1_y >= 12+(50*6):
        pygame.draw.circle(drawing_screen, blue_color, (150, 175), 100)
        winner = pygame.font.SysFont("Arial", 39)
        winner_displayed = winner.render("The Winner", True, orange_color)
        drawing_screen.blit(winner_displayed, (69, 150))
        break
    # if player 2 (orange) wins
    if pos_p2_x >= 25+(50*5) and pos_p2_y >= 37+(50*6):
        pygame.draw.circle(drawing_screen, brown_color, (150, 175),  100)
        winner = pygame.font.SysFont("Arial", 39)
        winner_displayed = winner.render("The Winner", True, orange_color)
        drawing_screen.blit(winner_displayed, (69, 150)) 
        break

    # continuasly update the screen after each player's move
    pygame.display.update()
    pygame.time.delay(1069)



# allow user to close the game
while True:
    for event in pygame.event.get():
        pygame.display.update()
        if event.type == pygame.QUIT:
            exit()	
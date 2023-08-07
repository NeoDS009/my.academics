# Deneo Shi 101271921


'''
tl;dr: The inventory/treasure-count will be displayed when the user exits! 

no threads (two tasks at the same time: both Pygame and Terminal's input) --> Pygame will be non-responding :(
'''

#importing third-party modules for the visual support
import pygame
import sys
import os

# Creating shortcut functions to contain the descriptions
def one():
    return "The lobby is the place to welcome travellers, such as yourself. It is a safe place where you can stay as long as you want. \n\t     From here, you can visit the elevator or the main hall."

def two():
    return"The elevator is where you can change floors. You can move from the first floor to the second. \n\t     From here, you can visit the lobby or the training room. "

def three():
    return"The training room is where you can train yourself. Although fun, it is better to stay shorter amount of times here. \n\t     From here, you can visit the elevator or the training room."

def four():
    return"The treasure room is where this mansion stores its wealth. Since you are lucky enough to have found it, \n\t     be sure to test your luck! From here, you can visit the training room or the secret hallway"

def five():
    return"Congratulations for having found the secret hallway! The secret hallway is a hidden path hidden in this mansion. \n\t     From here, you can head visit the treasure room or the secret floor."

def six():
    return"Outsanding! You have found the secret floor! Even more hidden than than the secret hallway! \n\t     From here, you can visit the backstage or the secret hallway."

def seven():
    return"The backstage is where the darkest ideas of this mansion come from. It might fuel where you want to visit next. \n\t     From what your instincts tell you, do you want to visit the changing room or the secret floor."

def eight():
    return"The changing room is where people, gets their equipment to get ready for training. So many items in here! \n\t     Be sure to check if there are no hidden treasures! From here, you can viit the training room, the backstage, or the main hallway."

def nine():
    return"The main hallway is where people move from visiting the mansion, to living in the mansion. \n\t     So many people travelling here at night, would you believe that? From here, you can visit the changing room, the main hall, or the dining room."

def ten():
    return"The main hall is the most artistic place of this mansion. Where artworks and memories of past visitors remains from their gratitude. \n\t     From here, you can visit the lobby or the main hallway."

def eleven():
    return"The dining room is the main place people have their warm meals served. It is so spacious that it might be confused as the ballroom \n\t     but filled with tables and delicious smells. From here, you can visit the main hallway, the bedrooms, or the chef's kitchen."

def twelve():
    return"The bedrooms is absolutely astonishing. Possessing more than hundreds of rooms, each spacious enough to feel like it's from a 5-star hotel! \n\t     From here, you can visit dining room."

def thirteen():
    return"The chef's kitchen is the main area where meals are being cooked. Often visited by maids and butlers, \n\t     there always seems to be action in this spacious room. From here, you can visit the dining room or the memorial's garden."

def fourteen():
    return"The ballroom is where most parties are hosted in this mansion (especially when raining). However, it can sometimes be confused as the outside \n\t     due to its high ceiling. From here, you can visit the dining room or the memorial's garden."

def fifteen():
    return"The memorial's garden is where the butlers' and maids' memories are kept. It's name was given instead of a grave, otherwise no kids would want to visit it. \n\t     From here, you can visit the ballroom, the chef's kitchen, the command center, or the maid's room."

def sixteen():
    return"The maid's room is a private area where maids can relax. Separate from where the residents of this mansion sleeps, \n\t     the maid's room is rumored to be more fun to spend the night's at! From here, you can visit the memorial's garden."

def seventeen():
    return"The command center is where butlers and housekeepers' private sector. It's where they command male and female servants \n\t     to attend to the mansion's residents. From here, you can visit the memorials garden, the meeting room, or the dungeon."

def eighteen():
    return"The meeting room is where the secret service of the mansion discuss plans of security for the mansion. Partly collaborating with butlers and housekeeprs, \n\t     but mostly operating on their own, in this very room. From here, you can visit the command center."

def nineteen():
    return"The dungeon is a place of darkness. Although chains, shackles, and cages are absent due to their violent nature, it is still not a place of confort. \n\t     People who gets punished to the dungeon will have to cook their own food without the butlers' or maids' help. From here, you can visit the command center or the back gate."

def twenty():
    return"The back gate is where the dungeon's prisonners can get their own food. It is linked to a beautiful fruitful garden. Although there's no such thing as a forbidden fruit here~ \n\t     From here, you can visit the dungeon."

def treasure():
    return"Congratulations! You found a treasure! Type 'take' to take this treasure \n\t     (at the end of the game, it will be displayed how many treasures you have found)."

# Creating funcions to locate the room to another
def north(location):
    if location == 1:
        location = 0
    elif location == 3:
        location = 2
    elif location == 4:
        location = 3
    elif location == 5:
        location = 6
    elif location == 6:
        location = 7
    elif location == 8:
        location = 9
    elif location == 10:
        location = 11
    elif location == 13:
        location = 10
    elif location == 14:
        location = 12
    elif location == 16:
        location = 14
    elif location == 18:
        location = 16
    else:
        print("***********************************************************************") #catch the eye
        print("Impossible to go that way. Please choose another direction.") #fail-safe

    return location

def south(location): #1,3,4,7,8,10,12,11,13,15,17
    if location == 0:
        location = 1
    elif location == 2:
        location = 3
    elif location == 3:
        location = 4
    elif location == 6:
        location = 5
    elif location == 7:
        location = 6
    elif location == 9:
        location = 8
    elif location == 11:
        location = 10
    elif location == 10:
        location = 13
    elif location == 12:
        location = 14
    elif location == 14:
        location = 16
    elif location == 16:
        location = 18
    else:
        print("***********************************************************************")
        print("Impossible to go that way. Please choose another direction.")

    return location

def west(location):
    if location == 2:
        location = 1
    elif location == 7:
        location = 2
    elif location == 5:
        location = 4
    elif location == 8:
        location = 7
    elif location == 9:
        location = 0
    elif location == 10:
        location = 8
    elif location == 12:
        location = 10
    elif location == 14:
        location = 13
    elif location == 15:
        location = 14
    elif location == 17:
        location = 16
    elif location == 19:
        location = 18
    else:
        print("***********************************************************************")
        print("Impossible to go that way. Please choose another direction.")
    return location

def east(location): #2,3,5,8,9,11,12,15,17,19
    if location == 0:
        location = 9
    elif location == 1:
        location = 2
    elif location == 2:
        location = 7
    elif location == 4:
        location = 5
    elif location == 7:
        location = 8
    elif location == 8:
        location = 10
    elif location == 10:
        location = 12
    elif location == 13:
        location = 14
    elif location == 14:
        location = 15
    elif location == 16:
        location = 17
    elif location == 18:
        location = 19
    else:
        print("***********************************************************************")
        print("Impossible to go that way. Please choose another direction.")
    return location


# Creating the main-game function that will call upon other functions
def text_adventure_game():

    # list containing the names of the rooms
    names = ["the lobby","the elevator","the training room","the treasure room","the secret hallway","the secret floor","the backstage","the changing room","the main hallway","the main hall","the dining room","the garden","the chef's kitchen","the ballroom","the memorial's garden","the maid's room","the command center","the meeting room","the dungeon","the back gate", "TREASURE!"]
    
    # adjencency list containing the possible accessible rooms
    adj_list = [[1,9], [0,2], [1,3,7], [2,4,20], [3,5], [4,6,20], [5,7], [2,6,8], [7,9,10], [0,8,20], [8,11,12,13],[10],[10,14,20],[10,14],[12,13,15,16],[14,20],[14,17,18],[16],[16,19,20],[18]]


    # list containing the descriptions (their function calls)
    description = [one(), two(), three(), four(), five(), six(), seven(), eight(), nine(), ten(), eleven(), twelve(), thirteen(), fourteen(), fifteen(), sixteen(), seventeen(), eighteen(), nineteen(), twenty(), treasure()]

    # initializing the needed variables
    current_location = "the lobby"
    inventory = 0

    # a loop to always re-do the actions needed until the user wants to 'exit'
    while True:

        # calling and displaying the map
        visual_display()
        
        print("____________________________________________________________________________________") #to make things clear
        
        print(f"You are currently in {current_location}.\n") #showing where the user is

        print("From this location, you can go to any of the following location: ")

        indx_location = names.index(current_location) #get the numerical location of the current_location 


        #verifying what are connected to the current location
        for location in range(len(adj_list[indx_location])): #scout through the entire list within the list

            #let the program know where can go
            x = adj_list[indx_location][location] #put the number inside a variable

            #let the user know where can go
            print(f"\n\t{names[x]} (room option {location}) \nDescription: {description[x]}") #To know wich direction to go (North, South, East, West, please consult the given map)")
        
        print("\n\nTo know wich direction to go (North, South, East, or West, please consult the given map)") #little guide instructions

        #Prompt the user for the next_location
        print("Where would you like to go? (type: 'North', 'South', 'East', 'West', or 'Exit' to quit the game)")
        next_location = input()
        user_input = next_location.lower() #transform what the user said
        print()

        # evaluating what the user has inputed
        if 'north' in user_input:
            delta = north(indx_location) #program will get where to go (name's index)
            current_location = names[delta]
        
        elif ('take' in user_input) and (20 in adj_list[indx_location]): #user wants to take the treasure (conditions met)
            inventory += 1
            adj_list[indx_location].remove(20)
        
        elif 'south' in user_input: #user wants to go down
            delta = south(indx_location)
            current_location = names[delta]

        elif 'west' in user_input: #user wants to go left
            delta = west(indx_location)
            current_location = names[delta]

        elif 'east' in user_input: #user wants to go right
            delta = east(indx_location)
            current_location = names[delta]

        elif 'exit' in user_input: #user wants to exit: say how many treasures they have collected
            print(f"Reaching the end of your journey, your last visit was in {current_location}, and you have taken a total of {inventory} treasures in your invetory.")
            sys.exit()

        else:
            print("You cannot perform that action here.") #fail-safe
    
    

#Creating the visual display
def visual_display():

    # did not learn how to "thread" (running two things at the same time?/ pygame + terminal)
    # thus, the pygame window cannot work simultaneously with the terminal (does not respond)
    try:

        # locate the pygame window to a corner
        pygame_x = 777
        pygame_y = 36
        os.environ['SDL_VIDEO_WINDOW_POS'] = "%d,%d" % (pygame_x,pygame_y)
        image = pygame.image.load("101271921_My_Text_Adventure_Game_Map.jpg")
        (w,h) = image.get_size()
        dis_scr = pygame.display.set_mode((w,h))
        dis_scr.blit(image, (0,0))
        pygame.display.set_caption("My Text Adventure Game Map")
        while True:
            pygame.display.update()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    break
            break
    except:
        print("You have not yet saved the '101271921_My_Text_Adventure_Game_Map.jpg'. Please go save it first!")



#Calling this function

text_adventure_game()
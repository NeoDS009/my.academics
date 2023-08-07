# Deneo Shi 101271921


# importing needed third-party modules
import random
import keyboard
import sys

# intializing global variables (used by all functions)
win = 0
lose = 0
tie = 0

# function about the computer moves
def computer_move():
    comp_num = random.randint(0, 2)
    comp_move = ['rock', 'paper', 'scissors']
    comp_move = comp_move[comp_num]
    return comp_move

# function about the user's move
def player_choice():
    print("\nWhat's your move: r (for rock), p (paper), s (for scissors), or q (for quitting the game)?")
    player_move = input()
    return player_move

# function to quit/end everything
def exiting():
    sys.exit()


# defining the main function of the program
def main():

    # instructions
    print('''\nWelcome to a game of 'Rock Paper and Scissors'
    The rules are simple: press the 'r' key for rock, 'p' key for paper, or 's' key for choosing scissors.
    If you wish to end the game and see your results, then please press the 'q' key.
    If you wish to leave, then please press the 'd' key.

    Note: Now, press the 'Backspace' key to begin the game! Good luck! \n''')


    # re-initializing the needed variables
    win = 0
    lose = 0
    tie = 0

    # main loop to keep playing
    while True:

        # starting the game after reading the instructions
        if keyboard.read_key() == "backspace":
            print("__________________________________________________________________") # making things more asthetic and clear
            
            # a nested loop to continuously ask and evaluate the rock-paper-scissor entries
            while True:

                # calling and intializing the computer and user moves' functions
                comp_move = computer_move()
                player_move = player_choice()

                # quitting the game and showing the results of the game
                if player_move == 'q':
                    print(f"\nYou have won {win} times, lost {lose} times, and tied {tie} times against me!")
                    break

                
                # evaluating and outputting the 'rock-paper-scissor' results after the player has chosen a move
                elif player_move == 'r' and comp_move == 'rock':
                        print("It's a tie!") # in case this is the flow of the program, show the user that they lost
                        tie += 1 # in the case this is flow of the program, increment the total ties

                elif player_move == 'r' and comp_move == 'paper':
                    print("You win!")
                    win += 1

                elif player_move == 'r' and comp_move == 'scissors':
                    print("You lose!")
                    lose += 1

                elif player_move == 'p' and comp_move == 'rock':
                    print("You win!")
                    win += 1

                elif player_move == 'p' and comp_move == 'paper':
                    print("It's a tie!")
                    tie += 1

                elif player_move == 'p' and comp_move == 'scissors':
                    print("You lose!")
                    lose += 1

                elif player_move == 's' and comp_move == 'rock':
                    print("You lose!")
                    lose += 1

                elif player_move == 's' and comp_move == 'paper':
                    print("You win!")
                    win += 1

                elif player_move == 's' and comp_move == 'scissors':
                    print("It's a tie!")
                    tie += 1

                # after entering the game, if the user enters an unidentified move (not 'r' or 'p' or 's' or 'q')
                else:
                    print("You have entered an unidentified move...")
                    continue # still let the user retry again if they entered an unidentified move
        
        # condition to end the game
        elif keyboard.read_key() == "d":
            sys.exit()

        # after reading the instructions, please type the 'Backspace' to enter the game
        else:
            print("Now that you have read the instructions, please press the 'Backspace' key to play the game or \nenter 'd' to leave")
            continue


# calling the main function to let the code run
main()
# Deneo Shi 101271921

# Making the game a function
def Guessing_Game():

    # Importing needed third-party module(s)
    import random


    # Initialize the needed values
    secret_number = random.randint(1, 100)
    guessed_times = 1

    # Explaining the rules
    print("I am thinking of a number between 1 and 100.")
    print("Now... try to guess the number that I am thinking of in less than 10 guesses! Good luck!", end='\n\n')

    # Post-event-controlled loop (with Boolean Flag)
    flag = True
    while flag:  

        try:
        
            guess_number = (int(input("Which number am I thinking of? Take a guess: ")))    #prompting the user

            if guess_number > 0 and guess_number <= 100:    # Verifying that the number guessed is in the given range
            
                guessed_times += 1    #begin the counter

                if guessed_times <= 10:    #letting the game run as long as the amount of times guessed is less than 10
                    
                    # When the guess is wrong
                    if guess_number != secret_number:    
                        print("Wrong guess! You still have", str(int(11-guessed_times)), "guesses.")

                        # Giving off a hint
                        if guess_number > secret_number:
                            print("Hint: Your guess is too big. Guess a smaller number!", end='\n\n')
                            continue
                        elif guess_number < secret_number:
                            print("Hint: Your guess is too small. Guess a bigger number!", end='\n\n')
                            continue
                    
                    # When the guess is correct
                    if guess_number == secret_number:
                        print("Good guess!" "\n\n" "Congratulations, you won! You guessed my secret number in", str(guessed_times - 1) + " times!", end='\n\n\n')
                        break

                # When the amount of times guess exceeds 10     
                elif guessed_times > 10:
                    print("Wrong guess again! And... that's Game Over!!!" "\n\n" "Oops, you lost. You have ran out of your 10 guesses. The secret number that I was thinking was", str(secret_number) + ". Better luck next time ;)", end='\n\n\n')
                    flag = False
            
            # if the number guessed is not in the range
            elif guess_number < 1 or guess_number > 100:
                print("Note: Please only guess a number between 1 and 100.", end='\n\n')


        except:
            print("Please only guess integers...", end='\n\n')


# Calling the function
Guessing_Game()
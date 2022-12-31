import random, os 
from time import sleep 

leds = 150 
snake = [0,1]
food = 3 
gameboard = [int(i) for i in range(leds)] 
print(gameboard)
while True: 
    snake_head = snake[-1]
    # move the snake forward 
    snake_head += 1 
    # check if snake is max length  
    if len(snake) == leds-1: 
        print("You Won! Game over") 
        exit()
        
    # add the snake head to the array 
    snake_head = snake_head if snake_head <= (leds -1) else snake_head % leds 
    snake.append(snake_head)
    
    

#    if snake head meets the food 
    if snake[-1] == food: 
        # snake.append(food)
        food = None
        while food == None: 
            nf = random.randint(0,leds-1)
            food = nf if nf not in snake else None
    else: 
        snake.pop(0)
    gamescreen = [] 
    for x in gameboard: 
        
        if x in snake: 
            gamescreen += 'x'
        elif x == food: 
            gamescreen += '@'
        else: 
            gamescreen += '_'
                
    print(''.join(str(i) for i in gamescreen))
    sleep(.01)
    os.system('cls')
        
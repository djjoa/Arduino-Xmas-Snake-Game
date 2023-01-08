///////////////////////////////////////////////
// AutomaticSnakeXmassTree V2
// Automatic snake game using WS2811 RGB lights and FastLED. 
// I created this as an xmas project. 
// (red) snake grows when eating a piece of (green) food
// there is a small end animation when the game is finished 
// which flashes lights and creates a growing rainbow effect.
// the program loops infinitely. 
// Merry Christmas and Happy New Year 12/31/22! 
// 
///////////////////////////////////////////////
// ACKNOWLEDGEMENTS 
//////////////// Flávio Amieiro
// Thank you Flávio Amieiro! 
// Although I didn't use any of your code in this project, your examples were very helpful.
// GitHub: https://github.com/flavioamieiro
// GitHub 1d_snake: https://github.com/flavioamieiro/snake_1D
//////////////// Engineer Man 
// Second thank you to Engineer Man for the Python Snake 
// video and repo which I also used to build the MVP before converting to C++
// EM snake-game video : https://www.youtube.com/watch?v=rbasThWVb-c
// EM snake-game repo: https://github.com/engineer-man/youtube/blob/bfca0f792cee59582c8dc39841e8446352f3481f/015/snake.py
//////////////// @Random936
// @Random936 did the brunt of the work converting my Python rendition of 
// this project into C++ and helped debug new features. Thank you Sir! 
// GitHub: https://github.com/Random936
//////////////// @djjoa 
// If you are happy with this project give it a start on GitHub! 
// My GitHub: https://github.com/djjoa


///////////////////////////// MAIN //////////////////////////////
// WARNING / WARNING / WARNING 
// Ensure the correct VOLTAGE is set for the corresponding strip/string of lights
// failure to do so could fry the lights. 
#include "FastLED.h"

#define LED_NUM 250 // CHANGE THIS to the number of LEDs used in the project 
#define LED_TYPE WS2811 // CHANGE THIS to the type of LED strip 
#define COLOR_ORDER RGB // CHANGE THIS if the color's look off. 
                        // Other optional values are GRB, BRG, etc. 
                        // Cycle through different options until the strip looks correct

#define DATA_PIN 4      // CHANGE to whatever data pin you would like to use
// #define CLK_PIN 4    // NOTE: some 4 wire LED strips require this to be set
#define VOLTS 12        // WARNING! CHANGE THIS BASED ON YOUR LEDs voltage 
#define MAX_MA 6000     // CHANGE if more/less power is required. 

// Define colors 
#define RED CRGB::Red
#define BLUE CRGB::Blue
#define GREEN CRGB::Green
#define BLACK CRGB::Black
#define WHITE CRGB::White

// Define global delay to slow the animation down 
#define DELAY 15 // sets the global delay of all actions. Change to hardcoded values if you want variable delay in a function. 
class Board
{
public:
    CRGB board[LED_NUM]; // array of all lights
    int snake_pos = 1;
    int snake_len = 75;
    int food_pos = 3;
    bool done = false;

    Board()
    {
        clear();
        add_food();
        reset(); 
    }


    // Main game logic function.
    void act()
    {
        clear();
        this->board[this->food_pos] = GREEN;
        add_snake();

        // If snake head over food, eat it.
        if (this->food_pos == this->snake_pos)
        {
            this->snake_len++;
            add_food();
        }

        FastLED.show();
        this->snake_pos = (this->snake_pos + 1) % LED_NUM;

        // Game finish condition
        if (this->snake_len > LED_NUM - 1)
            done = true;
    }

    // Clear game this->board.
    void clear(){
        for (int i = 0; i < LED_NUM; i++)
        {
            // this->board[i] = '_'; //change from ascii to RGB val
            this->board[i] = BLACK; // change from ascii to RGB val
        }
    }
    // Fills the strip with a solid color
    void fill_color(uint32_t color){
        for (int i = 0; i < LED_NUM; i++){
            this->board[i] = color;
        }
    }
    // Does the flashing animation after the Snake eats every food. 
    void end_animation(){
        fill_color(RED);
        FastLED.show();
        delay(500);
        fill_color(GREEN);
        FastLED.show();
        delay(500);
        fill_color(WHITE);
        FastLED.show();
        delay(500);
        fill_color(BLUE);
        FastLED.show();
        delay(500);
        fill_color(BLACK); // reset the tree back to black before drawing the rainbow 
        FastLED.show();
        // incremential rainbow effect when the game is over
        // fills the tree one light at a time 
        for(int i=0; i < LED_NUM ; i++ ){
        fill_rainbow(board, i, 0, 255/LED_NUM );
        FastLED.show();
        delay(DELAY * 4 ); 
        }
        // NOTE UNTESTED 
        // rotates / oscolates the rainbow up the lenght of the tree after it's filled up
        for(int i=0; i < 1000 ; i++ ){
        fill_rainbow(board, LED_NUM, i % 255 , 255/LED_NUM );
        delay(DELAY ); 
        FastLED.show();}
        
      }
// sets the gameboard back to the default conditions 
void reset()
{
    this->snake_pos = 0;
    this->snake_len = 1;
    this->food_pos = 0;
    this->done = false;
}

// Add snake to game this->board
void add_snake()
{
    for (int i = 0; i < this->snake_len; i++)
    {
        if (this->snake_pos - i < 0)
        {
            this->board[(this->snake_pos - i + LED_NUM) % LED_NUM] = RED;
        }
        else
        {
            this->board[(this->snake_pos - i) % LED_NUM] = RED;
        }
    }
}

// Add food to random this->board position (not already filled with the snake).
void add_food()
{

    while (this->board[this->food_pos] == CRGB(RED))
        this->food_pos = random(LED_NUM);

    this->board[this->food_pos] = GREEN;
}
};

Board gameboard = Board(); // Initialize the gameboard
void setup()
{
    delay(1500); // safety startup delay
    FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_MA);
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(gameboard.board, LED_NUM);
    //.setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(150);
}

void loop()
{

    // Game loop.
    while (!gameboard.done)
    {
        gameboard.act();

        // Change this to make the snake move faster or slower 
        delay(DELAY);
    }
    // We won the game
    gameboard.end_animation();
    gameboard.reset();
}

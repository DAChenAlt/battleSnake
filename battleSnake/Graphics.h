//
//  Graphics.h
//  GiocoLabInf
//
//  Created by Enrico Migliorini on 15/03/14.
//  Copyright (c) 2014 Enrico Migliorini. All rights reserved.
//

//==================================================//
//                                                  //
//   Graphics has a number of drawing functions     //
//    that might then be used by other classes      //
//==================================================//

#ifndef __GiocoLabInf__Graphics__
#define __GiocoLabInf__Graphics__

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

using namespace std;

// These enums are used throughout the game

enum Direction {NORTH, EAST, SOUTH, WEST, DIRECTION_TOTAL};

enum Screens
{
    MAIN_CAMERA,
    LOWER_MENU,
    MAIN_MENU,
    BATTLE,
    NARRATION,
    SELECTION_MENU,
    TEXTURES_TOTAL
};

enum Characters
{
    FIGHTER,
    CORVETTE,
    FRIGATE,
    DESTROYER,
    CRUISER,
    EN_FIGHTER,
    EN_CORVETTE,
    EN_FRIGATE,
    EN_DESTROYER,
    EN_CRUISER,
};

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SPRITE_WIDTH = SCREEN_WIDTH/20;
const int SPRITE_HEIGHT = SCREEN_HEIGHT/15;
const int SHIP_TYPES = 5;

class Graphics {
private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    
    // NOOOOOOOOOOO I need a bidimensional array somehow. Therefore I will be able to call a sprite from gTexture[sprite][Direction] or something like that
    SDL_Texture* gTexture[TEXTURES_TOTAL];
    SDL_Texture* gAllies[SHIP_TYPES];
    SDL_Texture* gEnemies[SHIP_TYPES];
    TTF_Font* gFont;
    
public:
    Graphics();
    //Starts up SDL and creates window
    bool init();
    //Loads media
    bool loadMedia();
    //Frees media and shuts down SDL
    void close();
    //loads a texture and assigns it to an element in a texture array
    SDL_Texture* loadTexture( string path);
    //Texture from text
    SDL_Texture* loadFromRenderedText(string textureText, SDL_Color textColor);
    //Sets camera view to choice
    void setView (Screens choice, Screens &lastDisplayed);
    //Writes something from text on screen. Gives some trouble to close apparently.
    void printTextOnScreen (string txtInput, SDL_Rect* destination);
    
    // We will never be free from getters
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    // Again, when i'll have the multidimensional array or whatever, i'll get this from there
    SDL_Texture* getTexture(Screens texture);
    SDL_Texture* getSprite(Characters sprite);
    SDL_Texture* getEnFighterSprite();
    TTF_Font* getFont();
};

#endif /* defined(__GiocoLabInf__Graphics__) */
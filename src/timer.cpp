#include "timer.h"

Timer::Timer(){
    tStartTicks = 0;
    tPausedTicks = 0;
    tPaused = false;
    tStarted = false;
}

void Timer::start(){
    tStarted = true; // Start the timer
    tPaused = false; //Unpause the timer

    //Get the current clock time
    tStartTicks = SDL_GetTicks();
    tPausedTicks = 0;
}

void Timer::stop(){
    tStarted = false; // Stop the timer
    tPaused = false; //Unpause the timer

    //Clear tick variables
    tStartTicks = 0;
    tPausedTicks = 0;
}

void Timer::pause(){
    //If the timer is running and isn't already paused
    if(tStarted && !tPaused){
        tPaused = true; // Pause the timer

        //Calculate the paused ticks
        tPausedTicks = SDL_GetTicks() - tStartTicks;
        tStartTicks = 0;
    }
}

void Timer::unpause(){
    // If the timer is running and paused
    if(tStarted && tPaused){
        tPaused = false;
        tStartTicks = SDL_GetTicks() - tPausedTicks; // Reset the starting ticks
        tPausedTicks = 0; //Reset the paused ticks
    }
}

Uint32 Timer::getTicks(){
    Uint32 time = 0;

    if(tStarted){
        if(tPaused){
            time = tPausedTicks; // Return the number of ticks when the timer was paused
        } else {
            time = SDL_GetTicks() - tStartTicks; //Return the current time minus the start time
        }
    }

    return time;
}

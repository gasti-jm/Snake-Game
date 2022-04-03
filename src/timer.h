#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL.h>

class Timer{
    private:
        Uint32 tStartTicks;
        Uint32 tPausedTicks;
        bool tPaused;
        bool tStarted;

    public:
        Timer();

        void start();
        void stop();
        void pause();
        void unpause();

        Uint32 getTicks();
        bool isStarted();
        bool isPaused();

};

#endif

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

#include "songstruct.h"

int pinnumber = 13;
int dir = -1;
const int keephightime = 40;



int JingleBellsNotes[48] = {2, 2, 2, 2, 2, 2, 2, 4, 0, 1, 2,
                  3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 2, 1,
                  2, 2, 2, 2, 2, 2, 2, 4, 0, 1, 2,
                  3, 3, 3, 3, 3, 2, 2, 2, 4, 4, 3, 1, 0 };
float JingleBellsNoteLengths[48] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 
                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 
                  1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 
                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4 };      
//http://www.8notes.com/scores/2811.asp?ftype=gif
int CarolOfTheBellsNotes[135] = {5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3,
                                 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 
                                 5, 4, 5, 3, 7, 6, 7, 5, 7, 6, 7, 5, 7, 6, 7, 5, 7, 6, 7, 5, 
                                 3, 3, 3, 2, 1, 7, 7, 7, 6, 5, 6, 6, 6, 7, 6, 5, 4, 5, 3, 0, 1, 2, 3, 4, 5,
                                 6, 7, 6, 5, 0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 
                                 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3, 5, 4, 5, 3};
float CarolOfTheBellsNoteLengths[135] = {1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1,
                                         1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 
                                         1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 
                                         1, .5, .5, .5, .5, 1, .5, .5, .5, .5, 1, .5, .5, .5, .5, 1, .5, .5, 1, .5, .5, .5, .5,
                                         .5, .5, 1, 1, .5, .5, .5, .5, .5, .5, 1, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1,
                                         1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 1};
                                         
//http://www.8notes.com/scores/530.asp?ftype=gif
int WeWishYouAMerryChristmasNotes[54] = {0, 3, 3, 4, 3, 2, 1, 1, 1, 4, 4, 5, 4, 3, 2, 2, 2, 5, 5, 6, 5, 4, 
                                      3, 1, 0, 0, 1, 4, 2, 3, 0, 3, 3, 3, 2, 2, 3, 2, 1,
                                      0, 4, 5, 4, 4, 3, 3, 7, 0, 0, 0, 1, 4, 2, 3
                                      };
float WeWishYouAMerryChristmasNoteLengths[54] = {1, 1, .5, .5, .5, .5, 1, 1, 1, 1, .5, .5, .5, .5, 1, 1, 1, 1, .5, .5, .5, .5, 
                                             1, 1, .5, .5, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 
                                             2, 1, 1, .5, .5, .5, .5, 1, 1, .5, .5, 1, 1, 1, 2
};

//http://www.8notes.com/scores/411.asp?ftype=gif
int SilentNightNotes[] = {4, 5, 4, 2, 4, 5, 4, 2   
};

//http://www.8notes.com/scores/1533.asp?ftype=gif
int OChristmasTreeNotes[] = {0, 3, 3, 3, 4, 5, 5, 5, 5, 4, 5, 6, 2, 4, 3, 
                             7, 7, 5, 7, 7, 7, 6, 6, 6, 6, 4, 7, 6, 6, 5, 5, 
                             0, 3, 3, 3, 4, 5, 5, 5, 5, 4, 5, 6, 2, 4, 3, 
                             0, 3, 3, 3, 4, 5, 5, 5, 5, 4, 5, 6, 2, 4, 3
};
float OChristmasTreenoteLengths[] = {};

//http://www.8notes.com/scores/9871.asp?ftype=gif
int JoyToTheWorldNotes[57] = {7, 6, 5, 4, 3, 2, 1, 0, 4, 5, 5,
                            6, 6, 7, 7, 7, 6, 5, 4, 4, 3, 2, 7, 7, 6, 5, 4,
                            4, 4, 2, 2, 2, 2, 2, 2, 3, 4, 3, 2, 1, 1, 1, 1, 2, 
                            3, 2, 1, 0, 7, 5, 4, 3, 2, 3, 2, 1, 0
};
float JoyToTheWorldNoteLenghts[57] = {1, 1.5, .5, 1.5, .5, 1, 1, 1.5, .5, 1.5, .5, 
                                    1.5, .5, 1.5, .5, .5, .5, .5, .5, .75, .25, .5, .5, .5, .5, .5, .5,  
                                    .75, .25, .5, .5, .5, .5, .5, .25, .25, 1.5, .25, .25, .5, .5, .5, .25, .25,
                                    1.5, .25, .25, .5, 1, .5, .75, .25, .5, .5, 1, 1, 2
};

//http://www.8notes.com/scores/576.asp?ftype=gif
arduino_song JingleBells = {
                  JingleBellsNotes, 
                  JingleBellsNoteLengths, 
                  120, 48 };
arduino_song CarolOfTheBells = { CarolOfTheBellsNotes, CarolOfTheBellsNoteLengths, 180, 135 };
arduino_song WeWishYouAMerryChristmas = {WeWishYouAMerryChristmasNotes, WeWishYouAMerryChristmasNoteLengths, 80, 54 };
arduino_song JoyToTheWorld = {JoyToTheWorldNotes, JoyToTheWorldNoteLenghts, 110, 57};

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
  pinMode(12, OUTPUT);     
  pinMode(11, OUTPUT);     
  pinMode(10, OUTPUT);     
  pinMode(9, OUTPUT);     
  pinMode(8, OUTPUT);     
  pinMode(7, OUTPUT);     
  pinMode(6, OUTPUT);     
}

void loop() {
  
  PlaySong(JingleBells);
  PlaySong(CarolOfTheBells);
  PlaySong(WeWishYouAMerryChristmas);
  PlaySong(JoyToTheWorld);
  
}

void PlaySong(arduino_song songtoplay)
{
  float delayNextNote = (1 / ((float)songtoplay.tempo / 60)) * 1000;
  for (int note = 0; note < songtoplay.NumberOfNotes; note++ )
  {
    int noteValue = pinnumber - songtoplay.songNotes[note];
    digitalWrite(noteValue, HIGH);
    delay(keephightime);
    digitalWrite(noteValue, LOW);
    
    float waitforNextNote = (delayNextNote * songtoplay.noteLength[note]) - keephightime;
    if (waitforNextNote > 0)
    {
      delay((int)waitforNextNote);
    }
  }

}

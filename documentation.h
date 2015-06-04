#ifndef DOCUMENTATION
#define DOCUMENTATION

/** @file Documentation.h
 * @brief Contains an overall documentation summary/overview

    I will include over all documentmentation in this file. It will not go into detail of any files.

*/


/**
  @mainpage Hero Quest v1
  @author Alec Chiu

  @section disclaimer Disclaimer
  I have opted not to include certain features such as background music and icons due to operating
  system dependent factors.

  @section description Description
  Hero Quest is my final submission for the PIC 10C final project. I had originally thought we would
  have longer than we were given to come up with the idea for our projects, but I had ultimately had
  to decide what I wanted to do as there was a homework submission based on what our idea is. In my
  panic, I had come up with the cheesy and corny game known as Hero Quest. It is loosely based on the
  idea of the popular game for the Playstation 2 and 3, Shadow of the Colossus. Shadw of the Colossus
  is a game based purely off boss encounter, each with unique mechanics. For my game, I have simulated
  this mechanic by giving each boss unique mechanics.

  @section Boss_Mechanics Boss Mechanics
  For this version of Hero Quest, I have constructed three bosses each with their own mechanic. I have
  listed each bosses mechanic below. \n
  \n
  Boss Mechanics: \n
  - Left Boss: The boss hides behind his electric wall. One of the four switches will temporarily
  deactivate the wall to make the boss vulnerable. \n
  - Right Boss: The boss is immune to normal arrows. In order to defeat the boss, a fire arrow must be
  used. A fire field randomly moves up and down the map. In order to generate a fire arrow, the player
  must shoot an arrow through the fire field at the boss. \n
  - Top Boss: This boss summons slime minions. He is immune to arrow attacks until all his minions have
  been defeated. He can spawn a total of ten slime minions.

  @section valgrind Memory Analysis
  I have noticed after repeated use of the game there have been slowdowns in terms of responsiveness
  and the game appears to be lagging. Due to this, I ran a memory analysis of the game using Valgrind.
  However, Valgrind was unable to detect any major memory leaks within the code.

  @section future Future Directions
  There are many directions I would take this project further as there are many aspects of Qt that I have
  yet to explore. I dabbled in sounds and audio near the end of the project and it definitely would have
  been fun to explore that further. Another area I had briefly dabbled in for an earlier assignment was
  the concept of animation in Qt. I would definitely have been fun to have dynamic images rather than
  static images simply being repositioned. In addition, it would have been interesting to come up with
  more unique and challenging boss mechanics and encounters. Additionally, it would be interesting to
  implement operating system dependent features such as icons and background music.

  @section Closing_Thoughts Closing Thoughts
  Building this project has induced a lot of stress for me throughout the quarter, but it has been a
  lot of fun exploring Qt and GUI based programming. While I think my game is extremely corny and
  cheesy, I had a lot fun programming and discovering new mechanics and features of Qt in order to
  create it. I hope you enjoy my work for the quarter.
  */

#endif // DOCUMENTATION


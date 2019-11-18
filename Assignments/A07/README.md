##  Program 4 - A-Star Monster Hunter 
#### Due: Monday Dec 2<sup>nd</sup>

#### Overview

You will implement the A-Star algorithm allowing a set of monsters to find some character and kill him. We will be using a simple console based app with unicode characters from [here](https://emojiterra.com/categories/) . I tested these characters out and they print ok. The only problem is they are "wide" and take up 2 spaces on a console. 
But they do print on a console as well as the repl.it console. So, if you're going to use Visual Studio and they don't work, use repl.it. 

#### Level One

I want you to start by placing a "**Monster**" ([🦖](https://emojiterra.com/t-rex/)) randomly on the screen/game-board somewhere and make it stationary. Then after placing a "**Hunter**" ([🤺](https://emojiterra.com/person-fencing/)) on the game-board it should start moving towards the Monster. You can simulate animation with console apps by using a "clear screen" then redrawing the board after updating the location of each entity. After the Hunter reaches your Monster, go to level two. 

#### Level Two

On this level when the **Hunter** reaches your **Monster**, transport him to another random location. Your **Hunter** should start tracking him again. After your **Monster** gets reached a total of three times, go to level 3.

#### Level Three

On this level add a random number of Hunters (2-6 or so) that will track your Monster. They should all go towards the Monster. When first Hunter reaches the Monster, then randomly relocate the Monster until it gets reached a total of 5 times. 

#### Level Four

Add barriers to your **GameBoard**. There should be a significant number (20% of the board) that has large contiguous chunks of barrier to go around. Your hunter will need to go around the barriers to get the single monster. 

#### Level Five

Add multiple moving monsters to your board with barriers. And make your Hunter "evade" or move away from the monsters. 



# CodeMode
In code mode.

# My Repository
This repository is pretty self-explanatory: I'm in code mode.
When I want to create a project and code off, this repository is where it will go.

# Project Playing XI (Prototype)
Starting off the repository, is my project "Playing XI" up for evaluation as my CSE project.

#
This project allows the user to enter and store records and demographic information of cricket players which they can access.

The user can segregate the cricket players into their respective playing role and enter the stats accordingly.

The players are organized based on a points system calculated using their statistics. Additionally, the algorithm employs a smart calculation process which factors in the players' performances in their last 5 matches.

The program then generates the best possible playing XI in a 5-2-4 (Batsmen-Allrounders-Bowlers) format using the estimated value of a player based on the smart algorithm.

The program also allows the user to update the records of any player and then re-run the code to generate an updated playing XI.

#
The code factors in several aspects (based on cricket in real life) besides straightforward statistics:
  
  -Younger players are preferred as they have more potential.
  
  -Last 5 match performances are given additional weightage to evaluate current form.
  
  -Average and Strike Rate are weighted systemmatically for the players based on their position in the batting order.
  
  -Number of Man of the Match awards won by the player is taken into consideration to add to the player's 'match-winning' capability.
  
  -Allrounders' values are estimated aggregating the bowling and batting strength they bring to the game.

#
This project is only the prototype and the source code only involves the fundamentals. This code employs the concepts in my CSE course for object-oriented programming such as inheritance, polymorphism and switch case.

The project will later include several updates. Some include: 
  
  -Reading player records from imported files rather than entering each detail.
  
  -Accounting for left-right batting combination advantage.
  
  -Includung the advantageous ratio of pace to spin bowling based on the field conditions.
  
  -Factoring in fielding proficiency.
  
  -Changing the ideal 5-2-4 format if required based on the pitch conditions and the opposition.
  
This project when launched after the updates, could generate the best playing XI instantly just off of records and provide a great assist to selectors.

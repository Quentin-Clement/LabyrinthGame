★ For this project, you’ll have to create a text-based 
console game in C.
★ The game should demonstrate programming proficiency, 
creativity, and adherence to the specified guidelines.
★ You can collaborate with others but, in the end, it 
should be your own work.

★ Game Concept: "Lost in the Labyrinth"
★ Your task is to develop a text-based adventure game set 
in a mysterious labyrinth.
★ The player starts at the entrance and must navigate 
through the maze, encountering challenges, collecting 
treasure, and making decisions that affect the outcome.

★ Console Interface:
○ Strictly use the console for input and output.
○ Keep the display clean and easy to read, providing 
clear instructions to the player.
★ Navigation:
○ Use a simple grid-like map. Every cell is a room.
○ Move only in four directions.
○ Include dead ends and teleport rooms.

★ Game Mechanics:
○ Implement a turn-based system.
○ Include at least three types of actions (e.g., 
explore, fight, move)
○ PLUS - Include random events
○ The player has HP and a simple inventory to collect 
treasure, etc.
★ Saving
○ You should be able to save and load the current 
state of the program (variable)

★ Winning condition:
○ The player reaches the final room or collects all 
the treasure.
★ Losing condition:
○ The player loses all their HP, or they fall into a 
trap (add your own)

## Start

The player will start with 100 HP, 50 golds and 0 equipment. He will spawn in a lobby room where he will be able to buy equipment to a merchant.

## Equipments

The player will be able to buy 3 types of equipment:
- weapons
- armors
- spells

### Weapons

- sword: 40 golds, 25 damage, speed 5
- axe: 100 golds, 50 damage, speed 3
- bow: 300 golds, 100 damage, speed 1

### Armors

One gold spent equal one armor point. You can buy 10 by 10 and it can go over 100 armor points.

### Spells

- red: 10, increase damages by 50% for 3 turns
- blue: 
- purple: 200, you will get teleported to the lobby room

## Rooms

### Lobby

The lobby is the room where the player will spawn. He will be able to buy equipment to the merchant.

### Corridors

They are just here to connect the rooms together. They can be multiple tiles long but they will always be 1 tile wide and it will always be a straight line.

### Rooms

A room can contain 4 types of things:
- a wolf
- a
- a
- a chest with 25
- nothing


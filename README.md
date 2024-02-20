# Zork

Wellcome to my mini and personalised experience of Zork.

The game follows a boy who needs to go to school, but he lost his key to get in and out of the house. To find the keys, you'll need to investigate the house and follow the clues that your brother, mother, and a mysterious man will give you. 

Will you be able to get out of the house? Or will you arrive late at school?

## How to play
In order to know how to play my version of Zork, you need to know all the commands available in the game and how to use them.

### List of commands

- `NORTH / N, SOUTH / S, EAST / E, WEST / W, UP / U, DOWN / D` ->  Helps you move through the game in the direction you specify. For example: `>> NORTH`, `>> S`.
- `LOOK / L` -> You look in the actual room and identify all the objects you can interact with.
- `INVENTORY / I` -> It shows all the items you have in your inventory.
- `TAKE [item]` -> You collect the specified item that is in the room and put it in your inventory. For example: `>> TAKE Apple` .
- `TAKE [item] FROM [container]` -> You collect the specified item that is inside a container. The container does not require to be in your inventory. For example: `>> TAKE Bottle FROM Backpack` .
- `DROP [item]` -> You leave the specified item that is in your inventory on the floor. For example: `>> DROP Bottle` .
- `PUT [item] IN [container]` -> You put the item specified that is in your inventory to a container. The container does not require to be in your inventory. For example: `>> PUT Apple IN Backpack` .
- `OPEN [container]` -> You see a list of all the items inside the container. The container does not require to be in your inventory. For example: `>> OPEN backpack` .
- `OPEN [Name of the door]` -> You open the specified door. It requires to have the corresponding key in your inventory. Be aware that all doors have **two** words in its name. For example: `>> OPEN Matias's door` .
- `TALK` -> You talk with the person that shares the same room as you. Don't try to talk alone, you are not crazy, right?
- `QUIT / Q` -> You exit the game. For example: `>> Q` .

### Map

In here you'll find the map of the game. It will help you to not getting lost.

![Zork](https://github.com/MarcLopezS/Zork/assets/88272783/10572797-255a-4d7c-969d-58b035c9ed1d)

I'm not showing you the locked doors because it's a surprise. If you want to know them, it's in the following spoiler tag.

<details>
  <summary>Spoiler warning</summary>

  The locked doors are on Mom's Bedroom, Matias's Bedroom and Front entrance. 
  
</details>

### Advice

For the first experience of the game, I recommend to **talk** as much as you can with the people you find in specific areas. They give you important clues that'll help you follow the course of the main path. 

### Finish the game
In order to not spoil the fun, if you want to play it, I'll put a spoiler warning for those that do not want to look at it. 

In this one shows you the map with all the keys located and all the doors locked

<details>
  <summary>Spoiler warning</summary>

![Zork_allKeys](https://github.com/MarcLopezS/Zork/assets/88272783/59b421f5-1cf5-4726-9b4e-592b53d51dcb)


</details>

And, in this one, explains all the commands you have to use in order to complete the game.

<details>
  <summary>Spoiler warning</summary>
 
 - You start in your bedroom. Use `S, E, TAKE key1, W, OPEN Mom's door, UP`.
 - You are now in mother's bedroom. Now use `TAKE key2, DOWN, W, OPEN Matia's door`.
 - You are now in brother's room. Use `TAKE key3, E, E, OPEN house entrance, S`.

   With this, you'll arrive at the end of the game.
</details>

## Experience doing this project

At first, the game was so difficult due to the lack of clues that the game itself was giving you. I thought that the experience of the player will be painful and also hard to reach through the end. Because of that, I though about implementing dialogues with specific characters in order to help the player have a better experience, don't loose track of the main path and, the most important, **FUN!**.

My thought about implementing dialogues with NPCs was a bit complex due to the texts with the requirement that I imposed myself. That one was reading from an external document and then store all the data within the code. I prefered to use JSON, because it's a format that I like to treat with data. Then I had to approach how could I use that data and make the characters reach though their specific dialogs. For that, I approached to do a controller that controls all the dialogues, depending on who NPC was speaking at the moment. In the end, I made it possible to implement this feature that it's very interesting and very useful in this game. 

What I struggled was at first about how to relate the different types of entities inside the game. However, during the process of understanding and the requirements of each class I arrived at the conclusion and get the structure that now the code has. Thanks to that, I was able to make profit of the class Entity to get to the final results I wanted.  

## Contact information

**@author** [Marc López Serrano](https://www.linkedin.com/in/marc-l%C3%B3pez-491132203/) 

**@github repository** click [here](https://github.com/MarcLopezS/Zork) to get to the repository page of this project.


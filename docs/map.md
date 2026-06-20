# Map

See the structure of the [map](../include/map.h#L7) used in the [game](../include/game.h#L32).

We use different types of maps for different purposes in the game.

## Start by the main one,

![Map](../assets/imgs/map.png)

It's only for the player to see the map of the game, and it is used to display the current position of the player and other important elements in the game world.

## Next, we have the collision map,

![Collision Map](../assets/imgs/collision3.png)

Which is used to determine if the player can move to a certain position or not.

### Color Codes

- **White**: Walkable area
- **Black**: Non-walkable area
- **Red**: Breakable wall
- **Blue**: Jumpable wall

This map is never displayed to the player, but it is used internally by the game to determine if the player can move to a certain position or not.

We use color detection to determine if the player can move to a certain position or not. The color of the pixel at the player's position is compared with the color codes defined above to determine if the player can move to that position or not.

## Finally, we have the isometric map,

![Isometric Map](../assets/imgs/iso3.png)

This map is used to display the game world in an isometric perspective. It is used to give the player a better view of the game world and to make the game more visually appealing.

It's **always** displayed after the main map and the player, so that the player can see the game world in an isometric perspective while still being able to see the main map and the player's position.
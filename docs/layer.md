# Layer Management in Game

It's all about one int `game->menu` [here](../include/game.h#L39).

Shared between every function with the `game` struct, this int is used to determine which layer of the game is currently being displayed. The value of `game->menu` can be set to different integers to represent different layers, such as the main menu, settings menu, or in-game HUD.

Each display has its **own** menu code, which is responsible for rendering the appropriate elements on the screen based on the current value of `game->menu`. For example, when `game->menu` is set to 0, the main menu is displayed, while a value of 6 might correspond to the settings menu.

The display layer isn't just an unique identifier for the current menu; it can also be used to manage multiple states of display simultaneously. By using multiples of 10 and division by 10, different display states can be stacked and managed effectively. This allows for a more complex and dynamic user interface, where different layers can be shown or hidden based on user interactions or game events.

Example of how to use `game->menu` to manage display layers:

```c
// Check if the current menu layer is the settings menu (6) and the sub-layer is 0
if ((game->menu / 10) % 10 != 6 || (game->menu % 10) != 0)
        return;

// Set the current menu layer to the settings menu (6) and the sub-layer to 1
game->menu = 61; // 6 for settings menu, 1 for sub-layer
```

Each display layer are **responsible** for rendering its **own** elements and handling user input specific to that layer. This modular approach allows for easier maintenance and scalability of the game's user interface, as new layers can be added without affecting existing ones.

# Network

See the structure of the [network](../include/network.h#L7) used in the [game](../include/game.h#L47).

Playing solo is fun, but playing with friends is even better!

The network module allows players to connect and play together in a multiplayer environment. It handles the communication between clients and the server, ensuring that game state is synchronized across all connected players.

It use **sfTcpSocket** for network communication, which provides a reliable and efficient way to send and receive data over the network.

Players can **only** see each other. No interaction is possible between players, such as trading or combat.

Mobs and items **are not synchronized** between players. Each player has their own instance of mobs and items, which means that the game state for these entities is not shared across clients. This design choice simplifies the network implementation and reduces potential issues with synchronization.

Only **name** and **position** of players are synchronized between clients. This allows players to see each other's avatars and movements in the game world, creating a sense of presence and interaction without the complexity of full entity synchronization.

A TCP connection is established at the beginning of the game, if it's impossible to connect to the server, the game will be played in solo mode.

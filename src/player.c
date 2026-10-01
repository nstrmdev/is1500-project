#include "../include/player.h"

// Moves the player.
void move_player(Player* player, Vec2 input) {
  // Update player velocity
  player->velocity.x = input.x * player->movement_speed;
  player->velocity.y = input.y * player->movement_speed;

  // Update player position
  player->position.x = player->position.x + player->velocity.x;
  player->position.y = player->position.y + player->velocity.y;
}

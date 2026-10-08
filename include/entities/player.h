#ifndef PLAYER_H
#define PLAYER_H

#include "../game_math.h"

// Holds our player settings.
typedef struct {
  // Movement constants
  float max_speed;
  float acceleration;
  float friction;
} PlayerConfig;

// Represents our player.
typedef struct {
  Vec2 position;
  Vec2 velocity;
} Player;

// Function declarations.
void player_move(Player* p, const PlayerConfig* cfg, Vec2 input_dir, float dt);
Player default_player();
PlayerConfig default_player_config();

#endif

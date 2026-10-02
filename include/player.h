#ifndef PLAYER_H
#define PLAYER_H

#include "game_math.h"

// Holds our player settings.
typedef struct {
  // Movement constants
  const float MAX_SPEED;
  const float ACCELERATION;
  const float FRICTION;
} PlayerConfig;

// Represents our player.
typedef struct {
  Vec2 position;
  Vec2 velocity;
} Player;

// Function declarations.
void move_player(Player* p, PlayerConfig p_cfg, Vec2 input_dir);

#endif

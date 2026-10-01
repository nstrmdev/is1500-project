#include "game_math.h"

// Maybe we want to move the player settings into
// a PlayerConfig struct or something like that?

// Represents our player.
typedef struct {
  Vec2 position;
  Vec2 velocity;
  float movement_speed;
} Player;

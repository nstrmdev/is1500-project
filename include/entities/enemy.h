#ifndef ENEMY_H
#define ENEMY_H

#include "../game_math.h"
#include "player.h"

// Holds an enemy type config
typedef struct {
  float speed;
} EnemyConfig;

// Represents an enemy.
//
// TODO: Make every enemy hold a specific config,
// then we should be able to have different enemy types.
typedef struct {
  Vec2 position;
  Vec2 velocity;
} Enemy;

// Function declarations.
void enemy_move(Enemy* e, const EnemyConfig* cfg, Vec2 move_dir);

#endif

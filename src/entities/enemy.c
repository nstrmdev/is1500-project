#include "../../include/entities/enemy.h"
#include "../../include/entities/player.h"
#include "../../include/game_math.h"

// Returns a normalized direction vector toward the player.
Vec2 enemy_get_move_dir(Enemy* e, Player* p) {
  return vec2_normalize(vec2_subtract(p->position, e->position));
}

// Moves the enemy towards the player.
void enemy_move(Enemy* e, const EnemyConfig* cfg, Vec2 move_dir) {
  e->velocity = vec2_scale(move_dir, cfg->speed);
  e->position = vec2_add(e->position, e->velocity);  // vec2_scale(e->velocity, dt)
}

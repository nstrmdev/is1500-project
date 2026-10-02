#include "../include/player.h"

// Returns true if the player is moving.
static int is_moving(const Player* p) {
  return p->velocity.x != 0 || p->velocity.y != 0;
}

// Calculate and return the player velocity.
static float calculate_velocity(float vel, const PlayerConfig* cfg, float dir) {
  if (dir != 0) {
    // Apply acceleration.
    return move_toward(vel, cfg->MAX_SPEED * dir, cfg->ACCELERATION);  // * dt
  } else {
    // Apply friction.
    return move_toward(vel, 0, cfg->FRICTION);  // * dt
  }
}

// Sets the player velocity and position.
void apply_movement(Player* p, const PlayerConfig* cfg, Vec2 input_dir) {
  // Set player velocity.
  p->velocity.x = calculate_velocity(p->velocity.x, cfg, input_dir.x);
  p->velocity.y = calculate_velocity(p->velocity.y, cfg, input_dir.y);

  // Update player position.
  // TODO: Scale velocity by delta time.
  p->position.x += p->velocity.x;  // * dt
  p->position.y += p->velocity.y;  // * dt
}

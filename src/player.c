#include "../include/player.h"

// Calculate and return the player velocity.
static float calculate_velocity(float vel, PlayerConfig p_cfg, float dir) {
  // TODO: Scale acceleration by delta time.
  return move_toward(vel, p_cfg.MAX_SPEED * dir, p_cfg.ACCELERATION);  // * dt
}

// Sets the player velocity and position.
void apply_movement(Player* p, PlayerConfig p_cfg, Vec2 input_dir) {
  // Set player velocity.
  p->velocity.x = calculate_velocity(p->velocity.x, p_cfg, input_dir.x);
  p->velocity.y = calculate_velocity(p->velocity.y, p_cfg, input_dir.y);

  // Update player position.
  // TODO: Scale velocity by delta time.
  p->position.x += p->velocity.x;  // * dt
  p->position.y += p->velocity.y;  // * dt
}

#include "../include/player.h"
#include "../include/game_math.h"

// Returns true if the player is moving.
static int is_moving(const Player* p) {
  return p->velocity.x != 0 || p->velocity.y != 0;
}

// Calculate and return the player velocity.
//
// TODO: Make sure that we normalize the input direction when making that,
// otherwise diagonal movement will be sqrt(2) faster.
static Vec2 calculate_velocity(Vec2 vel, const PlayerConfig* cfg, Vec2 input_dir) {
  // Player is attempting to move.
  if (vec2_get_length_squared(input_dir) > 0.0f) {
    // Apply acceleration.
    return vec2_move_toward(vel, vec2_scale(input_dir, cfg->max_speed), cfg->acceleration);  // * dt
  } else {
    // Apply friction.
    return vec2_move_toward(vel, (Vec2){0.0f, 0.0f}, cfg->friction);  // * dt
  }
}

// Sets the player velocity and position.
void player_move(Player* p, const PlayerConfig* cfg, Vec2 input_dir) {
  // Set player velocity.
  p->velocity = calculate_velocity(p->velocity, cfg, input_dir);

  // Update player position.
  //
  // TODO: Scale velocity by delta time.
  p->position = vec2_add(p->position, p->velocity);
}

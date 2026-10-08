#include "../../include/entities/player.h"
#include "../../include/game_math.h"
#include "../../platform/dtekv-lib.h"

// Returns true if the player is moving.
static int is_moving(const Player* p) {
  return p->velocity.x != 0 || p->velocity.y != 0;
}

// Calculate and return the player velocity.
//
// TODO: Make sure that we normalize the input direction when making that,
// otherwise diagonal movement will be sqrt(2) faster.
static Vec2 player_calculate_velocity(Vec2 vel, const PlayerConfig* cfg, Vec2 input_dir, float dt) {
  if (vec2_get_length_squared(input_dir) > 0.0f) {
    return vec2_move_toward(vel, vec2_scale(input_dir, cfg->max_speed), cfg->acceleration * dt);
  } else {
    // Apply friction.
    return vec2_move_toward(vel, (Vec2){0.0f, 0.0f}, cfg->friction * dt);
  }
}

// Sets the player velocity and position.
void player_move(Player* p, const PlayerConfig* cfg, Vec2 input_dir, float dt) {
  p->velocity = player_calculate_velocity(p->velocity, cfg, input_dir, dt);

  // TODO: Scale velocity by delta time.
  p->position = vec2_add(p->position, vec2_scale(p->velocity, dt));
}

// Creates a default player.
Player default_player() {
  Player p;

  p.position = (Vec2){160.0f, 120.0f};
  p.velocity = (Vec2){0.0f, 0.0f};

  print("[INFO] Player created...\n");
  return p;
}

PlayerConfig default_player_config() {
  PlayerConfig p_cfg;

  p_cfg.max_speed = 50;
  p_cfg.acceleration = 30;
  p_cfg.friction = 100;

  return p_cfg;
}

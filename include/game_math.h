#ifndef GAME_MATH_H
#define GAME_MATH_H

// Represents a two dimensional vector.
typedef struct {
  float x;
  float y;
} Vec2;

// Linear interpolation between two points (a, b).
static inline float lerp(float a, float b, float t) {
  return a + (b - a) * t;
}

// Move current toward target with a fixed step.
static inline float move_toward(float current, float target, float step) {
  float difference = target - current;

  if (difference > step) {
    return current + step;
  }

  if (difference < -step) {
    return current - step;
  }

  return target;
}

/*
  This is the fast inverse square implementation from the
  Quake III engine, it returns an approximation of 1/sqrtf(num).

  Because we need to do bitwise calculations on a float, we
  use a union here to represent the value and bits seperately.

  This lets us manipulate the bit representation, without
  numerically converting the value to an integer.

  More info is available here:
  https://en.wikipedia.org/wiki/Fast_inverse_square_root
*/
static inline float inverse_sqrt(float num) {
  const float threehalfs = 1.5f;

  float x2 = num * 0.5F;
  float y = num;

  union {
    float value;
    unsigned int bits;
  } data = {.value = y};

  // wtf??
  data.bits = 0x5f3759df - (data.bits >> 1);
  y = data.value;

  y = y * (threehalfs - (x2 * y * y));

  return y;
}

// Get the length of a vector.
static inline float vec2_get_length(Vec2 v) {
  // 1/sqrt(v) * v = sqrt(v)
}

// Move a vector toward a target vector with a fixed time step.
static inline Vec2 vec2_move_toward(Vec2 current, Vec2 target, float step) {
  // float difference =
}

#endif

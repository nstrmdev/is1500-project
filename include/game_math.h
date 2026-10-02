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

#endif

#ifndef VECTOR3F_HPP
#define	VECTOR3F_HPP

struct	Vector3f {
  float	x;
  float	y;
  float	z;

  Vector3f(void) : x(0.0f), y(0.0f), z(0.0f) {
  }

  Vector3f(float x, float y, float z) : x(x), y(y), z(z) {
  }

};

#endif	/* VECTOR3F_HPP */


#pragma once

template <typename T>
class Vector3D
{
public:
	T x, y, z, modulo;

	Vector3D(T x, T y, T z) :x(x), y(y), z(z) {
		modulo = sqrt(x * x + y * y + z * z);
	}

	Vector3D() :x(0), y(0), z(0), modulo(0) {}

	Vector3D operator=(const Vector3D& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return this;
	}

	Vector3D operator+(const Vector3D& v) {
		return Vector3D(v.x + x, v.y + y, v.z + z);
	}
	Vector3D operator-(const Vector3D& v) {
		return Vector3D(x -v.x, y -v.y, z -v. z);
	}
	Vector3D operator*(const Vector3D& v) {
		return Vector3D(x * v.x, y * v.y, z * v.z);
	}
	Vector3D operator*(T a) {
		return Vector3D(x * a, y *a, z * a);
	}

	Vector3D cross(const Vector3D& v) {
		return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y, y * v.x);
	}

	int module() {
		return modulo;
	}

	void normalize() {
		x = x / modulo;
		y = y / modulo;
		z = z / modulo;
	}
};


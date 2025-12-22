#pragma once
#include "raylib.h"

#include <cmath>

inline constexpr Vector2 operator+(const Vector2& a, const Vector2& b)
{
    return { a.x + b.x, a.y + b.y };
}

inline constexpr Vector2 operator-(const Vector2& a, const Vector2& b)
{
    return { a.x - b.x, a.y - b.y };
}

inline constexpr Vector2 operator*(const Vector2& v, float s)
{
    return { v.x * s, v.y * s };
}

inline constexpr Vector2 operator*(const Vector2& v, const Vector2& s)
{
    return { v.x * s.x, v.y * s.y };
}

inline constexpr Vector2 operator*(float s, const Vector2& v)
{
    return v * s;
}

inline constexpr Vector2 operator/(const Vector2& v, float s)
{
    return { v.x / s, v.y / s };
}

inline constexpr Vector2 operator-(const Vector2& v)
{
    return { -v.x, -v.y };
}

inline float Length(const Vector2& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

inline Vector2 Normalize(const Vector2& v)
{
    float len = Length(v);
    return (len > 0 ? Vector2{ v.x / len, v.y / len } : Vector2{ 0,0 });
}

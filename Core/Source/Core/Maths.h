#pragma once
#include "raylib.h"

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
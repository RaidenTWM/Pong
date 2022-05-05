#include "Ball.h"
#include "raylib.h"

Ball::Ball()
{
}

float Ball::GetX()
{
	return x;
}
float Ball::GetY()
{
	return y;
}
float Ball::GetRadius()
{
	return rad;
}

void Ball::Move()
{
	x += xSpeed * GetFrameTime();
	y += ySpeed * GetFrameTime();
	if (y + rad > GetScreenHeight())
	{
		y = GetScreenHeight() - rad;
		ySpeed *= -1;
	}
	if (y - rad < 0)
	{
		y = 0 + rad;
		ySpeed *= -1;
	}
	if (x + rad > GetScreenWidth())
	{
		x = GetScreenWidth() - rad;
		xSpeed *= -1;
	}
	if (x - rad < 0)
	{
		x = 0 + rad;
		xSpeed *= -1;
	}
}

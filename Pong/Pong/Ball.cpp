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
float Ball::GetSpeedX()
{
	return xSpeed;
}
float Ball::GetSpeedY()
{
	return ySpeed;
}
void Ball::InvertSpeedX()
{
	xSpeed *= -1;
}
void Ball::InvertSpeedX(float yy, float h)
{
	xSpeed *= -1.1;
	if (xSpeed < 0)
	{
	ySpeed = (y - yy) / (h / 2) * -xSpeed;
	} else { ySpeed = (y - yy) / (h / 2) * xSpeed; }
}
void Ball::InvertSpeedY()
{
	ySpeed *= -1;
}
void Ball::Stop()
{
	x = 640;
	y = 360;
	xSpeed = 0;
	ySpeed = 0;
}
void Ball::Start()
{
	xSpeed = -300;
	ySpeed = -300;
}

int Ball::OnUpdate()
{
	x += xSpeed * GetFrameTime();
	y += ySpeed * GetFrameTime();
	if (y + rad > GetScreenHeight())
	{
		y = GetScreenHeight() - rad;
		InvertSpeedY();
	}
	if (y - rad < 0)
	{
		y = 0 + rad;
		InvertSpeedY();
	}
	if (x + rad > GetScreenWidth() - 10)
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		InvertSpeedX();
		return -1;
	}
	if (x - rad < 10)
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		InvertSpeedX();
		return 1;
	}
	return 0;
}
void Ball::OnDraw()
{
	DrawCircle(GetX(), GetY(), GetRadius(), WHITE);
}
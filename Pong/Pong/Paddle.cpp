#include "Paddle.h"
#include "raylib.h"
Paddle::Paddle(char s) {
	y = GetScreenHeight() / 2 - height / 2;
	side = s;
}
float Paddle::GetX() {
	return x;
}
float Paddle::GetY() {
	return y;
}
Rectangle Paddle::GetRect()
{
	return Rectangle{ Paddle::GetX() - Paddle::width / 2, Paddle::GetY(), 10, height };
}
void Paddle::OnUpdate(Ball* ball)
{
	if (IsKeyDown(KEY_W) && side == 'l')
	{
		y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S) && side == 'l')
	{
		y += speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_UP) && side == 'r')
	{
		y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_DOWN) && side == 'r')
	{
		y += speed * GetFrameTime();
	}
	if (CheckCollisionCircleRec(Vector2{ ball->GetX(), ball->GetY() }, ball->GetRadius(), GetRect()) && side == 'l')
	{
		if (ball->GetSpeedX() < 0)
		{
			ball->InvertSpeedX(y, height);
		}
	}
	if (CheckCollisionCircleRec(Vector2{ ball->GetX(), ball->GetY() }, ball->GetRadius(), GetRect()) && side == 'r')
	{
		if (ball->GetSpeedX() > 0)
		{
			ball->InvertSpeedX(y, height);
		}
	}
}
void Paddle::OnDraw()
{
	DrawRectangleRec(GetRect(), WHITE);
}
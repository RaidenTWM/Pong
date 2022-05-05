#pragma once
#include "Objects.h";
class Ball :
	public Objects
{
	protected:
		float x = 640;
		float y = 360;
		float rad = 10;
		float xSpeed = 300;
		float ySpeed = 300;
	public:
		Ball();
		int Move();
		float GetX();
		float GetY();
		float GetRadius();
};
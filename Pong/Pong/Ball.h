#pragma once
class Ball
{
	protected:
		float x = 640;
		float y = 360;
		float rad = 10;
		float xSpeed = 300;
		float ySpeed = 300;
	public:
		Ball();
		void Move();
		float GetX();
		float GetY();
		float GetRadius();
};


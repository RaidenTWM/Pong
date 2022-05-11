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
		float GetX();
		void InvertSpeedX();
		void InvertSpeedY();
		float GetSpeedX();
		float GetSpeedY();
		float GetY();
		float GetRadius();
		int OnUpdate();
		void OnDraw();
};
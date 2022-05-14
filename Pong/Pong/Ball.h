#pragma once
class Ball
{
	protected:
		float x = 0;
		float y = 0;
		float rad = 10;
		float xSpeed = 300;
		float ySpeed = 300;
	public:
		Ball();
		float GetX();
		void InvertSpeedX();
		void InvertSpeedX(float yy, float h);
		void InvertSpeedY();
		float GetSpeedX();
		float GetSpeedY();
		float GetY();
		float GetRadius();
		int OnUpdate();
		void OnDraw();
		void Stop();
		void Start();
};
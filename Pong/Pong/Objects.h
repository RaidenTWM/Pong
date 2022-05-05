#pragma once
#include "Game.h";
class Objects :
	public Game
{
public:
	~Objects();
	virtual void OnUpdate();
	virtual void OnDraw();
	void Update();
	void Draw();
};


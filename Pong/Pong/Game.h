#pragma once
class Game
{
    private:
    int playerPoints = 0;
    int enemyPoints = 0;
    int point = 0;
	public:
        Game();
        void Shutdown();
        void Update();
        void Draw();
        void Init();
        ~Game();
};
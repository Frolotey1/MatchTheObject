#ifndef SCEEN_HPP
#define SCEEN_HPP
#include "Frames.hpp"
#include "Toys.hpp"
class Panel;
class Player;

class Sceen {
	Player player;
	Panel panel;
	// поле schore - либо в классе сцены либо в классе игрока в зависимости от дальнейших действий
public:
	struct Action {
		// чем является действие - определяется на этапе определения логики игры
	};
	Sceen() = default;
	void start();
	void GameCycle();
	Player& get_player();
	Panel& get_panel();
	//TO-DO - дальнейший перечень публичных и приватных методов должен исходить из правил игровой логики
};
#endif
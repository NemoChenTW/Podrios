#ifndef GAME_TOOL_H
#define GAME_TOOL_H

#include "GameToolTypeDef.h"

class GameTool {
private:
	
public:
	GameTool(/* args */) = default;
	GameTool(GameToolType gameToolType);

	///	Show GameTool.
	virtual void show();


};

#endif // GAME_TOOL_H

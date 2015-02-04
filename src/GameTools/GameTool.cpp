#include "GameTool.h"

#include <iostream>

#include "Log/Log.h"

GameTool::GameTool(GameToolType gameToolType)
{
	std::cout << "Generate GameToolType: " << gameToolType << std::endl;
}

/**
 * @brief	Default show method for game tool.
 */
void GameTool::show()
{
	LOG_WARNING("No implement show method.");
}

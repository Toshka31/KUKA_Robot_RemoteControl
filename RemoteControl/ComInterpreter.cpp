#include "stdafx.h"
#include "ComInterpreter.h"


ComInterpreter::ComInterpreter(KUKAPilot *pilot)
{
	m_pilot = pilot;
}


ComInterpreter::~ComInterpreter()
{
}

bool ComInterpreter::execCommand(ECommand cmdCode, int arg)
{
	switch (cmdCode)
	{
	case RC_CMD_MOVE_FORWARD:
		m_pilot->setMoveSpeed(arg);
		break;
	case RC_CMD_MOVE_BACKWARD:
		m_pilot->setMoveSpeed(-arg);
		break;
	case RC_CMD_MOVE_RIGHT:
		m_pilot->moveRight(arg);
		break;
	case RC_CMD_MOVE_LEFT:
		m_pilot->moveLeft(arg);
		break;
	case RC_CMD_STOP_MOVEMENT:
		m_pilot->setMoveSpeed(0);
		m_pilot->setRotationSpeed(0);
		break;
	case RC_CMD_ROTATE_RIGHT:
		m_pilot->setRotationSpeed(arg);
		break;
	case RC_CMD_ROTATE_LEFT:
		m_pilot->setRotationSpeed(-arg);
		break;
	case RC_CMD_WAIT:
		m_pilot->waitNextCommand(arg);
		break;
	default:
		break;
	}
	return true;
}

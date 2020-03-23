#pragma once
class Agent
{
	Agent() {}
	virtual ~Agent() {}

	//Update the agent and its behaviors
	virtual void update(float deltaTime);

	//Add a behavior to the agent
};


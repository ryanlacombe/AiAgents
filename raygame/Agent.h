#pragma once
#include "raylib.h"
#include <vector>

class Behavior;

class Agent
{
public:
	Agent() {}
	virtual ~Agent() {}

	//Update the agent and its behaviors
	virtual void update(float deltaTime);

	//Draw the agent
	virtual void draw();

	//Add a behavior to the agent
	void addBehavior(Behavior* behavior);

	//Add a force to the agent's velocity
	void addForce(Vector2 force);

	//Movement functions
	void setPosition(Vector2 position) { m_Position = position; }
	Vector2 getPosition() { return m_Position; }
	void setVelocity(Vector2 velocity) { m_Velocity = velocity; }
	Vector2 getVelocity() { return m_Velocity; }

	//Speed functions
	void setSpeed(float speed) { m_speed = speed; }
	float getSpeed() { return m_speed; }

	//Color functions
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }

protected:
	std::vector<Behavior*> m_BehaviorList;

	Vector2 m_Position = { 0,0 };
	Vector2 m_Velocity = { 0,0 };

	float m_speed = 500.0f;
	Color m_color = MAROON;
};


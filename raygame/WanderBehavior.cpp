#include "WanderBehavior.h"
#include <cstdlib>

Vector2 WanderBehavior::update(Agent* agent, float deltaTime)
{
	//Start with a random target on edge of a circle with a set radius around the agent
	float randRange = ((float)RAND_MAX) / 2;
	Vector2 targetPos = Vector2{ rand() - randRange, rand() - randRange }.normalize() * m_radius;
	//Add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos += Vector2{ rand() - randRange, rand() - randRange }.normalize() * m_jitter;
	//Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	targetPos = targetPos.normalize() * m_radius;
	//Add the agent's heading, multiplied by the distance, to the target
	Vector2 heading = agent->getVelocity().normalize();
	targetPos += heading;

	m_prevTarget.x = targetPos.x;
	m_prevTarget.y = targetPos.y;

	//Seek the target
	//Get this agent's position
	Vector2 pos = agent->getPosition();
	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	direction = direction * 250;
	//Subtract the agent's current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->getVelocity();

	//Return the force
	return force;
}

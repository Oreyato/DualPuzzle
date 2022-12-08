#include "Actor.h"
#include "../maths/Maths.h"

Actor::Actor() :
    position{ Vector3::zero} ,
    scale{ 1.0f },
    rotation{ Quaternion::identity }
{
}

Actor::~Actor()
{
    while (!components.empty())
    {
        delete components.back();
    }
}

//v Setters ======================================================
void Actor::setPosition(Vector3 positionP) {
    position = positionP;
}
void Actor::setScale(float scaleP) {
    scale = scaleP;
}
void Actor::setRotation(Quaternion rotationP) {
    rotation = rotationP;
}

void Actor::setAngle(const Vector3& axis, float angle) {
    Quaternion newRotation(axis, angle);
	setRotation(newRotation);
}
void Actor::rotate(const Vector3& axis, float angle) {
    Quaternion newRotation = rotation;
	Quaternion increment(axis, angle);
	newRotation = Quaternion::concatenate(newRotation, increment);
	setRotation(newRotation);
}

//v Game loop ====================================================
void Actor::actorInput(const struct InputState& inputState) {

}

void Actor::processInput(const struct InputState& inputState) {
    for (auto component : components)
    {
        component->processInput(inputState);
    }
    actorInput(inputState);
}
void Actor::update(float dt) {
    updateComponents(dt);
}
void Actor::updateComponents(float dt) {
    for (auto component : components)
	{
		component->update(dt);
	}
}

//v Components ===================================================
void Actor::addComponent(Component* component) {
	// Find the insertion point in the sorted vector
	// (The first element with a order higher than me)
	int myOrder = component->getUpdateOrder();
	auto iter = begin(components);
	for (; iter != end(components); ++iter)
	{
		if (myOrder < (*iter)->getUpdateOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	components.insert(iter, component);
}
void Actor::removeComponent(Component* component) {
	auto iter = std::find(begin(components), end(components), component);
	if (iter != end(components))
	{
		components.erase(iter);
	}
}
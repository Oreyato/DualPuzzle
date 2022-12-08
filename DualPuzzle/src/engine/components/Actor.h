#ifndef ACTOR_H
#define ACTOR_H

#include <vector>

#include "Component.h"
#include "../maths/Vector3.h"
#include "../maths/Quaternion.h"

class Actor
{
public:
    Actor();
    virtual ~Actor();
    Actor(const Actor&) = delete;
    Actor& operator=(const Actor&) = delete;

    //v Getters ======================================================
    Vector3 getPosition() { return position; }
    float getScale() { return scale; }
    Quaternion getRotation() { return rotation; }

    //v Setters ======================================================
    void setPosition(Vector3 positionP);
	void setScale(float scaleP);
	void setRotation(Quaternion rotationP);

    void setAngle(const Vector3& axis, float angle);
	void rotate(const Vector3& axis, float angle);

    //v Game loop ====================================================
protected:
    virtual void actorInput(const struct InputState& inputState);
    virtual void updateActor(float dt);
public:
    void processInput(const struct InputState& inputState);
    void update(float dt);
	void updateComponents(float dt);
    
    //v Components ===================================================
    void addComponent(Component* component);
	void removeComponent(Component* component);

protected:
    Vector3 position;
    float scale;
    Quaternion rotation;

    std::vector<Component*> components;
};

#endif // ACTOR_H
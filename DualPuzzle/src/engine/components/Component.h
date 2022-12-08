#ifndef COMPONENT_H
#define COMPONENT_H

// #include "../input/InputState.h" 

class Actor;

class Component {
public:
    Component(Actor* ownerP, int updateOrderP = 100);
    Component() = delete;
    virtual ~Component();
    Component(const Component&) = delete;
	Component& operator=(const Component&) = delete;

    class Actor& getOwner() { return owner; }
    int getUpdateOrder() const { return updateOrder; }

    // virtual void processInput(const InputState &inputState);
    virtual void update(float dt);

protected:
    Actor& owner;
    int updateOrder;
};

#endif // COMPONENT_H
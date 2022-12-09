#ifndef BOUNDARYCUBE_H
#define BOUNDARYCUBE_H_H

#include "../../engine/components/Actor.h"

class BoundaryCube : public Actor {
public:
    BoundaryCube();

    void actorInput(const struct InputState& inputState) override;
	void updateActor(float dt) override;
};

#endif // BOUNDARYCUBE_H
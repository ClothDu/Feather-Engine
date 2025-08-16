#ifndef WORLDS_HPP
#define WORLDS_HPP

#include <box2d.h>
#include <string>

class Worlds {
    private:
        b2WorldId world;
        b2WorldDef worldDef = b2DefaultWorldDef();

    public:
        Worlds(b2Vec2 gravity, bool sleep) {
            // foce will be applied on x and y axis
            worldDef.gravity = gravity;
            worldDef.enableSleep = sleep;
            world = b2CreateWorld(&worldDef);
        }
};

#endif
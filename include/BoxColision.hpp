#ifndef BOXCOLISION_HPP
#define BOXCOLISION_HPP
#include <box2d.h>
#include <SFML/Graphics.hpp>
#include <vector>

class CharacterBody_BoxCollision : public sf::Drawable {
    private:
        float width = 0, heigth = 0;
        b2BodyDef characterDef = b2DefaultBodyDef();
        b2ShapeDef characterShapeDef = b2DefaultShapeDef();
        b2Polygon characterBox = b2MakeBox(width * 2, heigth * 2);
        b2BodyId character;
        sf::RectangleShape characterVisualCollision;

        void draw(sf::RenderTarget &target, const sf::RenderStates states) const override {
            target.draw(characterVisualCollision, states);
        }

    public:
        CharacterBody_BoxCollision(b2WorldId worldId, float w, float h, b2Vec2 pos, float rotation, float density, float friction) : width(w), heigth(h) {
            characterDef.type = b2_dynamicBody;
            characterDef.position = pos;
            // must be in angle
            characterDef.rotation = b2MakeRot(rotation);
            character = b2CreateBody(worldId, &characterDef);
            characterShapeDef.density = density;
            // must be a number btween 0.f ~ 1.f
            characterShapeDef.material.friction = friction;
            b2CreatePolygonShape(character, &characterShapeDef, &characterBox);
            characterVisualCollision.setSize({width, heigth});
        }

        void setAsBuller() const {
            if (!b2Body_IsBullet(character)) {
                b2Body_SetBullet(character, true);
            }
            else {
                b2Body_SetBullet(character, false);
            }
        }

        void setPos() const {}

        void setColor(int color[3]) {
            characterVisualCollision.setFillColor(sf::Color(color[0], color[1], color[2]));
        }

        void update() const {}
};

class Ground_BoxCollison : public sf::Drawable {
    private:
        float width = 0, heigth = 0;
        b2BodyDef groundDef = b2DefaultBodyDef();
        b2ShapeDef goundShapeDef = b2DefaultShapeDef();
        b2Polygon groundBox = b2MakeBox(width * 2, heigth * 2);
        b2BodyId ground;
        sf::RectangleShape groundVisualCollison;

        void draw(sf::RenderTarget &target, const sf::RenderStates states) const override {
            target.draw(groundVisualCollison, states);
        }

    public:
        Ground_BoxCollison(b2WorldId worldId, float w, float h, b2Vec2 pos, float rotation) {
            groundDef.type = b2_staticBody;
            groundDef.position = pos;
            // must be in angle
            groundDef.rotation = b2MakeRot(rotation);
            ground = b2CreateBody(worldId, &groundDef);
            b2CreatePolygonShape(ground, &goundShapeDef, &groundBox);
            groundVisualCollison.setSize({width, heigth});
        }

        void setColor(int color[3]) {
            groundVisualCollison.setFillColor(sf::Color(color[0], color[1], color[2]));
        }

        void update() const {}
};

class Ground_ChainCollision {
    private:
        b2BodyDef bodyChainDef = b2DefaultBodyDef();
        b2ChainId chain;
        sf::ConvexShape visualShape;

    public:
        Ground_ChainCollision(b2WorldId worldId,std::vector<b2Vec2> &points, b2Vec2 pos, float rotation) {
            b2BodyId body;
            bodyChainDef.type = b2_staticBody;
            bodyChainDef.position = pos;
            // must be in angle
            bodyChainDef.rotation = b2MakeRot(rotation);
            body = b2CreateBody(worldId, &bodyChainDef);
            b2ChainDef chainDef = b2DefaultChainDef();
            chainDef.points = points.data();
            chainDef.count = points.size();
            chain = b2CreateChain(body, &chainDef);

            for (size_t i = 0; i < points.size(); i++) {
                visualShape.setPoint(i, {points[i].x, points[i].y});
            }
        }

        void setColor(int color[3]) {
            visualShape.setFillColor(sf::Color(color[0], color[1], color[2]));
        }

        void update() const {}
};

#endif
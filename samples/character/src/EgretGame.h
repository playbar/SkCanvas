#ifndef CHARACTERGAME_H_
#define CHARACTERGAME_H_

#include "GrContext.h"
#include "gameplay.h"
using namespace gameplay;

#include "JSEngine.h"

/**
 * This is a mesh demo game for rendering Mesh.
 */
class EgretGame: public Game, public AnimationClip::Listener, public PhysicsCollisionObject::CollisionListener, public Scene::VisitNode
{
public:
    
    /**
     * Constructor.
     */
    EgretGame();

    /**
     * @see Game::keyEvent
     */
    void keyEvent(Keyboard::KeyEvent evt, int key);

    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

    /**
     * @see Game::mouseEvent
     */
    bool mouseEvent(Mouse::MouseEvent evt, int x, int y, int wheelDelta);

    /**
     * @see Game::gamepadEvent
     */
    void gamepadEvent(Gamepad::GamepadEvent evt, Gamepad* gamepad);

    /**
     * @see AnimationClip::Listener::animationEvent
     */
    void animationEvent(AnimationClip* clip, AnimationClip::Listener::EventType type);

    /**
     * @see PhysicsCollisionObject::CollisionListener::collisionEvent
     */
    void collisionEvent(PhysicsCollisionObject::CollisionListener::EventType type,
                                    const PhysicsCollisionObject::CollisionPair& collisionPair,
                                    const Vector3& contactPointA = Vector3::zero(),
                                    const Vector3& contactPointB = Vector3::zero());
protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);

public: //add by hgl
	void TestV8();

private:
    
    void drawSplash(void* param);
	bool visitDrawNode(Node* node, void *cookie);

	GrContext *fCurContext;
	GrRenderTarget *fCurRenderTarget;
	SkCanvas * fCanvas;

	JSEngine mJSEngine;

};

#endif

#include "CharacterGame.h"

#include "gl/GrGLInterface.h"
#include "SkGpuDevice.h"

// Declare our game instance
CharacterGame game;

// Input flags
#define NORTH 1
#define SOUTH 2
#define EAST 4
#define WEST 8
#define RUNNING 16

// Character defines
#define WALK_SPEED  5.0f
#define STRAFE_SPEED 1.5f
#define RUN_SPEED 15.0f
#define CAMERA_FOCUS_DISTANCE 16.0f

#define BUTTON_1 0
#define BUTTON_2 1

CharacterGame::CharacterGame()
{
}

void CharacterGame::initialize()
{
	glViewport(0, 0, 1280, 720);
	const GrGLInterface *fCurIntf = GrGLCreateNativeInterface();
	fCurContext = GrContext::Create((GrBackendContext)fCurIntf);
	GrBackendRenderTargetDesc desc;
	desc.fWidth = 1280;
	desc.fHeight = 720;
	desc.fConfig = kSkia8888_GrPixelConfig;
	desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
	desc.fSampleCnt = 1;
	desc.fStencilBits = 8;
	GLint buffer;
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &buffer);
	desc.fRenderTargetHandle = buffer;

	SkSafeUnref(fCurRenderTarget);
	fCurRenderTarget = fCurContext->wrapBackendRenderTarget(desc);
	SkAutoTUnref<SkBaseDevice> device(new SkGpuDevice(fCurContext, fCurRenderTarget));
	fCanvas = new SkCanvas(device);

    setMultiTouch(true);

    // Display the gameplay splash screen for at least 1 second.
    //displayScreen(this, &CharacterGame::drawSplash, NULL, 1000L);

}

bool CharacterGame::visitInitNode(Node* node)
{
    return true;
}


void CharacterGame::finalize()
{

}

void CharacterGame::drawSplash(void* param)
{
	SkPaint paint;
	paint.setColor(0xFFFF0000);
	paint.setStrokeWidth(10);
	fCanvas->clear(0xff000080);
	SkPath path;
	path.moveTo(10, 10);
	path.lineTo(50, 50);
	fCanvas->drawPath(path, paint);
    //clear(CLEAR_COLOR_DEPTH, Vector4(0, 0, 0, 1), 1.0f, 0);
    //SpriteBatch* batch = SpriteBatch::create("res/eglogo.png");
    //batch->start();
    //batch->draw(getWidth() * 0.5f, getHeight() * 0.5f, 0.0f, 512.0f, 512.0f, 0.0f, 1.0f, 1.0f, 0.0f, Vector4::one(), true);
    //batch->finish();
    //SAFE_DELETE(batch);
}

bool CharacterGame::visitDrawNode(Node* node, void *cookie)
{
    return true;
}

void CharacterGame::play(const char* id, bool repeat, float speed)
{
   
}

void CharacterGame::update(float elapsedTime)
{
	SkPaint paint;
	paint.setAntiAlias(true);
	paint.setColor(0xFFFF0000);
	paint.setStyle(SkPaint::kStroke_Style);
	paint.setStrokeWidth(10);
	fCanvas->clear(0xff008000);
	SkPath path;
	path.moveTo(0, 0);
	path.lineTo(50, 500);
	fCanvas->drawPath(path, paint);
	//fCanvas->drawRectCoords(10, 10, 1200, 600, paint);
}

void CharacterGame::render(float elapsedTime)
{
	fCurContext->flush();
}

void CharacterGame::keyEvent(Keyboard::KeyEvent evt, int key)
{
    if (evt == Keyboard::KEY_PRESS)
    {
        switch (key)
        {
        case Keyboard::KEY_ESCAPE:
            exit();
            break;
        case Keyboard::KEY_W:
        case Keyboard::KEY_CAPITAL_W:
            break;
        case Keyboard::KEY_S:
        case Keyboard::KEY_CAPITAL_S:
            break;
        case Keyboard::KEY_A:
        case Keyboard::KEY_CAPITAL_A:
            break;
        case Keyboard::KEY_D:
        case Keyboard::KEY_CAPITAL_D:
            break;
        case Keyboard::KEY_B:
            break;
        case Keyboard::KEY_SPACE:
            break;
        case Keyboard::KEY_SHIFT:
            break;
        case Keyboard::KEY_M:
        case Keyboard::KEY_CAPITAL_M:
            break;
        case Keyboard::KEY_C:
        case Keyboard::KEY_CAPITAL_C:
            break;
        }
    }
    else if (evt == Keyboard::KEY_RELEASE)
    {
        switch (key)
        {
        case Keyboard::KEY_W:
        case Keyboard::KEY_CAPITAL_W:
            break;
        case Keyboard::KEY_S:
        case Keyboard::KEY_CAPITAL_S:
            break;
        case Keyboard::KEY_A:
        case Keyboard::KEY_CAPITAL_A:
            break;
        case Keyboard::KEY_D:
        case Keyboard::KEY_CAPITAL_D:
            break;
        case Keyboard::KEY_SHIFT:
            break;
        }
    }
}

void CharacterGame::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{
    // This should only be called if the gamepad did not handle the touch event.
    switch (evt)
    {
    case Touch::TOUCH_PRESS:
        {
        }
        break;
    case Touch::TOUCH_RELEASE:
        {
        }
        break;
    case Touch::TOUCH_MOVE:
        {
        }
        break;
    default:
        break;
    }
}

bool CharacterGame::mouseEvent(Mouse::MouseEvent evt, int x, int y, int wheelDelta)
{
    if (evt == Mouse::MOUSE_PRESS_RIGHT_BUTTON)
    {
        return true;
    }
    return false;
}

void CharacterGame::gamepadEvent(Gamepad::GamepadEvent evt, Gamepad* gamepad)
{
    switch(evt)
    {
    case Gamepad::CONNECTED_EVENT:
    case Gamepad::DISCONNECTED_EVENT:
        break;
    }
}


void CharacterGame::animationEvent(AnimationClip* clip, AnimationClip::Listener::EventType type)
{
   
}

void CharacterGame::collisionEvent(PhysicsCollisionObject::CollisionListener::EventType type,
                                    const PhysicsCollisionObject::CollisionPair& collisionPair,
                                    const Vector3& contactPointA,
                                    const Vector3& contactPointB)
{
    // objectA -> basketball, only care about collisions between the physics character and the basketball.
   
}

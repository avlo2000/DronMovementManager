#include"IController.h"
#include"Sattelite.h"

using namespace contracts;

class TestController : public IController<Sattelite>
{
public:
	TestController();
	virtual void ControlRotation(Vector3d rotSpeed) {};
	virtual void ControlInstanceSpeed(Vector3d instSpeed) {};
	~TestController();
};


#ifndef _CONTROL_H_
#define _CONTROL_H_
class IO_Control
{
public:
	IO_Control();
	void forward();
	void backward();
	void turnRight();
	void turnLeft();
	void panRight();
	void panLeft();
	void tiltUp();
	void tiltDown();
	void LEDOn();
	void LEDOff();
	void stopTread();
	void stopCam();
};
#endif

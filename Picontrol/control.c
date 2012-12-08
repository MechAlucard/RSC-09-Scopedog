#include "control.h"
#include <stdlib.h>
void initControl()
{
    //Export pins
    system("echo "0" > /sys/class/gpio/export");
    system("echo "1" > /sys/class/gpio/export");
    system("echo "4" > /sys/class/gpio/export");
    system("echo "7" > /sys/class/gpio/export");
    system("echo "8" > /sys/class/gpio/export");
    system("echo "9" > /sys/class/gpio/export");
    system("echo "10" > /sys/class/gpio/export");
    system("echo "11" > /sys/class/gpio/export");
    //Make outputs
    system("echo "out" > /sys/class/gpio/gpio0/direction");
    system("echo "out" > /sys/class/gpio/gpio1/direction");
    system("echo "out" > /sys/class/gpio/gpio4/direction");
    system("echo "out" > /sys/class/gpio/gpio7/direction");
    system("echo "out" > /sys/class/gpio/gpio8/direction");
    system("echo "out" > /sys/class/gpio/gpio9/direction");
    system("echo "out" > /sys/class/gpio/gpio10/direction");
    system("echo "out" > /sys/class/gpio/gpio11/direction");

}

void forward()
{
    system("echo "0" > /sys/class/gpio/gpio4/value");
    system("echo "0" > /sys/class/gpio/gpio1/value");
    system("echo "1" > /sys/class/gpio/gpio0/value");
}
void backward()
{  
    system("echo "0" > /sys/class/gpio/gpio4/value");
    system("echo "1" > /sys/class/gpio/gpio1/value");
    system("echo "0" > /sys/class/gpio/gpio0/value");
}
void turnRight()
{
    system("echo "0" > /sys/class/gpio/gpio4/value");
    system("echo "1" > /sys/class/gpio/gpio1/value");
    system("echo "1" > /sys/class/gpio/gpio0/value");
}
void turnLeft()
{
    system("echo "1" > /sys/class/gpio/gpio4/value");
    system("echo "0" > /sys/class/gpio/gpio1/value");
    system("echo "0" > /sys/class/gpio/gpio0/value");

}
void panRight()
{
    system("echo "1" > /sys/class/gpio/gpio11/value");
    system("echo "1" > /sys/class/gpio/gpio10/value");

}
void panLeft()
{
    system("echo "1" > /sys/class/gpio/gpio11/value");
    system("echo "0" > /sys/class/gpio/gpio10/value");

}
void tiltUp()
{
    system("echo "1" > /sys/class/gpio/gpio9/value");
    system("echo "1" > /sys/class/gpio/gpio8/value");

}
void tiltDown()
{
    system("echo "1" > /sys/class/gpio/gpio9/value");
    system("echo "0" > /sys/class/gpio/gpio8/value");

}
void LEDOn()
{
    system("echo "1" > /sys/class/gpio/gpio7/value");
}
void LEDOff()
{
    system("echo "0" > /sys/class/gpio/gpio7/value");
}
void stopTread()
{
    system("echo "0" > /sys/class/gpio/gpio4/value");
    system("echo "0" > /sys/class/gpio/gpio1/value");
    system("echo "0" > /sys/class/gpio/gpio0/value");

}
void stopCam()
{
    system("echo "0" > /sys/class/gpio/gpio8/value");
    system("echo "0" > /sys/class/gpio/gpio9/value");
    system("echo "0" > /sys/class/gpio/gpio11/value");
    system("echo "0" > /sys/class/gpio/gpio10/value");

}

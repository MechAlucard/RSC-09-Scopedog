#include "control.h"
#include <stdlib.h>
IO_Control::IO_Control()
{
    //Export pins
    system("echo \"0\" > /sys/class/gpio/export");
    system("echo \"1\" > /sys/class/gpio/export");
    system("echo \"4\" > /sys/class/gpio/export");
    system("echo \"7\" > /sys/class/gpio/export");
    system("echo \"8\" > /sys/class/gpio/export");
    system("echo \"9\" > /sys/class/gpio/export");
    system("echo \"10\" > /sys/class/gpio/export");
    system("echo \"11\" > /sys/class/gpio/export");
    //Make outputs
    system("echo \"out\" > /sys/class/gpio/gpio0/direction");
    system("echo \"out\" > /sys/class/gpio/gpio1/direction");
    system("echo \"out\" > /sys/class/gpio/gpio4/direction");
    system("echo \"out\" > /sys/class/gpio/gpio7/direction");
    system("echo \"out\" > /sys/class/gpio/gpio8/direction");
    system("echo \"out\" > /sys/class/gpio/gpio9/direction");
    system("echo \"out\" > /sys/class/gpio/gpio10/direction");
    system("echo \"out\" > /sys/class/gpio/gpio11/direction");

}

void IO_Control::forward()
{
    system("echo \"0\" > /sys/class/gpio/gpio4/value");
    system("echo \"0\" > /sys/class/gpio/gpio1/value");
    system("echo \"1\" > /sys/class/gpio/gpio0/value");
}
void IO_Control::backward()
{  
    system("echo \"0\" > /sys/class/gpio/gpio4/value");
    system("echo \"1\" > /sys/class/gpio/gpio1/value");
    system("echo \"0\" > /sys/class/gpio/gpio0/value");
}
void IO_Control::turnRight()
{
    system("echo \"0\" > /sys/class/gpio/gpio4/value");
    system("echo \"1\" > /sys/class/gpio/gpio1/value");
    system("echo \"1\" > /sys/class/gpio/gpio0/value");
}
void IO_Control::turnLeft()
{
    system("echo \"1\" > /sys/class/gpio/gpio4/value");
    system("echo \"0\" > /sys/class/gpio/gpio1/value");
    system("echo \"0\" > /sys/class/gpio/gpio0/value");

}
void IO_Control::panRight()
{
    system("echo \"1\" > /sys/class/gpio/gpio11/value");
    system("echo \"1\" > /sys/class/gpio/gpio10/value");

}
void IO_Control::panLeft()
{
    system("echo \"1\" > /sys/class/gpio/gpio11/value");
    system("echo \"0\" > /sys/class/gpio/gpio10/value");

}
void IO_Control::tiltUp()
{
    system("echo \"1\" > /sys/class/gpio/gpio9/value");
    system("echo \"1\" > /sys/class/gpio/gpio8/value");

}
void IO_Control::tiltDown()
{
    system("echo \"1\" > /sys/class/gpio/gpio9/value");
    system("echo \"0\" > /sys/class/gpio/gpio8/value");

}
void IO_Control::LEDOn()
{
    system("echo \"1\" > /sys/class/gpio/gpio7/value");
}
void IO_Control::LEDOff()
{
    system("echo \"0\" > /sys/class/gpio/gpio7/value");
}
void IO_Control::stopTread()
{
    system("echo \"0\" > /sys/class/gpio/gpio4/value");
    system("echo \"0\" > /sys/class/gpio/gpio1/value");
    system("echo \"0\" > /sys/class/gpio/gpio0/value");
}
void IO_Control::stopCam()
{
    system("echo \"0\" > /sys/class/gpio/gpio8/value");
    system("echo \"0\" > /sys/class/gpio/gpio9/value");
    system("echo \"0\" > /sys/class/gpio/gpio11/value");
    system("echo \"0\" > /sys/class/gpio/gpio10/value");
}

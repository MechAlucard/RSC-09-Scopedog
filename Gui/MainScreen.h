#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WContainerWidget>
#include <Wt/WTable>
#include <Wt/WString>
#include <Wt/WBreak>
#include <Wt/WLabel>
#include <Wt/WLength>
#include "Picontrol/control.h"
#include <Wt/WTemplate>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

class MainScreen : public Wt::WContainerWidget
{
public:
	MainScreen(Wt::WContainerWidget * parent = 0);
private:
	Wt::WText * video_;
	Wt::WPushButton * treadUp_;
	Wt::WPushButton * treadDown_;
	Wt::WPushButton * treadRight_;
	Wt::WPushButton * treadLeft_;
	Wt::WPushButton * treadHalt_;
	Wt::WPushButton * tiltUp_;
	Wt::WPushButton * tiltDown_;
	Wt::WPushButton * panRight_;
	Wt::WPushButton * panLeft_;
	Wt::WPushButton * led_;
	Wt::WLabel * treadStatus_;
	Wt::WLabel * camStatus_;
	Wt::WLabel * ledStatus_;
	void forward();
	void reverse();
	void leftTurn();
	void rightTurn();
	void ledOn();
	void ledOff();
	void panRight();
	void panLeft();
	void tiltUp();
	void tiltDown();
};

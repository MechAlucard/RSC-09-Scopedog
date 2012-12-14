#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WContainerWidget>
#include <Wt/WTable>
#include <Wt/WString>
#include <Wt/WBreak>
#include <Wt/WLabel>
#include <Wt/WLength>
#include <Wt/WApplication>
#include <Wt/WEvent>
#include "Picontrol/control.h"
#include <Wt/WTemplate>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

class MainScreen : public Wt::WContainerWidget
{
public:
	MainScreen(Wt::WContainerWidget * parent = 0);
private:
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
	Wt::WText * treadStatus_;
	Wt::WText * camStatus_;
	Wt::WText * ledStatus_;
	bool ledState_;
public:
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
	void halt();
	void ledToggle();
	void keyHandler(const Wt::WKeyEvent &e);
};

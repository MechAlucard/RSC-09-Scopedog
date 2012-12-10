#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WContainerWidget>
#include <Wt/WTable>
#include <Wt/WString>
#include <Wt/WBreak>
#include <Wt/WLabel>
#include <Wt/WLength>
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
};

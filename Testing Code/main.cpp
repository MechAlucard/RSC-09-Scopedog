#include "/root/RSC-09-Scopedog/Testing Code/login/LoginWidget.h"
//#include "/root/RSC-09-Scopedog/Testing\ Code/axis/AxisWidget.h"
//#include "/root/RSC-09-Scopedog/Testing\ Code/RPio/RPio.h"
//#include </usr/include/Wt/WMediaPlayer>
#include </usr/include/Wt/WPushButton>
#include </usr/include/Wt/WSignal>
#include </usr/include/Wt/WStackedWidget>
#include </usr/include/Wt/WApplication>
using namespace Wt;
class MainApp : public WAplication
{
public:
	MainApp( const WEnvironemnt & env);
private:
	
};
MainApp::MainApp(const WEnvironment & env) : Wt::WApplication(env)
{
	setTitle("Red Shoulder Custom 09 Scopedog");
	WStackedWidget *MainScreen = new WStackedWidget(root());
	LoginWidget *LoginPage = new LoginWidget(root())
	MainScreen->addWidget(LoginPage);
}
WApplication *creatApplication(const WEnvironment& env)
{
	return new MainApp(env);
}
int main(int argc, char **argv)
{
	return Wt::WRun(argc, argv, &createApplication);
}

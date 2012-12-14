#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WStackedWidget>
#include <Wt/WString>
#include "Login.h"
#include "MainScreen.h"
class MainApplication : public Wt::WApplication
{
public:
    MainApplication(const Wt::WEnvironment& env);

private:
	Wt::WStackedWidget *screen_;
};

MainApplication::MainApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
	setTitle("RSC-09 Scopedog");	
	screen_ = new Wt::WStackedWidget(root());
	Wt::WString password("test");
	screen_ = new Wt::WStackedWidget(root());
	//screen_->addWidget(new Login(password,root()));
	MainScreen * MainApp_ = new MainScreen(root());
	screen_->addWidget(MainApp_);
	this->globalKeyWentDown().connect(MainApp_, &MainScreen::keyHandler);
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new MainApplication(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}


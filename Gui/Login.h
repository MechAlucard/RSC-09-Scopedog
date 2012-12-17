#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WContainerWidget>
#include <Wt/WTable>
#include <Wt/WString>
#include <Wt/WImage>
#include <stdio.h>
class Login : public Wt::WContainerWidget
{
public:
	Login(const Wt::WString &password, Wt::WContainerWidget * parent = 0 ,int tries = 5);
	Wt::Signal<void> loginSuccessful;
private:
	Wt::WText * intro_;
	Wt::WImage * logo_;
	Wt::WLineEdit * password_;
	Wt::WPushButton * enter_;
	Wt::WString password;
	Wt::WText * greeting_;
	void checkPassword();
	int tries_;
};

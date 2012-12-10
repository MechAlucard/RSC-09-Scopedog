#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WContainerWidget>
#include <Wt/WTable>
#include <Wt/WString>
class Login : public Wt::WContainerWidget
{
public:
	Login(const Wt::WString &password, Wt::WContainerWidget * parent = 0);
	Wt::Signal<int> loginSuccessful;
private:
	Wt::WLineEdit * password_;
	Wt::WPushButton * enter_;
	Wt::WString password;
	Wt::WText * greeting_;
	void checkPassword();
};

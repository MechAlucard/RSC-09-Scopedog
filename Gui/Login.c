#include "Login.h"

Login::Login(const Wt::WString &password, Wt::WContainerWidget * parent)
: password(password)
{
	greeting_ = new Wt::WText("Welcome Enter Password: ", this);
	password_ = new Wt::WLineEdit(this);
	enter_ = new Wt::WPushButton("Login",this);
	enter_->clicked().connect(SLOT(this, Login::checkPassword));
}
void Login::checkPassword()
{
	if(password_->text() == password)
	{
		loginSuccessful.emit(1);
	}
	else
	{
		greeting_->setText("Try Again: ");
	}
		
}

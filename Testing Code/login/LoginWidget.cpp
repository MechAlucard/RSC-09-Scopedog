//LoginWidget.cpp created by Tyler Martin 
//This class creates a login method using WT
#include "LoginWidget.h"
#include <WContainerWidget.h>
#include <WText>
#include <WPressButton>
#include <WLable>
#include <WTable>
//login widgit ctor
LoginWiget::LoginWiget(WContainerWidget * parent) : WConainerWidget(parent)
{
setPadding(Wt::WLength(100), Wt:Left | Wt::Right);

WText * title = new WText("Secret Login", this);

title->decorationStyle().font().setSize(Wt::WFont::XLarge);

IntroText = new WText("<p>Enter Red Shoulders Credentials</p>", this);

WTable * layout = new WTable(this);

WLable * usernameLable = new WLable("User Name: ", layout->elementAt(0,0));

layout->elementAt(0,0)->resize(WLength(14,WLength::FontEx),WLength());

Username = new WLineEdit(layout->elementAt(0,1);

usernameLable->setBuddy(Username);

WLabel * passwordLable - newWLable("Password: ", layout->element(1,0));

Password = new WLineEdit(layout->element(1,1));
Password->setEchoMode(WLineEdit::Password);
passwordLable->setBuddy(Password);

new WBreak(this);

WPushButton->clicked.conect(SLOT(this,LoginWidget::checkCredentials);
}
void LoginWidget::checkCredentials()
{
User = Username->text();
std::string pass = Password->text();
if(User == "Chirico" & Password == "abnormalsurvivor")
{
	confirmLogin("<p>Welcome " + User +"</p>");
}
else
{
	IntroText->setText("<p>Wrong username/password, this will be logged in Yoran Pailsen's files</p>");
	introText->decorationStyle().setForgroundColor(WT::red);
	Username->setText("");
	Password->setText("");

}
}
void LoginWidget::confirmLogin(const std::string text)
{
clear();
WText * title = new WText("Loging successful", this);
title->decorationStyle().font().setSize(WFont::XLarge);
new WText(text, this);
//needs work... here
}

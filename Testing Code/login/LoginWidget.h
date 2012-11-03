#ifndef LOGINWIDGET_H_
#define LOGINWIDGET_H
class LoginWidget : public WContainterWidget
{
public:
	LoginWidget(WContainerWiget *parent = 0);
public signals:
	Wt:Signal<std::string, Dictionary> loginSuccessful;
private slots:
	void checkCredentials();
	void startControl();
private:
	WText * IntroText;
	WLineEdit * Username;
	WlineEdit * Password;
	std::string User;
	void confirmLogin(const std::string text);
};

#endif
_

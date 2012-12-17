#include "Login.h"

Login::Login(const Wt::WString &password, Wt::WContainerWidget * parent, int tries)
: password(password), tries_(tries)
{
	Wt::WTable * layout = new Wt::WTable(this);
	
	
	intro_ = new Wt::WText("<p style=\"text-align:left;\"><span style=\"font-family:Times;font-size:22px;font-style:normal;font-weight:bold;text-decoration:none;text-transform:none;color:CC0000;\">Welcome to The 679th Mobile Space Force Corps,<p style=\"text-align:left;\"><span style=\"font-family:Times;font-size:22px;font-style:normal;font-weight:bold;text-decoration:none;text-transform:none;color:CC0000;\">24th Melkian Division Special Forces: The Red Shoulders</p><p>Yoran Pailsen, Please enter your password to access<p>your Red Shoulder Custom 09 Scopedog</p></p></span></p>",Wt::XHTMLUnsafeText,this);
	logo_ = new Wt::WImage(std::string("Images/RS.png"),this);
	layout->elementAt(0,0)->addWidget(logo_);
	layout->elementAt(0,1)->addWidget(intro_);
	layout->elementAt(0,0)->resize(Wt::WLength((110),Wt::WLength::Pixel),Wt::WLength());
	greeting_ = new Wt::WText("Password: ", this);
	password_ = new Wt::WLineEdit(this);
	password_->setEchoMode(Wt::WLineEdit::Password);
	enter_ = new Wt::WPushButton("Login",this);
	enter_->clicked().connect(SLOT(this, Login::checkPassword));
	password_->enterPressed().connect(this, &Login::checkPassword);
}
void Login::checkPassword()
{
	if(password_->text() == password)
	{
		tries_ = 5;
		loginSuccessful.emit();
	}
	else
	{
		if(tries_-- == 2)
		{
			intro_->setHidden(true,Wt::WAnimation());
			logo_->setImageRef("Images/warning.png");
		}
		else if(tries_ == 0)
		{
			logo_->setImageRef("Images/fail.jpeg");
			password_->setHidden(true,Wt::WAnimation());
			enter_->setHidden(true,Wt::WAnimation());
			greeting_->setText("<p>You Have Failed</p><p>sudo shutdown -h 0</p>");
		}
	}
		
}

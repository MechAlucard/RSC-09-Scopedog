#include "MainScreen.h"
#define BUTTON_SIZE 65
MainScreen::MainScreen(Wt::WContainerWidget * parent) : ledState_(0)
{
	//Add video element...
	Wt::WTemplate * vid_ = new Wt::WTemplate(this);
	vid_->setTemplateText("<object data=http://192.168.1.121:8090/?action=stream width=\"700\" height=\"500\"> <embed src=http://192.168.1.121:8090/?action=stream width=\"700\" height=\"500\"> </embed> </object>",Wt::XHTMLUnsafeText);

/*	struct ifaddrs * ifap = NULL, *tempIfAddr = NULL;
	void * tempAddrPtr = NULL;
	char addressOutputBuffer[INET6_ADDRSTRLEN];
	if(getifaddrs(&ifap) == 0)
	{
		tempIfAddrPtr = ifap;
		//if(tempIfAddrPtr->ifa_addr->sa_family == AF_INET)
		{
			tempIfAddPtr = &((struct sockaddr_in *)tempIfAddr->sin_addr;
		}
		//else
		
		//	tempIfAddPtr = &((struct sockaddr_in *)tempIfAddr->sin6_addr;
		}
		video_->setText(
		Wt::WString(inet_ntop(ifap->ifa_addr->sa_family,
		tempAddrPtr,
		addressOutputBuffer,
		sizeof(addressOutputBuffer))));
		freeifaddrs(ifap);
	}
*/
	//break
	new Wt::WBreak(this);
	//Add titles above the control table in a 3 x 1 table
	Wt::WTable * headingLayout_ = new Wt::WTable(this);
	headingLayout_->elementAt(0,0)->resize(Wt::WLength((BUTTON_SIZE * 3),
					Wt::WLength::Pixel),Wt::WLength());	
	headingLayout_->elementAt(0,1)->resize(Wt::WLength((BUTTON_SIZE * 3),
					Wt::WLength::Pixel),Wt::WLength());	
	headingLayout_->elementAt(0,2)->resize(Wt::WLength((BUTTON_SIZE * 3),
					Wt::WLength::Pixel),Wt::WLength());	
	Wt::WText * treadAxisLabel_ = new Wt::WText("Tread Axis",
						headingLayout_->elementAt(0,0));
	headingLayout_->elementAt(0,0)->setContentAlignment(Wt::AlignCenter);
	headingLayout_->elementAt(0,1)->setContentAlignment(Wt::AlignCenter);
	headingLayout_->elementAt(0,2)->setContentAlignment(Wt::AlignCenter);
	Wt::WText * ledLabel_ = new Wt::WText("Illumination",
						headingLayout_->elementAt(0,1));
	Wt::WText * camAxisLabel_ = new Wt::WText("Camera Axis",
						headingLayout_->elementAt(0,2));
	//break!
	new Wt::WBreak(this);
	//set up buttons
	treadUp_ = new Wt::WPushButton("GO!",this);
	treadUp_->clicked().connect(this, &MainScreen::forward);
	treadUp_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadDown_ = new Wt::WPushButton("REVERSE",this);
	treadDown_->clicked().connect(this, &MainScreen::reverse);
	treadDown_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadRight_ = new Wt::WPushButton("RIGHT",this);
	treadRight_->clicked().connect(this,&MainScreen::rightTurn);
	treadRight_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadLeft_ = new Wt::WPushButton("LEFT",this);
	treadLeft_->clicked().connect(this,&MainScreen::leftTurn);
	treadLeft_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadHalt_ = new Wt::WPushButton("HALT",this);
	treadHalt_->clicked().connect(this,&MainScreen::halt);
	treadHalt_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	tiltUp_ = new Wt::WPushButton("UP",this);
	tiltUp_->clicked().connect(this,&MainScreen::tiltUp);
	tiltUp_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	tiltDown_ = new Wt::WPushButton("DOWN",this);
	tiltDown_->clicked().connect(this,&MainScreen::tiltDown);
	tiltDown_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	panRight_ = new Wt::WPushButton("RIGHT",this);
	panRight_->clicked().connect(this,&MainScreen::panRight);
	panRight_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	panLeft_ = new Wt::WPushButton("LEFT",this);
	panLeft_->clicked().connect(this,&MainScreen::panLeft);
	panLeft_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	led_ = new Wt::WPushButton("ON/OFF",this);
	led_->clicked().connect(this,&MainScreen::ledToggle);
	led_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	//Make a 9 x 3 table to put buttons in
	Wt::WTable * buttonLayout_ = new Wt::WTable(this);
	buttonLayout_->elementAt(0,1)->addWidget(treadUp_);
	buttonLayout_->elementAt(2,1)->addWidget(treadDown_);
	buttonLayout_->elementAt(1,2)->addWidget(treadRight_);
	buttonLayout_->elementAt(1,0)->addWidget(treadLeft_);
	buttonLayout_->elementAt(1,1)->addWidget(treadHalt_);
	buttonLayout_->elementAt(0,7)->addWidget(tiltUp_);
	buttonLayout_->elementAt(2,7)->addWidget(tiltDown_);
	buttonLayout_->elementAt(1,8)->addWidget(panRight_);
	buttonLayout_->elementAt(1,6)->addWidget(panLeft_);
	buttonLayout_->elementAt(0,4)->addWidget(led_);

	buttonLayout_->elementAt(0,1)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(2,1)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(1,2)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(1,0)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(1,1)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(0,7)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(2,7)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(1,8)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(1,6)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	buttonLayout_->elementAt(1,4)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
buttonLayout_->elementAt(1,3)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
buttonLayout_->elementAt(1,4)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
buttonLayout_->elementAt(1,5)->resize
	(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
	 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
//Key handling
	this->keyWentDown().connect(this, &MainScreen::keyHandler);
	//parent->globalKeyWentDown().connect(this, &MainScreen::keyHandler);
//break and debug stats
	new Wt::WBreak(this);
	Wt::WTable * statLayout_ = new Wt::WTable(this);
	statLayout_->elementAt(0,0)->addWidget(new Wt::WText("Tread Status: "));
	statLayout_->elementAt(1,0)->addWidget(new Wt::WText("Camera Status: "));
	statLayout_->elementAt(2,0)->addWidget(new Wt::WText("LED Status: "));
	treadStatus_ = new Wt::WText("Halt",statLayout_->elementAt(0,1));
	camStatus_ = new Wt::WText("Halt",statLayout_->elementAt(1,1));
	ledStatus_ = new Wt::WText("Off",statLayout_->elementAt(2,1));
}
void MainScreen::forward()
{
	this->treadStatus_->setText("Forward");
}
void MainScreen::reverse()
{
	this->treadStatus_->setText("Reverse");
}
void MainScreen::rightTurn()
{
	this->treadStatus_->setText("Right");
}
void MainScreen::leftTurn()
{
	this->treadStatus_->setText("Left");
}
void MainScreen::ledOn()
{
	this->ledStatus_->setText("ON!");
}
void MainScreen::ledOff()
{
	this->ledStatus_->setText("OFF");
}
void MainScreen::panRight()
{
	this->camStatus_->setText("Panning Right...");
	sleep(3);
//	this->camStatus_->setText("Halt");
}
void MainScreen::panLeft()
{
	this->camStatus_->setText("Panning Left...");
	sleep(3);
//	this->camStatus_->setText("Halt");
}
void MainScreen::tiltUp()
{
	this->camStatus_->setText("Tilting Up...");
	sleep(3);
//	this->camStatus_->setText("Halt");
}
void MainScreen::tiltDown()
{
	this->camStatus_->setText("Tilting Down..");
	sleep(3);
//	this->camStatus_->setText("Halt");
}
void MainScreen::halt()
{
	this->treadStatus_->setText("Halt");
	this->camStatus_->setText("Halt");
}
void MainScreen::ledToggle()
{
	if(this->ledState_)
	{
		this->ledState_ = 0;
		this->ledOff();
	}
	else
	{
		this->ledState_ = 1;
		this->ledOn();
	}
}
void MainScreen::keyHandler(const Wt::WKeyEvent &e)
{
	if(e.key() == Wt::Key_W)
	this->forward();
}

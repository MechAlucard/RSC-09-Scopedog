#include "MainScreen.h"
#define BUTTON_SIZE 65
#define INTERFACE_NAME "eth0"
MainScreen::MainScreen(Wt::WContainerWidget * parent) : ctl_(IO_Control()), ledState_(0), address_(Wt::WString()), videoElement_(Wt::WString())
{	//set the video element
	Wt::WString interfaceName(INTERFACE_NAME);
	setAddress(interfaceName);
	setVideoElement();
	//Add video element...
	Wt::WTemplate * vid_ = new Wt::WTemplate(this);
	vid_->setTemplateText(videoElement_, Wt::XHTMLUnsafeText);

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
	this->keyWentDown().connect(this, &MainScreen::keyDownHandler);
	this->keyWentUp().connect(this, &MainScreen::keyUpHandler);
//break and debug stats
	new Wt::WBreak(this);
	Wt::WTable * statLayout_ = new Wt::WTable(this);
	statLayout_->elementAt(0,0)->addWidget(new Wt::WText("Tread Status: "));
	statLayout_->elementAt(1,0)->addWidget(new Wt::WText("Camera Status: "));
	statLayout_->elementAt(2,0)->addWidget(new Wt::WText("LED Status: "));
	statLayout_->elementAt(3,0)->addWidget(new Wt::WText("Address: "));

	treadStatus_ = new Wt::WText("Halt",statLayout_->elementAt(0,1));
	camStatus_ = new Wt::WText("Halt",statLayout_->elementAt(1,1));
	ledStatus_ = new Wt::WText("Off",statLayout_->elementAt(2,1));
	ipStatus_ = new Wt::WText("UNKNOWN!!",statLayout_->elementAt(3,1));
	
	ipStatus_->setText(address_);
}
void MainScreen::forward()
{
	this->treadStatus_->setText("Forward");
	ctl_.forward();
}
void MainScreen::reverse()
{
	this->treadStatus_->setText("Reverse");
	ctl_.backward();
}
void MainScreen::rightTurn()
{
	this->treadStatus_->setText("Right");
	ctl_.turnRight();
}
void MainScreen::leftTurn()
{
	this->treadStatus_->setText("Left");
	ctl_.turnLeft();
}
void MainScreen::ledOn()
{
	this->ledStatus_->setText("ON!");
	ctl_.LEDOn();
}
void MainScreen::ledOff()
{
	this->ledStatus_->setText("OFF");
	ctl_.LEDOff();
}
void MainScreen::panRight()
{
	this->camStatus_->setText("Panned Right...");
	ctl_.panRight();
	usleep(300);
	ctl_.stopCam();
}
void MainScreen::panLeft()
{
	this->camStatus_->setText("Panned Left...");
	ctl_.panLeft();
	usleep(300);
	ctl_.stopCam();
}
void MainScreen::tiltUp()
{
	this->camStatus_->setText("Tilted Up...");
	ctl_.tiltUp();
	usleep(300);
	ctl_.stopCam();
}
void MainScreen::tiltDown()
{
	this->camStatus_->setText("Tilted Down..");
	ctl_.tiltDown();
	usleep(300);
	ctl_.stopCam();
}
void MainScreen::halt()
{
	this->treadStatus_->setText("Halt");
	this->camStatus_->setText("Halt");
	ctl_.stopCam();
	ctl_.stopTread();
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
void MainScreen::keyDownHandler(const Wt::WKeyEvent &e)
{
	switch(e.key())	
	{
		case Wt::Key_Up:
		tiltUp();
		break;
		case Wt::Key_Down:
		tiltDown();
		break;
		case Wt::Key_Left:
		panLeft();
		break;
		case Wt::Key_Right:
		panRight();
		break;
		case Wt::Key_W:
		forward();
		break;
		case Wt::Key_A:
		leftTurn();
		break;
		case Wt::Key_S:
		reverse();
		break;
		case Wt::Key_D:
		rightTurn();
		break;
		case Wt::Key_E:
		ledToggle();
		break;
		case Wt::Key_Q:
		halt();
		break;
	}
}
void MainScreen::keyUpHandler(const Wt::WKeyEvent &e)
{
	if(e.key() == Wt::Key_W ||
	   e.key() == Wt::Key_A ||
	   e.key() == Wt::Key_S ||
	   e.key() == Wt::Key_D)
	halt();	
}
void MainScreen::setVideoElement()
{
	videoElement_ = "<object data=http://";
	videoElement_ += address_;
	videoElement_ += ":8090/?action=stream width=\"700\" height=\"500\"> <embed src=http://";
	videoElement_ += address_;
	videoElement_ += ":8090/?action=stream width=\"700\" height=\"500\"> </embed> </object>";
return;
}
//Sets the ipv4 address to be used based on the interface name given
void MainScreen::setAddress(Wt::WString & interfaceName)
{
	struct ifaddrs * interfaceArray = NULL, * tempIfAddr = NULL;
	void * tempAddrPtr = NULL;
	char addressOutputBuffer[INET6_ADDRSTRLEN] = {0};
	int rc = 0;
	bool match_type = 0;
	Wt::WString name;
	rc = getifaddrs(&interfaceArray);
	if(rc == 0)
	{
		for(tempIfAddr = interfaceArray; tempIfAddr != NULL; tempIfAddr = tempIfAddr->ifa_next)
    		{
      			if(tempIfAddr->ifa_addr->sa_family == AF_INET && match_type == 0)
			{
        			tempAddrPtr = &((struct sockaddr_in *)tempIfAddr->ifa_addr)->sin_addr;
				match_type = 1;
			}
      			else
			{
       			 	tempAddrPtr = &((struct sockaddr_in6 *)tempIfAddr->ifa_addr)->sin6_addr; 
			}
     		       	inet_ntop(tempIfAddr->ifa_addr->sa_family,
	                       	tempAddrPtr,
       	          		addressOutputBuffer,
       	               		sizeof(addressOutputBuffer));	
				name = Wt::WString(tempIfAddr->ifa_name, Wt::LocalEncoding);
				if(interfaceName == name && match_type)
		    		{
					address_ = Wt::WString(addressOutputBuffer, Wt::LocalEncoding);
					return;
				}
				else
				{
					address_ = Wt::WString("Interface Not Found");
				}
				match_type = 0;
				
		}
	}
	else
		address_ = Wt::WString("Failed");
	freeifaddrs(interfaceArray);
	return;
}

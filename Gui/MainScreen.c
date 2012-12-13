#include "MainScreen.h"
#define BUTTON_SIZE 65
MainScreen::MainScreen(Wt::WContainerWidget * parent)
{
	//Add video element... somehow mpegstreamer feed!
	Wt::WTemplate * vid_ = new Wt::WTemplate(this);
	vid_->setTemplateText("<object data=http://192.168.1.121:8090/?action=stream width=\"700\" height=\"500\"> <embed src=http://192.168.1.121:8090/?action=stream width=\"700\" height=\"500\"> </embed> </object>",Wt::XHTMLUnsafeText);

	Wt::WText * video_ = new Wt::WText("Video Be Heeyar!",this);
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
	Wt::WLabel * treadAxisLabel_ = new Wt::WLabel("Tread Axis",
						headingLayout_->elementAt(0,0));
	headingLayout_->elementAt(0,0)->setContentAlignment(Wt::AlignCenter);
	headingLayout_->elementAt(0,1)->setContentAlignment(Wt::AlignCenter);
	headingLayout_->elementAt(0,2)->setContentAlignment(Wt::AlignCenter);
	Wt::WLabel * ledLabel_ = new Wt::WLabel("Illumination",
						headingLayout_->elementAt(0,1));
	Wt::WLabel * camAxisLabel_ = new Wt::WLabel("Camera Axis",
						headingLayout_->elementAt(0,2));
	//break!
	new Wt::WBreak(this);
	//set up buttons
	treadUp_ = new Wt::WPushButton("UP",this);
	treadUp_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadDown_ = new Wt::WPushButton("DOWN",this);
	treadDown_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadRight_ = new Wt::WPushButton("RIGHT",this);
	treadRight_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadLeft_ = new Wt::WPushButton("LEFT",this);
	treadLeft_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	headingLayout_->elementAt(0,0)->setContentAlignment(Wt::AlignCenter);
	headingLayout_->elementAt(0,1)->setContentAlignment(Wt::AlignCenter);
	headingLayout_->elementAt(0,2)->setContentAlignment(Wt::AlignCenter);
	
	//break!
	new Wt::WBreak(this);
	//set up buttons
	treadUp_ = new Wt::WPushButton("UP",this);
	treadUp_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadDown_ = new Wt::WPushButton("DOWN",this);
	treadDown_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadRight_ = new Wt::WPushButton("RIGHT",this);
	treadRight_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadLeft_ = new Wt::WPushButton("LEFT",this);
	treadLeft_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadHalt_ = new Wt::WPushButton("HALT",this);
	treadHalt_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	tiltUp_ = new Wt::WPushButton("UP",this);
	tiltUp_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	tiltDown_ = new Wt::WPushButton("DOWN",this);
	tiltDown_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	panRight_ = new Wt::WPushButton("RIGHT",this);
	panRight_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	panLeft_ = new Wt::WPushButton("LEFT",this);
	panLeft_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	led_ = new Wt::WPushButton("ON/OFF",this);
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
//break and debug stats
	new Wt::WBreak(this);
	Wt::WTable * s(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	treadHalt_ = new Wt::WPushButton("HALT",this);
	treadHalt_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	tiltUp_ = new Wt::WPushButton("UP",this);
	tiltUp_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	tiltDown_ = new Wt::WPushButton("DOWN",this);
	tiltDown_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	panRight_ = new Wt::WPushButton("RIGHT",this);
	panRight_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	panLeft_ = new Wt::WPushButton("LEFT",this);
	panLeft_->resize(Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel),
			 Wt::WLength(BUTTON_SIZE,Wt::WLength::Pixel));
	led_ = new Wt::WPushButton("ON/OFF",this);
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
//break and debug stats
	new Wt::WBreak(this);
	Wt::WTable * statLayout_ = new Wt::WTable(this);
	//Wt::WText("Tread Status: ", statLayout_->elementAt(0,0));
	//statLayout_->elementAt(0,0)->addWidget(Wt::WText("Tread Status: "));
	//statLayout_->elementAt(1,0)->addWidget(Wt::WText("Camera Status: "));
	//statLayout_->elementAt(2,0)->addWidget(Wt::WText("LED Status: "));
	treadStatus_ = new Wt::WLabel("Halt",statLayout_->elementAt(1,0));
	camStatus_ = new Wt::WLabel("Halt",statLayout_->elementAt(1,1));
	ledStatus_ = new Wt::WLabel("Off",statLayout_->elementAt(1,2));
}

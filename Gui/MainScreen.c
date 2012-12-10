#include "MainScreen.h"
#define BUTTON_SIZE 65
MainScreen::MainScreen(Wt::WContainerWidget * parent)
{
	//Add video element... somehow mpegstreamer feed!
	Wt::WText video("Video be here!",this);
	//break
	new Wt::WBreak(this);
	//Add titles above the control table in a 3 x 1 table
	Wt::WTable * headingLayout_ = new Wt::WTable(this);
	headingLayout_->elementAt(0,0)->resize(Wt::WLength((BUTTON_SIZE * 3),Wt::WLength::Pixel)
			     , Wt::WLength());	
	Wt::WLabel * treadAxisLable_ = new Wt::WLabel("Tread Axis",
						headingLayout_->elementAt(0,0));
	Wt::WLabel * ledLable_ = new Wt::WLabel("Illumination",
						headingLayout_->elementAt(0,1));
	Wt::WLabel * camAxisLable_ = new Wt::WLabel("Camera Axis",
						headingLayout_->elementAt(0,3));
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
	buttonLayout_->elementAt(1,4)->addWidget(led_);

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




}

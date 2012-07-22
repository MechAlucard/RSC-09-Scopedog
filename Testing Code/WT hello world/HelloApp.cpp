//WT test code
#include </usr/include/Wt/WApplication>
#include </usr/include/Wt/WBreak>
#include </usr/include/Wt/WContainerWidget>
#include </usr/include/Wt/WLineEdit>
#include </usr/include/Wt/WPushButton>
#include </usr/include/Wt/WText>
#include </usr/include/Wt/WSignal>
#include </usr/include/Wt/WStackedWidget>
using namespace Wt;
using namespace Wt;
class Test: public Wt::WContainerWidget
{
public:
	Test(const std::string &name, Wt::WContainerWidget *parent = 0);
	Wt::Signal<std::string>& next(){return next_;}	
private:
	Wt::Signal<std::string> next_;
	std::string name;
	Wt::WText * name_;
	Wt::WPushButton *go_;
	void NextPage(){next_.emit("next");}
	
};
Test::Test(const std::string &name, Wt::WContainerWidget *parent)
: WContainerWidget(parent), name(name), next_(this)
{
	name_ = new Wt::WText(name,this);
	go_ = new Wt::WPushButton("GO!",this);
	go_->clicked().connect(this,&Test::NextPage);
}
class HelloApp : public WApplication
{
public:
	HelloApp( const WEnvironment & env);
private:
	WLineEdit *nameEdit_;
	WText *greeting_;
	Wt::WStackedWidget *bottom; 
	void greet();
	void change(std::string);
};
//ctor
HelloApp::HelloApp(const WEnvironment & env)
: Wt::WApplication(env)
{
	setTitle("Za Warudo!!"); 		//app title
	root()->addWidget(new WText("Omae wa namae desu ka"));
	//show some text
	nameEdit_ = new WLineEdit(root());  	//make test input
	nameEdit_->setFocus();			//give focus
	
	WPushButton *b = new WPushButton("Hajimemasu",root());
	//create button
	b->setMargin(5, Wt::Left);		//5 pixal margin
	
	root()->addWidget(new WBreak());	//insert a line break
	
	greeting_ = new WText(root());		//empty text

	//connet signals to slots
	b->clicked().connect(SLOT(this, HelloApp::greet));
	nameEdit_->enterPressed().connect(SLOT(this,HelloApp::greet));
	//testing added
	Test *t1 = new Test("tyler",root());
	//testing stacked widget
	bottom = new Wt::WStackedWidget(root());
	bottom->addWidget(new Test("mazinga!",root()));
	bottom->addWidget(new Test("Getta Robo!",root()));
	static_cast<Test*>(bottom->currentWidget())->next().connect(this,&HelloApp::change);
	bottom->setCurrentIndex(1);
	static_cast<Test*>(bottom->currentWidget())->next().connect(this,&HelloApp::change);
}
void HelloApp::change(std::string)
{
	std::cout << "page: " << bottom->currentIndex() << std::endl;
	if(bottom->currentIndex() == 0)
		bottom->setCurrentIndex(1);
	else if(bottom->currentIndex() == 1)
		bottom->setCurrentIndex(0);

}
//greet function
void HelloApp::greet()
{
	//update text using text imput to nameEdit feild
	greeting_->setText("Hajimemashita " + nameEdit_->text());
}
WApplication *createApplication(const WEnvironment& env)
{
	return new HelloApp(env);
}
int main(int argc, char **argv)
{
	return Wt::WRun(argc, argv, &createApplication);
}


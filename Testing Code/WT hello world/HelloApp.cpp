//WT test code written by Victor Volkman
#include <WApplication>
#include <WBreak>
#include <WContainerWidget>
#include <WLineEdit>
#include <WPushButton>
#include <WText>

using namespace Wt;
class HelloApp : public WApplication
{
public:
   HelloApp(const WEnvironment& env);
private:
   WLineEdit *nameEdit_;
   WText *greeting_;

   void greet();
};
HelloApp::HelloApp(const WEnvironment& env)
   : WApplication(env)
{
	setTitle("Hello world");               // application title
	root()->addWidget(new WText("Your name, please ? "));
      // show some text
	nameEdit_ = new WLineEdit(root());    // allow text input
	nameEdit_->setFocus();                // give focus

	WPushButton *b = new WPushButton("Greet me.", root());
      // create a button
	b->setMargin(5, WWidget::Left);       // add 5 pixels margin
	
	root()->addWidget(new WBreak());      // insert a line break
	
	greeting_ = new WText(root());        // empty text
	
	// Connect signals with slots
	
	b->clicked.connect(SLOT(this, HelloApp::greet));
	nameEdit_->enterPressed.connect(SLOT(this, HelloApp::greet));
}

void HelloApp::greet()
{
// Update the text, using text input into the nameEdit_ field.
	greeting_->setText("Hello there, " + nameEdit_->text());
}

WApplication *createApplication(const WEnvironment& env)
{
// You could read information from the environment to decide
// whether the user has permission to start a new application
return new HelloApp(env);
}

int main(int argc, char **argv)
{
	return WRun(argc, argv, &createApplication);
}
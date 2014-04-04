#include "PanelSaveLoad.h"

using namespace ci;
using namespace ci::app;
using namespace std;

PanelSaveLoad::PanelSaveLoad(BasePanel *parent) : BasePanel() {
	mBounds.set(0, 0, 200, 23);
	parent->registerPanel(this);
}

PanelSaveLoad::PanelSaveLoad(BasePanel *parent, fs::path savePath) : BasePanel() {
	parent->registerPanel(this);
}

void PanelSaveLoad::updateBounds(const ci::Vec2f &offset, const ci::Rectf &parentBounds) {
	BasePanel::updateBounds(offset, parentBounds);

	int margin = 10;
	int buttonWidth = (mBounds.getWidth() - margin * 3.0) * 0.5;
	int buttonHeight = 19;

	mSaveRect.set(margin, 0, buttonWidth + margin, buttonHeight);
	mLoadRect = mSaveRect.getOffset(Vec2f(buttonWidth + margin, 0));
}

void PanelSaveLoad::mouseDown(const ci::Vec2i &pos){
	if (mSaveRect.contains(pos-mOffset)){
		console() << "Save!" << endl;
	}
	else if (mLoadRect.contains(pos-mOffset)){
		console() << "Load! " << endl;
	}
}

void PanelSaveLoad::mouseDragged(const ci::Vec2i &pos){

}

void PanelSaveLoad::mouseUp(const ci::Vec2i &pos){

}

void PanelSaveLoad::draw() {
	gl::pushMatrices(); {
		gl::translate(mOffset + Vec2f(0,3));

		// SAVE
		gl::color(mGlobal->P_TAB_COLOR);
		gl::drawSolidRect(mSaveRect);

		gl::color(mGlobal->P_HIGHLIGHT_COLOR);
		gl::drawLine(mSaveRect.getUpperLeft() + Vec2f(0, 1), mSaveRect.getUpperRight() + Vec2f(0, 1));

		gl::color(mGlobal->P_OUTLINE_COLOR);
		gl::drawStrokedRect(mSaveRect);
		mGlobal->renderTextCentered("Save", Vec2f(mSaveRect.getCenter().x, 2));
		
		// LOAD
		gl::color(mGlobal->P_TAB_COLOR);
		gl::drawSolidRect(mLoadRect);

		gl::color(mGlobal->P_HIGHLIGHT_COLOR);
		gl::drawLine(mLoadRect.getUpperLeft() + Vec2f(0, 1), mLoadRect.getUpperRight() + Vec2f(0, 1));

		gl::color(mGlobal->P_OUTLINE_COLOR);
		gl::drawStrokedRect(mLoadRect);
		mGlobal->renderTextCentered("Load", Vec2f(mLoadRect.getCenter().x, 2));

	}gl::popMatrices();

}
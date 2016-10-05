#ifndef BACKYARDBRAINS_ANALYSISAUDIOVIEW_H
#define BACKYARDBRAINS_ANALYSISAUDIOVIEW_H

#include "AudioView.h"
#include "engine/SpikeSorter.h"

namespace BackyardBrains {

class SpikeSorter;

/* This is a messy extension of AudioView. It adds a spike display and is thought
 * for paused one channel non-thresh-mode non-live-mode playback. But it doesn’t
 * prevent everything elsefrom happening and that’s why it’s messy.
 */

class AnalysisAudioView : public AudioView {
public:
	AnalysisAudioView(RecordingManager &mngr, AnalysisManager &anaman, SpikeSorter &spikes, Widget *parent = NULL);

	int upperThresh() const;
	int lowerThresh() const;

	void setColorIdx(int idx);
	void setThresh(int upper, int lower);
	
	sigslot::signal0<> threshChanged;
private:
	SpikeSorter &_spikes;
    RecordingManager &_manager;
	int _colorIdx;

	int _clickedThresh;
	int _clickOffset;
	int _threshPos[2];

	int screenWidth() const;

	int relPosToAmp(float rpos) const;
	float ampToRelPos(int amp) const;
	void mousePressEvent(Widgets::MouseEvent *event);
	void mouseMotionEvent(Widgets::MouseEvent *event);
	void mouseReleaseEvent(Widgets::MouseEvent *event);

	void drawTargetMarkers();
	void paintEvent();
};

}
#endif

#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    bool inside = false;
    int currsor[2];
    
    bool inProg = false;
    
    ofPoint tmpPoint;
    
    typedef struct {
        ofPoint first;
        ofPoint second;
    }fixtur_T;
    
    vector<fixtur_T> fixtur;
    
    ofxCsv csv;
    
    int rowIndex = 0;
    
    bool CMDon = false;
    bool ctrlF = false;
    int fixturType = 0;
    
    string fixturTypes[10];
    
    ofTrueTypeFont myfont;
    
};

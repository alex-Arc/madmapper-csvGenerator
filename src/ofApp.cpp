#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofHideCursor();
    ofSetEscapeQuitsApp(false);
    
    ofxCsvRow rowContent("Fixture Definition Name,Start Universe,Start Channel,StartX,StartY,EndX,EndY,Width");
    
    if (csv.load("test.csv")) {
        cout << "file exists" << endl;
        csv.setRow(0, rowContent);
        csv.save();
        
    }else{
        cout << "no file, creating new" << endl;
        csv.createFile("test.csv");
        csv.setRow(rowIndex, rowContent);
        rowIndex++;
        csv.save();
    }
    
    fixturTypes[0] = "t - Fixture";
    fixturTypes[1] = "t - Fixture 1";
    
    myfont.load("obscurapro-ultralight-webfont.ttf", 12);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(0, 50, 50);
    ofSetColor(255, 255, 255);
    myfont.drawString("current fixtur" + fixturTypes[fixturType], 10, 20);
    
    //draw draw fixturs
    ofSetColor(255, 100, 0);
    for(vector<fixtur_T>::iterator it = fixtur.begin(); it != fixtur.end(); ++it) {
        ofDrawCircle(it->first, 5);
        ofDrawCircle(it->second, 5);
        ofDrawLine(it->first, it->second);
    }
    
    
    //draw temporary points
    ofSetColor(0, 0, 255);
    if(inProg == true) {
        ofDrawCircle(tmpPoint, 5);
    }
    
    
    
    
    // draw cursor
    if (inside == true) {
        ofSetColor(255, 255, 255);
        ofDrawLine(currsor[0], currsor[1]+10, currsor[0], currsor[1]-10);
        ofDrawLine(currsor[0]+10, currsor[1], currsor[0]-10, currsor[1]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 27:                    //esc
            inProg = false;
        break;
        case 233:                   //e
        break;
        case 115:                   //s
            if (CMDon == true) {    //CMD+s
                csv.save();
            }
        break;
        case 4353:                  //CMD on
            CMDon = true;
        break;
        case 6:                     // ctrl+f
            ctrlF = true;
        break;
    }
    
    if (ctrlF == true) {
        if (key <= 57 && key >= 48) {   //  0 => key <= 9
            fixturType = key-48;
        }
    }
    
    
    cout << key << endl;
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 4353:
            CMDon = false;  //CMD off
        break;
        case 6:             //ctrl+f
            ctrlF = false;
        break;
            
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    currsor[0] = x;
    currsor[1] = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    currsor[0] = x;
    currsor[1] = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    currsor[0] = x;
    currsor[1] = y;
    if(button == 0) {
        if(inProg == true){
            fixtur_T tmp;
            tmp.first = tmpPoint;
            tmp.second = ofPoint(x,y);
            fixtur.push_back(tmp);
            ofxCsvRow newRow(fixturTypes[fixturType] + "," + ofToString(0) + "," + ofToString(0) +"," + ofToString(tmp.first[0])+ "," +ofToString(tmp.first[1])+ "," +ofToString(tmp.second[0])+ "," +ofToString(tmp.second[1])+ "," + ofToString(10));
            csv.setRow(rowIndex, newRow);
            rowIndex++;
            inProg = false;
        }else{
            tmpPoint = ofPoint(x,y);
            inProg = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    currsor[0] = x;
    currsor[1] = y;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    inside = true;
    currsor[0] = x;
    currsor[1] = y;
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
        inside = false;
    currsor[0] = x;
    currsor[1] = y;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

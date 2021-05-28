#include "ofApp.h"
void ofApp::setup(){
    

    ofBackground(255,255,255);
    ofSetSmoothLighting(true);
    light.setPosition(40, 100, 100);
    ofSetFrameRate(60);
    cam.setDistance(800);
    
    ofSetLineWidth(3);
    
    
    model.loadModel("astroBoy.dae");
    
    angle =0.0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(ofGetMousePressed()){
        
        
        time=time+1;
        
        Xa=Xa+0.2;
    
        if(time>99){
            Xa= Xa-0.2;
        }

    }
    else{
        time=0;
        Xa=0;
    }
    
    angle += 1.0;
    
    camCenter.set(-70-Xa,50+Xa,0-Xa);

    camPosition = camCenter;
    camPosition.z += 260.0;
    camPosition.x += 150.0;
    camPosition.y -= 80.0;
    
    
    camera.setPosition(camPosition);
    camera.lookAt(camCenter);
    
    ofSeedRandom(39);
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(ofColor(255,255,255));
    
    ofEnableDepthTest();
    
    camera.begin();
    light.enable();
    
    ofPushMatrix();
    
    ofTranslate(-160,160,-10);
    //ofRotate(angle,0,1,0);
    ofScale(0.07,0.07,0.07);
    model.setRotation(0,angle,1,1,1);
    model.setPosition(-400+time*0.7,400-time,-400+time);
    
    model.drawFaces();
    
    
    ofPopMatrix();
 
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(-120,120,15);
    
    ofColor color;
    for (int v = 0; v < 360; v += 10) {
 
        vector<glm::vec3> vertices_1;
       
        int u_start = v * 3 + ofGetFrameNum() * 2;
 
        color.setHsb(ofMap(v, 0, 360, 0, 255), 255, 230);
        ofSetColor(color);
 
        ofFill();
        
        if(time>600){
        ofDrawSphere(this->make_point(5, 3+(time-600)/10, (u_start) * DEG_TO_RAD, v * DEG_TO_RAD), ofMap(time-600,0,1000, 0,10));
        ofDrawBox(this->make_point2(5, ofRandom(10), (u_start + 90) * DEG_TO_RAD, v * DEG_TO_RAD), ofMap(time-600,0,1000, 0,10));
        }
    
        ofNoFill();
 
        ofBeginShape();
        ofVertices(vertices_1);
        ofEndShape();
 
    }
    ofPopStyle();
    ofPopMatrix();
    
   
    
    ofPushMatrix();

    ofTranslate(-120,120,15);
    if(time>100){
    for (int i = 0; i < 90; i++) {
        auto x = ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, -20, 20);
        auto y = ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, -20, 30);
        auto z = ofMap(ofNoise(ofRandom(100), ofGetFrameNum() * 0.005), 0, 1, -20, 30);
 
        ofSetColor(0,0,0);
        ofDrawSphere(glm::vec3(x, y, z), ofMap(time-100,0,1000, 0,10));
    }
    }
    
   
    
    
    ofPopMatrix();
    
    
    
    ofPushMatrix();
    
    ofSetColor(ofColor(100,100,100));

    ofDrawPlane(0, 0, 0, 300, 300);
   
    ofRotateX(90);
    ofDrawPlane(0,150, -150, 300, 300);
    
    ofRotateY(90);
    ofDrawPlane(0,150, -150, 300, 300);
    ofPopMatrix();
    
    
    
    ofDrawBitmapString("imaginative power:"+ofToString(time),0,0);
    
    light.disable();
    camera.end();
    
    
    ofDisableDepthTest();
    
    
 
}
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {
    
 
    float x = (R + r * cos(u)) * cos(v);
    float y = (R + r * cos(u)) * sin(v);
    float z = r * sin(u);
 
    return glm::vec3(x, y, z);

}
glm::vec3 ofApp::make_point2(float R, float r, float u, float v) {
    
 
    float x = (R + r * cos(u)) * cos(v)-40;
    float y = (R + r * cos(u)) * sin(v);
    float z = r * sin(u);
 
    return glm::vec3(x+(time-600)/6, y-(time-600)/15, z+(time-600)/10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

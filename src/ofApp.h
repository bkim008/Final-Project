#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

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
    
    ofxAssimpModelLoader model;
    
    float Xa = 0;
    float angle;
    
    int time = 0;
    
        
    ofLight    light;
    ofEasyCam cam;
    
    
    ofCamera camera;
    ofVec3f camCenter;
    ofVec3f camPosition;
    ofVec3f shakeCam;
    
    ofPlanePrimitive plane;
    
    glm::vec3 make_point(float R, float r, float u, float v);
    glm::vec3 make_point2(float R, float r, float u, float v);
};

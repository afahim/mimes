#pragma once

#include "ofMain.h"
#include "ofxPuppetInteractive.h"
#include "ofxDelaunay.h"
#include "ofxXmlSettings.h"
#include "ofxRemoteUIServer.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
#include "ofxOpenCv.h"

#define XML_TAG_POINT_NAME					"meshPoint"
#define XML_TAG_SELECTION_TRIANGLE_NAME		"SelectionTriangleIndex"
#define MESH_XML_FILENAME					"trianglePoints.xml"
#define SELECTION_DISTANCE					13

struct Triangle{
	ofVec2f p0, p1, p2;
	void set(const ofVec2f & p0_, const ofVec2f & p1_, const ofVec2f& p2_){
		p0 = p0_;
		p1 = p1_;
		p2 = p2_;
	}
};

struct TriangleIndexPtrs{
	int * p1; int * p2; int * p3;
};

class ofApp : public ofBaseApp{

public:

	void setup();
	void update();
	void draw();
	void exit();

	void mousePressed( int x, int y, int button );
	void mouseMoved( int x, int y );
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button );
	void keyPressed( int key );

	void clear();


	bool triangleInVector(const vector<ITRIANGLE> &selectedTriangles, ITRIANGLE t );
	ofMesh makeGrid(ofRectangle square, int nHoriz, int nVert);
	void saveMesh( ofxDelaunay & points, vector<ITRIANGLE> & selected);
	void loadMesh(ofxDelaunay & points, vector<ITRIANGLE> & selected);

	void makePuppetFromSelectedTriangleMesh(ofxDelaunay & triangles, vector<ITRIANGLE>selected, ofxPuppetInteractive & pup);

	ofxPuppetInteractive puppet;

	vector<ITRIANGLE>selectedTriangles;

	ofxDelaunay tri;

    ofImage bgImg;
	ofImage legImg;
	ofImage contourImg;
	Triangle tt; //temp triangle to draw mouseOver
	ofVec2f tempVertex;
	int mouseOverVertexIndex; //idex of the vertex that we are mouseOvering on, otherwise -1

	bool draggingVertex;
	bool puppetMode;
	ofVec3f cameraOffset;

	bool drawIDs;
	bool drawMesh;
	bool drawCtrlpoints;
    bool isInit = true;
    
    ofVideoGrabber cam;
	ofxFaceTracker tracker;//, imgTracker;

    int numClicks;
    
    bool createMode = false;
    int clicksRecorded = 0;
    bool contourPtsAdded = false;
    bool addArmsMode = false;
    
    vector<ofPoint> initLeftEye;
    vector<ofPoint> initRightEye;
    vector<ofPoint> initNose;
    vector<ofPoint> initMouth;
    
    vector<ofPoint> diffLeftEye;
    vector<ofPoint> diffRightEye;
    vector<ofPoint> diffNose;
    vector<ofPoint> diffMouth;
    
    vector<ofPoint> puppetTorso;
    vector<ofPoint> puppetLeftArm;
    vector<ofPoint> puppetRightArm;
    vector<ofPoint> puppetPotato;

    int armPtsRecorded = 0;
    vector<int> leftArm;
    vector<int> rightArm;
    
    int count = 0;
    float avgHue = 0;
    float avgBri = 0;
    float avgLight = 0;
    float avgTopColorR = 0;
    float avgTopColorB = 0;
    float avgTopColorG = 0;
    ofColor avgTopColor;
    
    float noseHue = 0;
    float noseBri = 0;
    float noseLight = 0;
    
    ofxCvColorImage	colorImg;
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    
    ofxCvContourFinder contourFinder;
    int clicksThreshold = 24;
    
    int threshold;
};

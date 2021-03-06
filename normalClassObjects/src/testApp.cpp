#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	
	dot.loadImage("dot.png");
	dot.setAnchorPercent(.5,.5);
}

//--------------------------------------------------------------
void testApp::update(){
	
	ofSetWindowTitle( ofToString(ofGetFrameRate() ) );
	
	for( int i = 0; i < particles.size(); i++){
		particles[i].update();
	}
	
	for( int i = particles.size()-1; i >= 0; i--){
		if(particles[i].pos.y > ofGetHeight()+100) 
			particles.erase(particles.begin()+i);
	}
	
	// alternative cleaner method to remove particles
	// ofRemove(particles, shouldRemoveParticle);
	
	ofLogNotice() << "particles " << particles.size();
}

//--------------------------------------------------------------
void testApp::draw(){

	ofBackground(0);
	
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	ofSetColor(255);
	
	for( int i = 0; i < particles.size(); i++){
		//ofEllipse(particles[i].pos.x, particles[i].pos.y, particles[i].size, particles[i].size);
		dot.draw(particles[i].pos.x, particles[i].pos.y, particles[i].size, particles[i].size);		
	}
	
	for( int i = 0; i < particles.size(); i++){
		for( int j = 0; j < i; j++){
			ofPoint diff = particles[i].pos - particles[j].pos;
			float d = diff.length();
			if(d < 100 ){
				float alph = 1-(d/100.f);
				ofSetColor(255,255*alph);
				ofLine(particles[i].pos,particles[j].pos);
			}
		}
	}
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	particles.push_back(Particle());
	particles[ particles.size()-1 ].setup();
	
	//--- alternative, faster method:
//	particles.resize( particles.size()+1);
//	
//	Particle p;
//	p.setup();
//	particles[ particles.size()-1 ] = p;

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
bool testApp::shouldRemoveParticle(Particle &p) {
    if(p.pos.y > ofGetHeight()+100) return true;
	else return false;
}
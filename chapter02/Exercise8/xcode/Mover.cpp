/*
 *  Mover.cpp
 *  Example1
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"

// namespaces
using namespace ci;


Mover::Mover( ) {
	mMass =  1.0f;
    mLocation = Vec2f( randFloat(app::getWindowWidth()), randFloat(app::getWindowHeight()) );
	mVelocity = Vec2f::zero();
    mAcceleration = Vec2f::zero();
}

Mover::Mover(float m, float x, float y) {
    mMass = m;
    mLocation = Vec2f(x, y);
}


void Mover::update( ) {
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    
    mAcceleration *= 0;
}


void Mover::draw( ) {
    gl::enableAlphaBlending();
    gl::color(0.68, 0.68, 0.68, 0.4);
    gl::drawSolidCircle(mLocation, mMass * 16);
    gl::color(0, 0, 0, 0.8);
    gl::drawStrokedCircle(mLocation, mMass * 16);
    gl::disableAlphaBlending();
}

void Mover::applyForce(Vec2f force) {
    Vec2f f = force / mMass;
    mAcceleration += f;
}
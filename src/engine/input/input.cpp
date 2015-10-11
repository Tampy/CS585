// input.cpp

#include "input.h"

Input::Input() {

}

Input::Input( Input& otherInput ) {

}

Input& Input::operator = ( const Input &otherInput ) {

}

Input::~Input() {

}

static Input& Input::inst() {

}

bool Input::isDown( InputType type ) {

}

bool Input::isUp( InputType type ) {

}

bool Input::wasPressed( InputType type ) {

}

void Input::preTick() {

}
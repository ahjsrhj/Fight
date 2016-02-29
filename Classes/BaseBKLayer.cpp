#include "BaseBKLayer.h"



BaseBKLayer::BaseBKLayer() {

}

BaseBKLayer::~BaseBKLayer() {

}

bool BaseBKLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	return true;
}

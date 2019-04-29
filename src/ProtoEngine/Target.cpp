#include "Target.hpp"

namespace Proto {

int Target::getWidth() const { return viewports[0]->getWidth(); }
int Target::getHeight() const { return viewports[0]->getHeight(); };
int Target::getAspectRatio() const { return viewports[0]->getAspect(); };

void Target::setWidth(int new_width) { viewports[0]->setWidth(new_width); }

void Target::setHeight(int new_height) { viewports[0]->setHeight(new_height); }

void Target::setDimension(int new_width, int new_height) {
    viewports[0]->setWidth(new_width);
    viewports[0]->setHeight(new_height);
}

} // namespace Proto

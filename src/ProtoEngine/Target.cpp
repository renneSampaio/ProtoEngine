#include "Target.hpp"

namespace Proto {

Int Target::getWidth() const { return viewports[0]->getWidth(); }
Int Target::getHeight() const { return viewports[0]->getHeight(); };
Float Target::getAspectRatio() const { return viewports[0]->getAspect(); };

void Target::setWidth(Int new_width) { viewports[0]->setWidth(new_width); }

void Target::setHeight(Int new_height) { viewports[0]->setHeight(new_height); }

void Target::setDimension(Int new_width, Int new_height) {
    viewports[0]->setWidth(new_width);
    viewports[0]->setHeight(new_height);
}

} // namespace Proto

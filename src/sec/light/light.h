#ifndef LIGHT_H
#define LIGHT_H

#include <scene/scene.h>
#include "../objects/objects.h"

t_bool computeIllumin(const t_intersection inter,t_light *light);

#endif
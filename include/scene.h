#ifndef _SCENE_H_
#define _SCENE_H_

#include "common.h"
#include "lights/light.h"
#include <vector>


class scene {

public:
    std::vector<std::shared_ptr<Light>> lights;

};

#endif
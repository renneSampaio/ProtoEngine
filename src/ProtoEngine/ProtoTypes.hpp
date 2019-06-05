#ifndef PROTOTYPES_HEADER_
#define PROTOTYPES_HEADER_

#define PROTO_API

#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <algorithm>
#include <cstdlib>
#include <set>
#include <string>
#include <vector>

#include "Component.hpp"
#include "Shader.hpp"

namespace Proto {

using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;

using Mat4 = glm::mat4;

using Float = float;
using Int = int32_t;

using String = std::string;

} // namespace Proto

#endif

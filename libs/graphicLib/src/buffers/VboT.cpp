//
// Created by VerOchka on 22.09.2023.
//

#include "../../headers/GraphicLib/Buffers/Vbo.hpp"
#include "Vbo.cpp"
#include "../../headers/GraphicLib/Buffers/Vertex.hpp"

template
class GraphicLib::Buffers::VBO<GraphicLib::Buffers::Vertex>;

template
class GraphicLib::Buffers::VBO<glm::vec3>;

template
class GraphicLib::Buffers::VBO<glm::vec4>;

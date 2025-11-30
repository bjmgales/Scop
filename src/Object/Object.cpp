#include <Object.hpp>

std::vector<int> Object::getVertex() { return this -> _vertex; };
void Object::setVertex(std::vector<int> v)
{
    this->_vertex = v;
};

std::vector<int> Object::getNormal() { return this -> _normal; };
void Object::setNormal(std::vector<int> vn)
{
    this->_normal = vn;
};

std::vector<int> Object::getTextureCoord() { return this->_textureCoord; };
void Object::setTextureCoord(std::vector<int> vt)
{
    this->_textureCoord = vt;
}

std::vector<int> Object::getFace() { return this->_face; }
void Object::setFace(std::vector<int> f)
{
    this->_face = f;
};
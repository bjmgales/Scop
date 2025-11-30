#include <string>
#include <vector>

class Object
{
    // member
public:
    const std::string name;

private:
    std::vector<int> _vertex;
    std::vector<int> _normal;
    std::vector<int> _textureCoord;
    std::vector<int> _face;

    // Methods
public:
    Object(const std::string &name) : name(name) {}

    std::vector<int> getVertex();
    void setVertex(std::vector<int> v);

    std::vector<int> getNormal();
    void setNormal(std::vector<int> vn);

    std::vector<int> getTextureCoord();
    void setTextureCoord(std::vector<int> vt);
    
    std::vector<int> getFace();
    void setFace(std::vector<int> f);
};
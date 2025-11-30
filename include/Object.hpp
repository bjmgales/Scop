#include <string>
#include <vector>
#include <globalUtils.hpp>

class Object
{
    // member
private:
    const std::vector<std::string> _fileContent;
    std::vector<std::vector<int>> _vertices;
    std::vector<std::vector<int>> _faces;

    // Methods
public:
    Object(const std::vector<std::string> &fileContent) : _fileContent(fileContent)
    {
        for (int i = 0; i < fileContent.size(); i++)
        {
            if (startsWith(fileContent[i], "v"))
                _vertices[i].push_back(getVertices(fileContent[i]));
            else if (startsWith(fileContent[i], "f"))
                _faces[i].push_back(getFaces(fileContent[i]));
        };
    };

    std::vector<std::vector<int>> getVertex();
    void setVertex(std::vector<int> v);

    std::vector<std::vector<int>> getFace();
    void setFace(std::vector<int> f);
};
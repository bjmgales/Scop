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

    static std::vector<int> _retrieveVertex(const std::string &line);
    static std::vector<int> _retrieveFace(const std::string &line);
    // Methods
public:
    Object(const std::vector<std::string> &fileContent) : _fileContent(fileContent)
    {
        for (int i = 0; i < fileContent.size(); i++)
        {
            if (startsWith(fileContent[i], "v"))
                _vertices.push_back(_retrieveVertex(fileContent[i]));
            else if (startsWith(fileContent[i], "f"))
                _faces.push_back(_retrieveFace(fileContent[i]));
        };
    };

    std::vector<std::vector<int>> getVertices();
    void setVertex(std::vector<int> v);

    std::vector<std::vector<int>> getFaces();
    void setFace(std::vector<int> f);
};
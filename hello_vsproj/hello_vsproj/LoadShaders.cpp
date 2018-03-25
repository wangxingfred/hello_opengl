#include <iostream>

#include "LoadShaders.h"

static const GLchar* ReadShader(const char* filename)
{
#ifdef WIN32
    FILE* infile;
    fopen_s(&infile, filename, "rb");
#else
    FILE* infile = fopen(filename, "rb");
#endif // WIN32

    if (!infile) {
#ifdef _DEBUG
        std::cerr << "Unable to open file '" << filename << "'" << std::endl;
#endif /* DEBUG */
        return NULL;
    }

    fseek(infile, 0, SEEK_END);
    int len = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    GLchar* source = new GLchar[len + 1];

    fread(source, 1, len, infile);
    fclose(infile);

    source[len] = 0;

    return const_cast<const GLchar*>(source);
}
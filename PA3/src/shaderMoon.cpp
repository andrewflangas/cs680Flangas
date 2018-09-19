#include "shaderMoon.h"


ShaderMoon::ShaderMoon()
{
  m_ShaderMoonProg = 0;
}


ShaderMoon::~ShaderMoon()
{
  for (std::vector<GLuint>::iterator it = m_ShaderMoonObjList.begin() ; it != m_ShaderMoonObjList.end() ; it++)
  {
    glDeleteShader(*it);
  }

  if (m_ShaderMoonProg != 0)
  {
    glDeleteProgram(m_ShaderMoonProg);
    m_ShaderMoonProg = 0;
  }
}

bool ShaderMoon::Initialize()
{
  m_ShaderMoonProg = glCreateProgram();

  if (m_ShaderMoonProg == 0) 
  {
    std::cerr << "Error creating ShaderMoon program\n";
    return false;
  }

  return true;
}

  std::string ShaderMoon::readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}


// Use this method to add ShaderMoons to the program. When finished - call finalize()
bool ShaderMoon::AddShaderMoon(GLenum ShaderMoonType)
{
  std::string s;
  const char *vFile = "vertex.txt";
  const char *fFile = "fragment.txt";
 

  

    if(ShaderMoonType == GL_VERTEX_SHADER)
  {

        s = readFile(vFile);


  }

  else if(ShaderMoonType == GL_FRAGMENT_SHADER)
  {
    s = readFile(fFile);

    
  }
  


  GLuint ShaderMoonObj = glCreateShader(ShaderMoonType);

  if (ShaderMoonObj == 0) 
  {
    std::cerr << "Error creating ShaderMoon type " << ShaderMoonType << std::endl;
    return false;
  }

  // Save the ShaderMoon object - will be deleted in the destructor
  m_ShaderMoonObjList.push_back(ShaderMoonObj);

  const GLchar* p[1];
  p[0] = s.c_str();
  GLint Lengths[1] = { (GLint)s.size() };

  glShaderSource(ShaderMoonObj, 1, p, Lengths);

  glCompileShader(ShaderMoonObj);

  GLint success;
  glGetShaderiv(ShaderMoonObj, GL_COMPILE_STATUS, &success);

  if (!success) 
  {
    GLchar InfoLog[1024];
    glGetShaderInfoLog(ShaderMoonObj, 1024, NULL, InfoLog);
    std::cerr << "Error compiling: " << InfoLog << std::endl;
    return false;
  }

  glAttachShader(m_ShaderMoonProg, ShaderMoonObj);

  return true;



}


// After all the ShaderMoons have been added to the program call this function
// to link and validate the program.
bool ShaderMoon::Finalize()
{
  GLint Success = 0;
  GLchar ErrorLog[1024] = { 0 };

  glLinkProgram(m_ShaderMoonProg);

  glGetProgramiv(m_ShaderMoonProg, GL_LINK_STATUS, &Success);
  if (Success == 0)
  {
    glGetProgramInfoLog(m_ShaderMoonProg, sizeof(ErrorLog), NULL, ErrorLog);
    std::cerr << "Error linking ShaderMoon program: " << ErrorLog << std::endl;
    return false;
  }

  glValidateProgram(m_ShaderMoonProg);
  glGetProgramiv(m_ShaderMoonProg, GL_VALIDATE_STATUS, &Success);
  if (!Success)
  {
    glGetProgramInfoLog(m_ShaderMoonProg, sizeof(ErrorLog), NULL, ErrorLog);
    std::cerr << "Invalid ShaderMoon program: " << ErrorLog << std::endl;
    return false;
  }

  // Delete the intermediate ShaderMoon objects that have been added to the program
  for (std::vector<GLuint>::iterator it = m_ShaderMoonObjList.begin(); it != m_ShaderMoonObjList.end(); it++)
  {
    glDeleteShader(*it);
  }

  m_ShaderMoonObjList.clear();

  return true;
}


void ShaderMoon::Enable()
{
    glUseProgram(m_ShaderMoonProg);
}


GLint ShaderMoon::GetUniformLocation(const char* pUniformName)
{
    GLuint Location = glGetUniformLocation(m_ShaderMoonProg, pUniformName);

    if (Location == INVALID_UNIFORM_LOCATION) {
        fprintf(stderr, "Warning! Unable to get the location of uniform '%s'\n", pUniformName);
    }

    return Location;
}

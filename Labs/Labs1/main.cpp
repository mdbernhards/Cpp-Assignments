#include <iostream>
#include <string>
#include <cassert>
#include <string_view>

void printArray(std::string array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    std::cout << array[i] << std::endl;
  }
}

int main(int argc, char* argv[])
{
  std::string oneDashArr[argc], twoDashArr[argc], noDashArr[argc];
  int oneDashCount = 0, twoDashCount = 0, noDashCount = 0;

  if (argc > 1)
  {
    for (int i = 0; i < argc; i++)
    {
      if (argv[i][0] == '-')
      {
        if (argv[i][1] == '-')
        {
          twoDashArr[twoDashCount] = argv[i];
          twoDashCount++;
        }
        else 
        {
          oneDashArr[oneDashCount] = argv[i];
          oneDashCount++;
        }
      }
      else if (argv[i][0] != '.')
      {
          noDashArr[noDashCount] = argv[i];
          noDashCount++;
      }
    }

    printArray(oneDashArr, oneDashCount);
    printArray(twoDashArr, twoDashCount);
    printArray(noDashArr, noDashCount);
    
    std::cout << oneDashCount << " " << twoDashCount << " " << noDashCount << std::endl;
  }
  else
  {
    std::cout << "The program name is: " << argv[0] << '\n';
  }
}
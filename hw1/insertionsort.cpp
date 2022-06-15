#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>

using namespace std;

int comparisonCounter = 0;

void insertionSort(std::vector<int>& vec)
{
        for (int i = 1; i < vec.size() ; i++)
        {
                int key = vec[i];
                int j = i - 1;

                comparisonCounter++;
                while (j >= 0 && vec[j] > key)
                {       
                        comparisonCounter++;
                        vec[j + 1] = vec[j];
                        j--;
                }

                vec[j + 1] = key; 
        }

}



void printPokemon(std::vector<int>& vec)
{
        for (int i = 0; i < vec.size(); i++)
                cout << vec[i] << '\n';

        cout << endl;
}


int main(int argc,char* argv[])
{
        
        
    string filename = argv[1];
    std::vector<int> power; 
    //Define the input file stream
    std::ifstream myFile(filename);
    std::string line;
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    int val;
    int count = 0;
    while (std::getline(myFile, line))
    {
        if (count > 0) {
            int pow; 

            //Here...string manipulation
            std::stringstream s_stream(line);
            std::vector<std::string> result;
            while (s_stream.good())
            {
                std::string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            power.push_back(stoi(result[1]));
        }
        count++;
    }


        printPokemon(power);
        insertionSort(power);
        printPokemon(power);
        cout << "\nNumber of comparisons: " << comparisonCounter << "\n";
        return 0;

}
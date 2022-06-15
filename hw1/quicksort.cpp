#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>

using namespace std;

int comparisonCount = 0;

int partition(std::vector<int>& vec, int l , int r)
{
        int i = l - 1;
        int j;
        int pivot = vec[r];
        for (int j = l ; j < r ; j++)
        {
                comparisonCount++;
                if (vec[j] < pivot)
                {
                        i++;
                        swap(vec[i], vec[j]);
                }
        }

        swap(vec[i + 1], vec[r]);
        return i + 1;
}

void quickSort(std::vector<int>& vec, int l, int r)
{
        comparisonCount++;
        if (l < r)
        {
                int pi = partition(vec, l, r);

                quickSort(vec, l, pi - 1);
                quickSort(vec, pi + 1, r);
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
        quickSort(power, 0, count - 2);
        printPokemon(power);

        cout << "\nNumber of comparisons: " << comparisonCount << "\n";

        return 0;
}
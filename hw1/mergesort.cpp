#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>
#include <math.h>

using namespace std;

int comparisonCount = 0;

void merge(std::vector<int>& vec, int p, int q, int r)
{
    int size1 = q-p+1;
    int size2 = r-q;
    std::vector<int> L(size1);
    std::vector<int> R(size2);

    for(int i = 0; i < size1; i++)
    {
        L[i] = vec[p+i];
    }
    for(int j = 0; j < size2; j++)
    {
        R[j]=vec[q+j+1];
    }

    int i=0,j=0;
    int k;
    for(k = p; k <= r && i < size1 && j < size2; k++)
    {
        comparisonCount ++;
        if(L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
    }
    for(i = i; i < size1; ++i)
    {
        vec[k] = L[i];
        k++;
    }

    for(j = j; j < size2; j++)
    {
        vec[k] = R[j];
        k++;
    }
}

void merge_sort(std::vector<int>& vec, int p, int r)
{
    comparisonCount++;
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(vec, p, q);
        merge_sort(vec, q+1, r);
        merge(vec, p, q, r);
    }
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

    int sz = power.size();
    for(int n = 0; n < sz; n++)
    {
        std::cout << power[n] <<"\n";
    }
    std::cout << "\n";
    merge_sort(power, 0, sz-1);
    for(int n = 0; n < sz; n++)
    {
        std::cout << power[n] << "\n";
    }
    std::cout << "\n\n";
    cout << "Number of comparisons: " << comparisonCount << "\n";

}
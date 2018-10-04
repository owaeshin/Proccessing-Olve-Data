#include<ThreeVector.hh>
#include<vector>
#include<string>
#include<ParsingFile.hh>
#include<iostream>
#include<fstream>
#include<sstream>


using namespace std;
void ParsingFile::streamPars(string &currLine, vector<ThreeVector> &vec)
{
    ThreeVector tempvec;
    double tempd;
    char tempc;
    stringstream currLineStream;

    currLineStream<<currLine;
    currLineStream>>tempd;
    tempvec.setN(tempd);

    currLineStream>>tempc;
    currLineStream>>tempd;
    tempvec.setX(tempd);

    currLineStream>>tempc;
    currLineStream>>tempd;
    tempvec.setY(tempd);

    currLineStream>>tempc;
    currLineStream>>tempd;
    tempvec.setZ(tempd);
    vec.push_back(tempvec);
}
void ParsingFile::readPosFile(string fileName, vector<ThreeVector> &posCells, vector<ThreeVector> &posPlates)
{
    ifstream fileData(fileName);
    if (!fileData.is_open())
    {
        cout << "Position file can not be opened, or it does not exist " << endl;
        exit(EXIT_FAILURE);
    }
    string currLine;
    while (getline(fileData, currLine))
    {
        if(currLine[0]=='#')
        {
            break;
        }
        streamPars(currLine,posCells);
    }
    while (getline(fileData, currLine))
    {
        streamPars(currLine,posPlates);
    }
    if (fileData.bad()) {
        throw std::runtime_error ("IO error");
        // IO error
    }
}
void ParsingFile::readSpecFile(string fileName, vector<vector<double>> &specVec)
{
    ifstream fileData(fileName);
    if (!fileData.is_open())
    {
        cout << "Spectrum file can not be opened, or it does not exist " << endl;
        exit(EXIT_FAILURE);
    }
    string currLine;
    while(getline(fileData,currLine))
    {
        if(currLine[0]=='#')
        {

        }
    }

}
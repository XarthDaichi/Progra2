//
// Created by Xarthy on 0020 April 20, 2022.
//

#include "FileManager.h"

FileManager::FileManager() {}

FileManager::~FileManager() {

}

PersonManager FileManager::loadCSV(const std::string &filename) {
    std::string tempNameLast, tempNameFirst, tempStrId, tempEmail, tempNewLine;
    int tempId;

    Person tempPerson;
    std::vector<Person> tempPeople;


    std::ifstream in(filename, std::ios::in | std::ios::binary);

    if(!in.is_open()) {
        throw std::invalid_argument("Could not open file ["+ filename + "]");
    }

    getline(in, tempEmail, '\r'); // ignoring first line with variable names
    getline(in, tempNewLine, '\n');
    while(in.good()) {
        // getting the values
        getline(in, tempEmail,';');
        getline(in, tempStrId, ';');
        getline(in, tempNameFirst, ';');
        getline(in, tempNameLast, '\r');
        getline(in, tempNewLine, '\n');

        // changing anything that is not a string
        tempId = stoi(tempStrId);

        // creating Person
        tempPerson.setFirstName(tempNameFirst);
        tempPerson.setLastName(tempNameLast);
        tempPerson.setId(tempId);
        tempPerson.setEmail(tempEmail);

        // adding Person to list
        tempPeople.push_back(tempPerson);
    }

    // creating PersonManager to return with made list
    PersonManager tempPM(tempPeople);
    return tempPM;
}

PersonManager FileManager::loadDAT(const std::string &filename) {
    PersonManager tempPM;
    std::vector<Person> tempVector;
    Person tempPerson;

    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file [" + filename + "]");
    }

    file.seekg(0);
    while (file.good()) {
        read(file, tempPerson);
        if (tempPerson.getEmail() != "") {
            tempVector.push_back(tempPerson);
        }
    }
    tempPM.setPeople(tempVector);
    return tempPM;
}

void FileManager::saveCSV(const std::string &filename, const PersonManager &PM) {
    std::ofstream out(filename, std::ios::out | std::ios::app | std::ios::binary);

    if(!out.is_open()) {
        throw std::invalid_argument("Could not open file ["+ filename + "]");
    }

    for (Person i : PM.getPeople()) {
        out << i.getEmail() << ";" << i.getId() << ";" << i.getFirstName() << ";" << i.getLastName() << '\r' << '\n';
    }
}

void FileManager::saveDAT(const std::string &filename, const PersonManager &PM) {
    std::ofstream file(filename, std::ios_base::binary);

    for (Person i : PM.getPeople()) {
        write(file, i);
    }

    file.close();
}

std::ostream &FileManager::write(std::ostream &out, const Person &person) {
    int id = person.getId();
    size_t lenFN = person.getFirstName().size();
    size_t lenLN = person.getLastName().size();
    size_t lenE = person.getEmail().size();

    out.write((char*)&lenE, sizeof(lenE));
    out.write(person.getEmail().c_str(), lenE);
    out.write((char*)(&id), sizeof(person.getId()));
    out.write((char*)&lenFN, sizeof(lenFN));
    out.write(person.getFirstName().c_str(), lenFN);
    out.write((char*)&lenLN, sizeof(lenLN));
    out.write(person.getLastName().c_str(), lenLN);

    return out;
}

std::istream &FileManager::read(std::istream &in, Person &person) {
    size_t lenE = 0;
    size_t lenFN = 0;
    size_t lenLN = 0;
    in.read((char*)&lenE, sizeof(lenE));

    int id = 0;

    char* email = new char[lenE + 1];
    in.read(email, lenE);
    email[lenE] = '\0';
    person.setEmail(email);
    delete[] email;

    in.read((char*)&id, sizeof(int));
    person.setId(id);

    in.read((char*)&lenFN, sizeof(lenFN));
    char* firstName = new char[lenFN + 1];
    in.read(firstName, lenFN);
    firstName[lenFN] = '\0';
    person.setFirstName(firstName);
    delete[] firstName;

    in.read((char*)&lenLN, sizeof(lenLN));
    char* lastName = new char[lenLN + 1];
    in.read(lastName, lenLN);
    lastName[lenLN] = '\0';
    person.setLastName(lastName);
    delete[] lastName;

    return in;
}

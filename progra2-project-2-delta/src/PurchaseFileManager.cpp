//
// Created by Xarthy on 0020 June 20, 2022.
//

#include "PurchaseFileManager.h"

PurchaseFileManager::PurchaseFileManager(const char c) : inputType(c) {
    purchases = new Container<Purchase>;
    clog << "Constructing PurchaseFileManager" << endl;

    Purchase* pur = new Purchase();
//    Set *set = new Set();
//    Suit *suit = new Suit();
//    Garment *garment = new Garment();
    string code, type, color, size, price, amount, characteristic;
    vector<Clothing*> hasSet, hasSuit;
    string fileName = "../../db_purchase.";
    ifstream myReadFile;

    if (inputType == 'b') fileName += "dat";
    else fileName += "csv";

    myReadFile.open(fileName, ios::in | ios::binary);

    if (!myReadFile.is_open()) throw invalid_argument("Could not open the file [" + fileName + "]");

    if (inputType == 'b') myReadFile.seekg(0);
    else getline(myReadFile, type, '\n');

    while(myReadFile.good()) {
        if (inputType == 'b') myReadFile.read((char*)&*pur, sizeof(*pur));
        if (!code.empty() || inputType == 'b') purchases->push(new Purchase(*pur));
        hasSet.clear();
    }
    if (inputType == 'b') purchases->pop();
    myReadFile.close();
    clog << "Finished Constructing PurchaseFileManager" << endl;
}

PurchaseFileManager::~PurchaseFileManager() {
    clog << "Deconstructing PurchaseFileManager" << endl;

    string fileNameCSV = "../../db_purchase.csv", fileNameDAT = "../../db_purchase.dat";
    ofstream myWriteFileCSV, myWriteFileDAT;

//    myWriteFileCSV.open(fileNameCSV, ios::trunc | ios::out | ios::binary);

//    if (!myWriteFileCSV.is_open()) throw invalid_argument("Could not open file [" + fileNameCSV + "]");
//
//    myWriteFileCSV << "code;price;amountBought;itemsBought\n";
//
//    for (auto * i: purchases->allObjects()) {
//        myWriteFileCSV << "set:" << i->getCode() << ';' << i->getPrice() << ';' << i->hasClothes().size() << ';';
//        for (auto * j : i->hasClothes()) {
//            Suit* jSuit = dynamic_cast<Suit*> (&*j);
//            if (jSuit) {
//                myWriteFileCSV <<"suit:" << jSuit->getCode() << ';' << jSuit->getPrice() << ";" << jSuit->getType() << ';';
//                for (auto * k : j->hasClothes()) {
//                    Garment * kGarment = dynamic_cast<Garment*> (&*k);
//                    if (kGarment) {
//                        myWriteFileCSV << "garment:" << kGarment->getCode() << ';' << kGarment->getPrice() << ';' << kGarment->getType() << ';' << kGarment->getSize() << ';' << kGarment->getColor() << ';';
//                        if (kGarment->isCharacteristic()) myWriteFileCSV << "TRUE;";
//                        else myWriteFileCSV << "FALSE;";
//                    }
//                    else throw invalid_argument("Invalid type of Clothing (not Garment, cannot access necessary info)");
//                }
//            } else {
//                Garment* jGarment = dynamic_cast<Garment*> (&*j);
//                if (jGarment) {
//                    myWriteFileCSV << "garment:" << jGarment->getCode() << ';' << jGarment->getPrice() << ';' << jGarment->getType() << ';' << jGarment->getSize() << ';' << jGarment->getColor() << ';';
//                    if (jGarment->isCharacteristic()) myWriteFileCSV << "TRUE;";
//                    else myWriteFileCSV << "FALSE;";
//                }
//                else throw invalid_argument("Invalid type of Clothing (not Garment, cannot access necessary info)");
//            }
//        }
//    }
//
//    myWriteFileCSV.close();

    myWriteFileDAT.open(fileNameDAT, ios::trunc | ios::out | ios::binary);

    if (!myWriteFileDAT.is_open()) throw invalid_argument("Could not open file [" + fileNameDAT + "]");

    for (auto * i : purchases->allObjects()) myWriteFileDAT.write((char*)&*i, sizeof(*i));

    myWriteFileDAT.close();

    clog << "Finished Deconstructing PruchaseFileManager" << endl;
}

Container<Purchase> *PurchaseFileManager::getPurchases() {
    return purchases;
}

//void to_json(json &_json, const Purchase &_purchase) {
//    _json = json{
//            {"id",   _person.getId()},
//            {"name", _person.getName()},
//    };
//}
//
//void from_json(const nlohmann::json &_json, Purchase &_purchase) {
//    _person.setId(_json.at("id").get<int>());
//    _person.setName(_json.at("name").get<std::string>());
//}

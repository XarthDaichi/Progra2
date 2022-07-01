//
// Created by ribre on 16/06/2022.
//

#include "PricingManager.h"

PricingManager::PricingManager() = default;

PricingManager::~PricingManager() = default;

double PricingManager::getShippingCost(int code) {
        double shipping;
        switch (code) {
            case 1 :
                shipping = 100;
                break;
            case 2 :
                shipping = 200;
                break;
            case 3 :
                shipping = 250;
                break;
            case 4 :
                shipping = 150;
                break;
            case 5 :
                shipping = 175;
                break;
            case 6 :
                shipping = 160;
                break;
            case 7 :
                shipping = 200;
                break;
            case 8 :
                shipping = 150;
                break;
            case 9 :
                shipping = 50;
                break;
            default:
                cout<<" Imposible encontrar el codigo de pais, intente de nuevo! "<<endl;
                return 0;
        }
        return shipping;
    }

string PricingManager::getCity(int code) {
    string city;
    switch (code) {
        case 1 :
            city = "New York";
            break;
        case 2 :
            city = "Paris";
            break;
        case 3 :
            city = "Milan";
            break;
        case 4 :
            city = "Brasilia";
            break;
        case 5 :
            city = "Buenos Aires";
            break;
        case 6 :
            city = "Ontario";
            break;
        case 7 :
            city = "Londres";
            break;
        case 8 :
            city = "California";
            break;
        case 9 :
            city = "Ciudad Costarricense";
            break;
        default:
            cout<<" Imposible encontrar el codigo de pais, intente de nuevo! "<<endl;
            return "";
    }
    return city;
}

string PricingManager::getCountry(int code) {
    string country;
    switch (code) {
        case 1 :
            country = "Estados Unidos";
            break;
        case 2 :
            country = "Francia";
            break;
        case 3 :
            country = "Italia";
            break;
        case 4 :
            country = "Brasil";
            break;
        case 5 :
            country = "Argentina";
            break;
        case 6 :
            country = "Canada";
            break;
        case 7 :
            country = "Inglaterra";
            break;
        case 8 :
            country = "Estados Unidos";
            break;
        case 9 :
            country = "Costa Rica";
            break;
        default:
            cout<<" Imposible encontrar el codigo de pais, intente de nuevo! "<<endl;
            return "";
    }
    return country;
}

double PricingManager::itemPrice(string type, bool characteristic, string size) {
    if (type == "Shirt:LongSleeve") {
        if (size == "Large") {
            if (characteristic) return 375.0;
            else return 325.0;
        } else if (size == "Medium") {
            if (characteristic) return 315.0;
            else return 280.0;
        } else if (size == "Small") {
            if (characteristic) return 175.0;
            else return 150.0;
        } else if (size == "Child") {
            if (characteristic) return 165.0;
            else return 125.0;
        }
    } else if (type == "Shirt:T-shirt") {
        if (size == "Large") {
            if (characteristic) return 200.0;
            else return 150.0;
        } else if (size == "Medium") {
            if (characteristic) return 150.0;
            else return 100.0;
        } else if (size == "Small") {
            if (characteristic) return 125.0;
            else return 75.0;
        } else if (size == "Child") {
            if (characteristic) return 75.0;
            else return 50.0;
        }
    } else if (type == "Shirt:WithSquares") {
        if (size == "Large") {
            if (characteristic) return 300.0;
            else return 250.0;
        } else if (size == "Medium") {
            if (characteristic) return 250.0;
            else return 200.0;
        } else if (size == "Small") {
            if (characteristic) return 175.0;
            else return 150.0;
        } else if (size == "Child") {
            if (characteristic) return 150.0;
            else return 100.0;
        }
    } else if (type == "Pant:DressUp") {
        if (size == "Large") {
            if (characteristic) return 500.0;
            else return 300.0;
        } else if (size == "Medium") {
            if (characteristic) return 450.0;
            else return 250.0;
        } else if (size == "Small") {
            if (characteristic) return 260.0;
            else return 125.0;
        } else if (size == "Child") {
            if (characteristic) return 200.0;
            else return 100.0;
        }
    } else if (type == "Pant:Shorts") {
        if (size == "Large") {
            if (characteristic) return 150.0;
            else return 110.0;
        } else if (size == "Medium") {
            if (characteristic) return 130.0;
            else return 85.0;
        } else if (size == "Small") {
            if (characteristic) return 80.0;
            else return 50.0;
        } else if (size == "Child") {
            if (characteristic) return 75.0;
            else return 45.0;
        }
    } else if (type == "Pant:Jeans") {
        if (size == "Large") {
            if (characteristic) return 200.0;
            else return 150.0;
        } else if (size == "Medium") {
            if (characteristic) return 150.0;
            else return 100.0;
        } else if (size == "Small") {
            if (characteristic) return 75.0;
            else return 50.0;
        } else if (size == "Child") {
            if (characteristic) return 90.0;
            else return 25.0;
        }
    } else if (type == "Shoe:Executive") {
        if (size == "Large") {
            if (characteristic) return 450.0;
            else return 400.0;
        } else if (size == "Medium") {
            if (characteristic) return 400.0;
            else return 350.0;
        } else if (size == "Small") {
            if (characteristic) return 325.0;
            else return 250.0;
        } else if (size == "Child") {
            if (characteristic) return 200.0;
            else return 175.0;
        }
    } else if (type == "Shoe:Tennis") {
        if (size == "Large") {
            if (characteristic) return 335.0;
            else return 225.0;
        } else if (size == "Medium") {
            if (characteristic) return 300.0;
            else return 200.0;
        } else if (size == "Small") {
            if (characteristic) return 200.0;
            else return 150.0;
        } else if (size == "Child") {
            if (characteristic) return 150.0;
            else return 75.0;
        }
    } else if (type == "Shoe:Boots") {
        if (size == "Large") {
            if (characteristic) return 250.0;
            else return 220.0;
        } else if (size == "Medium") {
            if (characteristic) return 225.0;
            else return 200.0;
        } else if (size == "Small") {
            if (characteristic) return 175.0;
            else return 150.0;
        } else if (size == "Child") {
            if (characteristic) return 90.0;
            else return 75.0;
        }
    }
    return 0;
}

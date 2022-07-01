//
// Created by Xarthy on 0020 June 20, 2022.
//
#include "gtest/gtest.h"
#include "../src/Client.h"
#include"../src/Company.h"
#include"../src/Container.h"
#include "../src/StockData.h"

TEST(ClientTestSuite, TestClientData){
//Testing data is being saved in physical clients
    Client realCliente1("JosePresencial","13242362", 9, false, "Jose@temp.com");
    realCliente1.setEmail("joseTrajes@gmail.com");
    realCliente1.setOnline(false);
//Testing data is being saved in physical companies
    Company  realEmpresa1("ModaAdecuada", "201010010", 2, false, true);
    realEmpresa1.setStartup(true);
    realEmpresa1.setOnline(false);
    EXPECT_STREQ(realCliente1.toString().c_str()," name: JosePresencial id: 13242362 email: joseTrajes@gmail.com");
    EXPECT_STREQ(realEmpresa1.toString().c_str()," name: ModaAdecuada id: 201010010 startup: 1");

//Testing data is being saved in virtual clients
    Client virtualCliente1("JoseVirtual","461234237", 1, true, "Jose@temp.com");
    virtualCliente1.setEmail("TrajesBonitos@gmail.com");
    virtualCliente1.setOnline(true);
    virtualCliente1.setCountryCode(6);
//Testing data is being saved in virtual companies
    Company  virtualEmpresa1("ModaModerna", "532523423", 3, true, true);
    virtualEmpresa1.setStartup(true);
    virtualEmpresa1.setOnline(true);
    virtualEmpresa1.setCountryCode(2);
    EXPECT_STREQ(virtualCliente1.toString().c_str()," name: JoseVirtual id: 461234237 "
                                                    "email: TrajesBonitos@gmail.com "
                                                    "Coste de envio: 160 dolares, "
                                                    "Ciudad: Ontario "
                                                    "Pais: Canada "
                                                    "Coste de suscripcion: 200");
    EXPECT_STREQ(virtualEmpresa1.toString().c_str()," name: ModaModerna "
                                                    "id: 532523423 startup: 1 "
                                                    "Coste de envio: 200 dolares, "
                                                    "Ciudad: Paris "
                                                    "Pais: Francia "
                                                    "Coste de sustripcion: 400");
    //Having different info from being virtual or physical
}

TEST(ClientTestSuite, TestSavingClients) {

    Client c1("Carlos", "243152161", 6, false, "Carlo@temp.com");
    c1.setEmail("CarlosCompras@gmail.com");
    c1.setOnline(false);
    c1.setCountryCode(6);

    Client c2("Ana", "572451267", 8, true, "Ana@temp.com");
    c2.setOnline(true);
    c2.setCountryCode(8);
    c2.setEmail("AnaEstudiante@gmail.com");

    Client c3("Carlos", "243152161", 9, false, "carlos2@temp.com");
    c3.setEmail("CarlosCompras@gmail.com");
    c3.setOnline(false);
    c3.setCountryCode(9);

    StockData stockTienda;

    EXPECT_TRUE(stockTienda.registerObserver(&c1));
    EXPECT_TRUE(stockTienda.registerObserver(&c2));
    EXPECT_FALSE(stockTienda.registerObserver(&c3));

//Registering observers for shopping and being updated when new Stock comes in
}
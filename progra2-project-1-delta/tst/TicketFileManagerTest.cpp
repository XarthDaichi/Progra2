//
// Created by Xarthy on 0014 May 14, 2022.
//
#include "gtest/gtest.h"
#include "../src/TicketFileManager.h"

TEST(TicketFileManagerTestSuite, FileGenerator) {
    // creating ticket fileF
    ofstream out;
    string fileName = "../../db_ticket.csv";
    out.open(fileName, ios::trunc | ios::out);

    out << "passengerId;origin;destination;lenVehicles;vehicles(type;licencePlate);bus;seats;seatNumbers\n";
    out << "1;Volcán Arenal;San Carlos;2;Buseta;BUS001;Buseta;BUS002;BUS001;2;1 2\n";
    out << "2;Volcán Arenal;San Carlos;2;Buseta;BUS001;Buseta;BUS002;BUS002;3;1 2 3\n";
    out << "3;Río Celeste;San Carlos;2;Buseta;BUS003;Coaster;COA001;BUS003;4;1 2 3 4\n";
    out << "4;Tamarindo;Guanacaste;2;Coaster;COA002;Hiace;HIA001;COA002;5;1 2 3 4 5\n";
    out << "5;Puerto Viejo;Limón;2;Hiace;HIA002;Hiace;HIA003;HIA002;6;1 2 3 4 5 6\n";
    out << "6;Cóbano;Puntarenas;2;Hiace;HIA004;H1;HON001;HIA004;7;1 2 3 4 5 6 7\n";
    out << "7;Volcán Irazú;Cartago;1;H1;HON002;HON002;6;1 2 3 4 5 6\n";

    out.close();
}

TEST(TicketFileManagerTestSuite, TicketFileManager) {
    vector<Ticket *> goldenTickets = TicketFileManager::getInstance('c').getTickets()->allObjects();

    EXPECT_TRUE(goldenTickets.size() == 7);
}
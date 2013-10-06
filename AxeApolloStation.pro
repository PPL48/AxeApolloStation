#-------------------------------------------------
#
# Project created by QtCreator 2013-09-24T20:00:22
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AxeApolloStation
TEMPLATE = app

SOURCES +=\
    Includes/pesawat.cpp \
    Includes/penumpang.cpp \
    Includes/penerbangan.cpp \
    Includes/pemesan.cpp \
    Includes/pegawai.cpp \
    Includes/bandara.cpp \
    Includes/bagasi.cpp \
    Models/pesawatmodel.cpp \
    Models/penumpangmodel.cpp \
    Models/penerbanganmodel.cpp \
    Models/pemesanmodel.cpp \
    Models/pegawaimodel.cpp \
    Models/bandaramodel.cpp \
    Models/bagasimodel.cpp \
    viewfactory.cpp \
    main.cpp \
    Controllers/ParkingController.cpp \
    Controllers/FlightController.cpp \
    Controllers/CheckInController.cpp \
    Controllers/LoginController.cpp \
    Views/dlgchooseaviator.cpp \
    Views/dlgchoosecrew.cpp \
    Models/dbconfig.cpp \
    dbfactory.cpp \
    Models/pemesananmodel.cpp \
    Includes/pemesanan.cpp

HEADERS  += \
    Includes/pesawat.h \
    Includes/penumpang.h \
    Includes/penerbangan.h \
    Includes/pemesan.h \
    Includes/pegawai.h \
    Includes/bandara.h \
    Includes/bagasi.h \
    Models/pesawatmodel.h \
    Models/penumpangmodel.h \
    Models/penerbanganmodel.h \
    Models/pemesanmodel.h \
    Models/pegawaimodel.h \
    Models/bandaramodel.h \
    Models/bagasimodel.h \
    viewfactory.h \
    Controllers/CheckInController.h \
    Controllers/FlightController.h \
    Controllers/ParkingController.h \
    Controllers/LoginController.h \
    Views/dlgchooseaviator.h \
    Views/dlgchoosecrew.h \
    Models/dbconfig.h \
    dbfactory.h \
    Models/pemesananmodel.h \
    Includes/pemesanan.h

FORMS    += \
    Views/parkingcontroller.ui \
    Views/checkincontroller.ui \
    Views/flightcontroller.ui \
    Views/logincontroller.ui \
    Views/dlgchooseaviator.ui \
    Views/dlgchoosecrew.ui

RESOURCES += \
    Resources/systems.qrc
